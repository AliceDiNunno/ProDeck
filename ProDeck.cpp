#include "ProDeck.h"
#include "Core/Logging/Logging.h"

#include <QDebug>

ProDeck::ProDeck()
{
    Logging::log("Starting Prodeck...");

    _pDiscovery = new StreamDeckDiscovery(StreamDeckAvailableDevice::XL);

    connect(_pDiscovery, SIGNAL(deviceListUpdated(QList<StreamDeckDevice>)), this, SLOT(discoveryUpdated(QList<StreamDeckDevice>)));

    _pDiscovery->start();
}

void ProDeck::discoveryUpdated(QList<StreamDeckDevice> deviceList) {
    auto remainingDevices = deviceList;
    for(int i = 0; i < deviceList.count(); i++) {
        auto device = deviceList.at(i);
        remainingDevices.removeOne(device);

        if (!_runningDevices.contains(device)) {
            this->startDevice(device);
            _runningDevices.append(device);
        }


    }

    for (int i = 0; i < remainingDevices.count(); i++) {
        auto device = remainingDevices.at(i);

        stopDevice(device);
    }
}

void ProDeck::startDevice(StreamDeckDevice dev) {
    if (dev.Open()) {
        qDebug() << "Opened";
    } else {
        qDebug() << "Unable to open";
    }
}

void ProDeck::stopDevice(StreamDeckDevice dev) {
    qDebug() << "closed";
    dev.Close();
}

ProDeck::~ProDeck() {
    Logging::log("Stopping Prodeck...");
    _pDiscovery->stop();  
    _pDiscovery->deleteLater();

    for (int i = 0; i < _runningDevices.count(); i++) {
        auto device = _runningDevices.at(i);

        stopDevice(device);
    }
}
