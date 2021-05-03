#include "StreamDeckDiscovery.h"

#include "Core/Logging/Logging.h"
#include "Core/Device/StreamDeckFactory.h"
#include "Core/Hid/HidDiscovery.h"

StreamDeckDiscovery::StreamDeckDiscovery(StreamDeckAvailableDevice device): _device(StreamDeckFactory::buildDevice(device))
{
    _pRefreshTimer = new QTimer();
    connect(_pRefreshTimer, SIGNAL(timeout()), this, SLOT(refresh()));
}

void StreamDeckDiscovery::start() {
    Logging::log("Starting discovery for: " + _device.deviceName);
    _pRefreshTimer->start(1000);
}

void StreamDeckDiscovery::stop() {
    Logging::log("Stopping discovery for: " + _device.deviceName);
    _pRefreshTimer->stop();
}

void StreamDeckDiscovery::refresh() {
    auto items = HidDiscovery::startDiscovery(_device.productId, _device.vendorId);

    auto updatedItems = QList<StreamDeckDevice>();

    for (int iItem = 0; iItem < items.count(); iItem++) {
        auto currentDevice = items[iItem];

        updatedItems.append(StreamDeckDevice(_device, currentDevice.serialNumber));
    }

    emit deviceListUpdated(updatedItems);
}
