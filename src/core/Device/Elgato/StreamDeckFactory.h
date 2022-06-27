#ifndef STREAMDECKFACTORY_H
#define STREAMDECKFACTORY_H

#include "StreamDeckDeviceInformation.h"
#include "StreamDeckSupportedDevice.h"

class StreamDeckFactory
{
public:
    static StreamDeckDeviceInformation *buildDevice(StreamDeckSupportedDevice device);
};

#endif // STREAMDECKFACTORY_H
