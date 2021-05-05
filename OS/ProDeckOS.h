#ifndef PRODECKOS_H
#define PRODECKOS_H

#include "Core/DeckController/StreamDeckDevice.h"

class ProDeckOS: public QObject
{
    Q_OBJECT
public:
    ProDeckOS(StreamDeckDevice *device);

private:
    void ClearScreen();
    void SetBrightness(short int);
    void log(QString info);

private slots:
    void updateFrames();

private:
    StreamDeckDevice *_device;
    QTimer *_pUpdateFrameTimer;
};

#endif // PRODECKOS_H
