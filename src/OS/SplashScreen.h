#ifndef SPLASHSCREEN_H
#define SPLASHSCREEN_H

#include "DeckView.h"

class SplashScreen: public DeckView
{
public:
    SplashScreen(QRect window);
    void endSplashScreen();
    void refresh();

    void draw();
    void drawEndFading();

    void keyDown(QPoint point);
    void keyUp(QPoint point);

private:
    bool isEnding = false;
    int row = 0;
    int colorIndex = 0;
    int fadingIndex = 0;
};

#endif // SPLASHSCREEN_H
