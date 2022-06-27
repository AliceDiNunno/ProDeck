#ifndef MAINVIEW_H
#define MAINVIEW_H

#include "src/OS/DeckView.h"

class MainView: public DeckView
{
public:
    MainView(QRect window);
    void refresh();

public:
    void keyDown(QPoint point);
    void keyUp(QPoint point);
};

#endif // MAINVIEW_H
