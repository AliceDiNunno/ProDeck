#ifndef NAVIGATIONVIEW_H
#define NAVIGATIONVIEW_H

#include "OS/DeckView.h"

class NavigationBar;
class NavigationView: DeckView
{
public:
    NavigationView(QRect window);

private:
    NavigationBar *_pNavigationBar;
    DeckView *_pCurrentView;
};

#endif // NAVIGATIONVIEW_H
