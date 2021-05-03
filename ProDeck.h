#ifndef PRODECK_H
#define PRODECK_H

#include <QObject>
#include "Core/DeckController/StreamDeckDevice.h"
#include "Core/DeckController/StreamDeckDiscovery.h"

class ProDeck: public QObject
{
    Q_OBJECT

public:
    ProDeck();
    ~ProDeck();

private slots:
   void discoveryUpdated(QList<StreamDeckDevice> );

private:
   void startDevice(StreamDeckDevice );
   void stopDevice(StreamDeckDevice );

private:
   StreamDeckDiscovery *_pDiscovery;
   QList<StreamDeckDevice> _runningDevices;
};

#endif // PRODECK_H
