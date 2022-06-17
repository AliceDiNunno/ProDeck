#include "RazerFactory.h"

#include "RazerBlackWidowV3Device.h"

RazerDeviceInformation RazerFactory::buildDevice(RazerAvailableDevice device) {
    switch (device) {
        case XL2:
            return RazerBlackWidowV3Device();
        break;
    }
}
