#include "StreamDeckFactory.h"

//devices
#include "src/core/device/elgato/metadata/StreamDeckXLDevice.h"

StreamDeckDeviceInformation *StreamDeckFactory::buildDevice(StreamDeckSupportedDevice device) {
    switch (device) {
        case XL:
            return new StreamDeckXLDevice();
    }
}
