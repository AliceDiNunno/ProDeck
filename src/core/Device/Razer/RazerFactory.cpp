#include "RazerFactory.h"

//devices
#include "metadata/RazerBlackWidowV3Device.h"
#include "metadata/RazerBasiliskV3Device.h"

RazerDeviceInformation *RazerFactory::buildDevice(RazerSupportedDevice device) {
    switch (device) {
        case BlackWidowV3:
            return new RazerBlackWidowV3Device();
        case BasiliskV3:
            return new RazerBasiliskV3Device();
    }
}
