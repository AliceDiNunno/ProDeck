#include "Key.h"
#include "DeckView.h"

Key::Key(DeckView *parent, DeckPoint position) {
    this->_parent = parent;
    this->position = position;
}
