#ifndef RAZERFACTORY_H
#define RAZERFACTORY_H

#include "RazerAvailableDevice.h"
#include "RazerDeviceInformation.h"

class RazerFactory
{
public:
    static RazerDeviceInformation buildDevice(RazerAvailableDevice device);
};

#endif // RAZERFACTORY_H
