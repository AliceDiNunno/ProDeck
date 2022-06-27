#ifndef RAZERFACTORY_H
#define RAZERFACTORY_H

#include "RazerSupportedDevice.h"
#include "RazerDeviceInformation.h"

class RazerFactory
{
public:
    static RazerDeviceInformation *buildDevice(RazerSupportedDevice device);
};

#endif // RAZERFACTORY_H
