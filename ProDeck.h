#ifndef PRODECK_H
#define PRODECK_H

#include <QObject>

#include "src/Core/DeckController/StreamDeckDevice.h"
#include "src/Core/DeckController/StreamDeckDiscovery.h"
#include "src/Core/RazerController/RazerDevice.h"
#include "src/Core/RazerController/RazerDiscovery.h"

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
   void stopOS(ProDeckOS *);

private:
   StreamDeckDiscovery *_pDiscovery;
   RazerDiscovery *_pRazerDiscovery;
   QMap<StreamDeckDevice *, ProDeckOS*> *_runningDevices;
};

#endif // PRODECK_H
