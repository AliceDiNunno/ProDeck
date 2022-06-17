#ifndef PRODECKOS_H
#define PRODECKOS_H

#include "src/core/DeckController/StreamDeckDevice.h"

class DeckView;
class ProDeckOS: public QObject
{
    Q_OBJECT
public:
    ProDeckOS(StreamDeckDevice *device);
    ~ProDeckOS();

private:
    void ClearScreen();
    void SetBrightness(short int);
    void log(QString info);

private slots:
    void updateFrames();
    void endSplash();
    void refreshKey(int index, QPixmap key);

private:
    DeckView *_pCurrentView;
    StreamDeckDevice *_device;
    QTimer *_pUpdateFrameTimer;


    ///temporary
    QTimer *_pSplashScreenTimer;
};

#endif // PRODECKOS_H
