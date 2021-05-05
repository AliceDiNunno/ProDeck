#include "ProDeck.h"
#include "Core/Logging/Logging.h"

#include <QDebug>
#include "OS/ProDeckOS.h"

ProDeck::ProDeck()
{
    Logging::log("Starting Prodeck...");

    _runningDevices = new QMap<StreamDeckDevice *, ProDeckOS*>();

    _pDiscovery = new StreamDeckDiscovery(StreamDeckAvailableDevice::XL);

    connect(_pDiscovery, SIGNAL(deviceListUpdated(QList<StreamDeckDevice *>)), this, SLOT(discoveryUpdated(QList<StreamDeckDevice *>)));

    _pDiscovery->start();
}

void ProDeck::discoveryUpdated(QList<StreamDeckDevice *> deviceList) {
    auto remainingDevices = deviceList;
    for(int i = 0; i < deviceList.count(); i++) {
        auto device = deviceList.at(i);
        remainingDevices.removeOne(device);

        bool deviceFound = false;

        for (int j = 0; j < _runningDevices->keys().count(); j++) {
            auto currentKey = _runningDevices->keys().at(j);
            if  (currentKey->serialNumber() == device->serialNumber()) {
                deviceFound = true;
            }
        }

        if (!deviceFound) {
            auto os = this->startDevice(device);
            if (os != nullptr) {
               _runningDevices->insert(device, os);
            }
        }
    }

    for (int i = 0; i < remainingDevices.count(); i++) {
        auto device = remainingDevices.at(i);

        stopDevice(device);
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
    Logging::log(QString("Closed Device: %1").arg(dev->serialNumber()));
    dev->Close();
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
