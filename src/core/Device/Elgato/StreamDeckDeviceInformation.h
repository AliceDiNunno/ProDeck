#ifndef STREAMDECKDEVICEINFORMATION_H
#define STREAMDECKDEVICEINFORMATION_H

#include <QString>
#include "../HidDevice.hpp"
#include "../MacroDevice.hpp"
#include "HidDescriptor.h"

class StreamDeckDeviceInformation: public HidDevice, public MacroDevice {
public:
    StreamDeckDeviceInformation();
};

#endif // STREAMDECKDEVICE_H
