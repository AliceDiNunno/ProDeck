#ifndef PRODECKOS_H
#define PRODECKOS_H

#include "src/core/device/elgato/StreamDeck.h"
#include "DeviceDiscovery.hpp"
#include "NavigationView.hpp"

class DeckView;
class ProDeckOS: public QObject
{
    Q_OBJECT
public:
    ProDeckOS();
    ~ProDeckOS();

    void addDevice(DeviceDiscovery::DiscoveredDevice dev);
private:
    void log(QString info);

private slots:
    void updateFrames();
    void endSplash();
    void refreshKey(int index, QPixmap key);

    void keyUp(QPoint point);
    void keyDown(QPoint point);

private:
    StreamDeck *_pStreamDeck;
    DeckView *_pCurrentView;
    NavigationView *_pMainView;
    QTimer *_pUpdateFrameTimer;

    ///temporary
    QTimer *_pSplashScreenTimer;
};

#endif // PRODECKOS_H
