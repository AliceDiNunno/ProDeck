#include "ProDeck.h"
#include <QDebug>

#include "src/Core/Logging/Logging.h"
#include "src/OS/ProDeckOS.h"

ProDeck::ProDeck()
{
    Logging::log("Starting Prodeck...");

    _runningDevices = new QMap<StreamDeckDevice *, ProDeckOS*>();

    _pDiscovery = new StreamDeckDiscovery(StreamDeckAvailableDevice::XL);

    connect(_pDiscovery, SIGNAL(deviceListUpdated(QList<StreamDeckDevice *>)), this, SLOT(discoveryUpdated(QList<StreamDeckDevice *>)));

    _pDiscovery->start();


    _pRazerDiscovery = new RazerDiscovery(RazerAvailableDevice::XL2);
    _pRazerDiscovery->start();
}

void ProDeck::discoveryUpdated(QList<StreamDeckDevice *> deviceList) {
    for (int i = 0; i < deviceList.count(); i++) {
        bool alreadyRunning = false;

        for (int j = 0; j < _runningDevices->count(); j++) {
            if (deviceList.at(i)->serialNumber() == _runningDevices->keys().at(j)->serialNumber()) {
                alreadyRunning = true;
                break;
            }
        }

        if (!alreadyRunning) {
            _runningDevices->insert(deviceList.at(i), startDevice(deviceList.at(i)));
        }
    }

    QList<StreamDeckDevice *> stoppedDevices;
    for (int i = 0; i < _runningDevices->count(); i++) {
        bool stoppedRunning = true;

        for (int j = 0; j < deviceList.count(); j++) {
            if (deviceList.at(j)->serialNumber() == _runningDevices->keys().at(i)->serialNumber()) {
                stoppedRunning = false;
            }
        }

        if (stoppedRunning) {
            stoppedDevices.append(_runningDevices->keys().at(i));
        }
    }

    for (int i = 0; i < stoppedDevices.count(); i++) {
        stopDevice(stoppedDevices.at(i));
    }
}

ProDeckOS *ProDeck::startDevice(StreamDeckDevice *dev) {
    if (dev->Open()) {
        Logging::log(QString("Opened Device: %1").arg(dev->serialNumber()));
        auto os = new ProDeckOS(dev);
        return os;
    } else {
        //TODO: handle error
        qDebug() << "Unable to open";
    }
    return nullptr;
}

void ProDeck::stopDevice(StreamDeckDevice *dev) {
    stopOS(_runningDevices->value(dev));

    Logging::log(QString("Closed Device: %1").arg(dev->serialNumber()));
    dev->deleteLater();

   _runningDevices->remove(dev);
}

void ProDeck::stopOS(ProDeckOS *os) {
    os->deleteLater();
}

ProDeck::~ProDeck() {
    Logging::log("Stopping Prodeck...");
    _pDiscovery->stop();  
    _pDiscovery->deleteLater();

    for (int i = 0; i < _runningDevices->keys().count(); i++) {
        auto device = _runningDevices->keys().at(i);
        stopDevice(device);
    }
}
