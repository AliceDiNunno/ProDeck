#ifndef NAVIGATIONBAR_H
#define NAVIGATIONBAR_H

#include "src/OS/DeckView.h"

class NavigationBar: public DeckView
{
public:
    NavigationBar(QRect window);
    void refresh();

public:
    void keyDown(QPoint point);
    void keyUp(QPoint point);
};

#endif // NAVIGATIONBAR_H
