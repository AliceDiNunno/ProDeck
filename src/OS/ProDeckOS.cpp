#include <QTimer>

#include "SplashScreen.h"
#include "ProDeckOS.h"
#include "src/core/logging/Logging.h"
#include "DeviceDiscovery.hpp"
#include "MainView.h"
#include <unistd.h>

ProDeckOS::ProDeckOS()
{
    _pStreamDeck = nullptr;
    log("Starting ProDeckOS");
}

void ProDeckOS::endSplash() {
   log("Closing Splash Screen");
   _pSplashScreenTimer->stop();
   SplashScreen *pSplash = dynamic_cast<SplashScreen *>(_pCurrentView);

   if (pSplash != nullptr) {
        pSplash->endSplashScreen();

        pSplash->deleteLater();
        pSplash = nullptr;
   }

   _pSplashScreenTimer->deleteLater();
   _pSplashScreenTimer = nullptr;

   _pCurrentView = _pMainView;
}

void ProDeckOS::updateFrames() {
    _pCurrentView->refresh();
}

void ProDeckOS::refreshKey(int index, QPixmap key) {
    _pStreamDeck->Draw(index, key);
}

void ProDeckOS::log(QString info) {
    //Logging::log(QString("[%1] %2").arg(_device->serialNumber()).arg(info));
}

void ProDeckOS::keyUp(QPoint point) {
    _pCurrentView->keyUp(point);
}

void ProDeckOS::keyDown(QPoint point) {
    _pCurrentView->keyDown(point);
}

#include <QDebug>
void ProDeckOS::addDevice(DeviceDiscovery::DiscoveredDevice dev) {
    Logging::log("OS: Added device: " + dev.device->deviceName);

    auto *macro = dynamic_cast<MacroDevice *>(dev.device);

    if (macro != nullptr) {
        _pStreamDeck = new StreamDeck(dev);

        if (!_pStreamDeck->Open()) {
            Logging::log("OS: Unable to open device: " + dev.device->deviceName);
            _pStreamDeck = nullptr;
            return;
        }

        _pStreamDeck->Clear();
        _pStreamDeck->SetBrightness(100);
        connect(_pStreamDeck, SIGNAL(keyUp(QPoint)), this, SLOT(keyUp(QPoint)));
        connect(_pStreamDeck, SIGNAL(keyDown(QPoint)), this, SLOT(keyDown(QPoint)));

        _pCurrentView = new SplashScreen(QRect(QPoint(0, 0),_pStreamDeck->size()));

        connect(_pCurrentView, SIGNAL(refreshKey(int, QPixmap)), this, SLOT(refreshKey(int, QPixmap)));

        _pUpdateFrameTimer = new QTimer(this);
        connect(_pUpdateFrameTimer, SIGNAL(timeout()), this, SLOT(updateFrames()));
        _pUpdateFrameTimer->setSingleShot(false);
        _pUpdateFrameTimer->start(20);

        _pSplashScreenTimer = new QTimer(this);
        connect(_pSplashScreenTimer, SIGNAL(timeout()), this, SLOT(endSplash()));
        _pSplashScreenTimer->start(200*5);

        _pMainView = new NavigationView(QRect(QPoint(0, 0),_pStreamDeck->size()));
        connect(_pMainView, SIGNAL(refreshKey(int, QPixmap)), this, SLOT(refreshKey(int, QPixmap)));

    }

}

ProDeckOS::~ProDeckOS() {
    log("Stopping ProDeckOS");
    _pUpdateFrameTimer->stop();
}

