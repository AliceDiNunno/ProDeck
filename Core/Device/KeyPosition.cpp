#include "KeyPosition.h"

KeyPosition::KeyPosition(QPoint point, QRect context) {
    _context = context;
    _point = point;
    _absolutePosition = 0;
    _absolutePosition = positionFromPoint();
}

KeyPosition::KeyPosition(int absolutePosition, QRect context) {
    _context = context;
    _absolutePosition = absolutePosition;
    _point = QPoint(0, 0);

    _point = pointFromPosition();
}

int KeyPosition::positionFromPoint() {
    return int((_point.y() * _context.width()) + _point.x());
}

QPoint KeyPosition::pointFromPosition() {
    return QPoint(int(int(_absolutePosition) % _context.width()),
                  int(int(_absolutePosition) / _context.width()));
}

QPoint KeyPosition::getPoint() {
    return _point;
}

void KeyPosition::setPoint(QPoint point) {
    _point = point;
    _absolutePosition = positionFromPoint();
}

int KeyPosition::getAbsolutePosition() {
    return _absolutePosition;
}

void KeyPosition::setAbsolutePosition(int position) {
    _absolutePosition = position;
    _point = pointFromPosition();
}
