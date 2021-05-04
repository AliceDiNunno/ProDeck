#include "ProDeckOS.h"
#include "Core/Logging/Logging.h"
#include <unistd.h>

ProDeckOS::ProDeckOS(StreamDeckDevice device): _device(device)
{
    log("Starting ProDeckOS");
    ClearScreen();
    SetBrightness(25);

    QPixmap pix("/Users/alice/Downloads/output-onlinepngtools.jpg");
    for (int i = 0; i < 32; i++) {
        _device.Draw(i, pix);
    }

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
