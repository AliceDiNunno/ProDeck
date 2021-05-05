#include "DeckView.h"

DeckView::DeckView(QRect window): _window(window) {

}

QRect DeckView::getRect() {
    return _window;
}
