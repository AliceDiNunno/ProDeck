#include "ProDeckOS.h"
#include "Core/Logging/Logging.h"

ProDeckOS::ProDeckOS(StreamDeckDevice device): _device(device)
{
    log("Starting ProDeckOS");
    ClearScreen();
    SetBrightness(25);
}

void ProDeckOS::ClearScreen() {
    log("Clearing screen");
    _device.Clear();
}

void ProDeckOS::SetBrightness(short brightness) {
    log(QString("Setting brightness to %1%").arg(brightness));
}

void ProDeckOS::log(QString info) {
    Logging::log(QString("[%1] %2").arg(_device.serialNumber()).arg(info));
}
