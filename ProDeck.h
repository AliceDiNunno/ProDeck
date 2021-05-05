#ifndef PRODECK_H
#define PRODECK_H

#include <QObject>
#include "Core/DeckController/StreamDeckDevice.h"
#include "Core/DeckController/StreamDeckDiscovery.h"

class ProDeckOS;
class ProDeck: public QObject
{
    Q_OBJECT

public:
    ProDeck();
    ~ProDeck();

private slots:
   void discoveryUpdated(QList<StreamDeckDevice *> );

private:
   ProDeckOS *startDevice(StreamDeckDevice * );
   void stopDevice(StreamDeckDevice *);

private:
   StreamDeckDiscovery *_pDiscovery;
   QMap<StreamDeckDevice *, ProDeckOS*> *_runningDevices;
};

#endif // PRODECK_H
