#ifndef SPLASHSCREEN_H
#define SPLASHSCREEN_H

#include "DeckView.h"

class SplashScreen: public DeckView
{
public:
    SplashScreen(QRect window);
    void refresh();
};

#endif // SPLASHSCREEN_H
