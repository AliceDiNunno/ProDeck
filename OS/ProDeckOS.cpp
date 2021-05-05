#include <QTimer>

#include "SplashScreen.h"
#include "ProDeckOS.h"
#include "Core/Logging/Logging.h"
#include <unistd.h>

ProDeckOS::ProDeckOS(StreamDeckDevice *device): _device(device)
{
    log("Starting ProDeckOS");
    ClearScreen();
    SetBrightness(25);

    _pCurrentView = new SplashScreen();

    connect(_pCurrentView, SIGNAL(refreshKey(int, QPixmap)), this, SLOT(refreshKey(int, QPixmap)));

    _pUpdateFrameTimer = new QTimer(this);
    connect(_pUpdateFrameTimer, SIGNAL(timeout()), this, SLOT(updateFrames()));
    _pUpdateFrameTimer->setSingleShot(false);
    _pUpdateFrameTimer->start(100);

}


void ProDeckOS::updateFrames() {
    _pCurrentView->refresh();
}

void ProDeckOS::refreshKey(int index, QPixmap key) {
    _device->Draw(index, key);
}

void ProDeckOS::ClearScreen() {
    log("Clearing screen");
    _device->Clear();
}

void ProDeckOS::SetBrightness(short brightness) {
    log(QString("Setting brightness to %1%").arg(brightness));
}

void ProDeckOS::log(QString info) {
    Logging::log(QString("[%1] %2").arg(_device->serialNumber()).arg(info));
}

ProDeckOS::~ProDeckOS() {
    log("Stopping ProDeckOS");
    _pUpdateFrameTimer->stop();
}

