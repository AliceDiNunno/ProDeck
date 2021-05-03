#include "StreamDeckFactory.h"

//devices
#include "StreamDeckXLDevice.h"

StreamDeckDeviceInformation StreamDeckFactory::buildDevice(StreamDeckAvailableDevice device) {
    switch (device) {
        case XL:
            return StreamDeckXLDevice();
        break;
    }
}
