#ifndef STREAMDECKFACTORY_H
#define STREAMDECKFACTORY_H

#include "StreamDeckDeviceInformation.h"
#include "StreamDeckAvailableDevice.h"

class StreamDeckFactory
{
public:
    static StreamDeckDeviceInformation buildDevice(StreamDeckAvailableDevice device);
};

#endif // STREAMDECKFACTORY_H
