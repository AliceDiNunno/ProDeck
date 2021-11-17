#ifndef KEYPOSITION_H
#define KEYPOSITION_H


#include <QRect>
#include <QPoint>

class KeyPosition
{
public:
    KeyPosition(QPoint point, QRect context);
    KeyPosition(int absolutePosition, QRect context);


    int positionFromPoint();
    QPoint pointFromPosition();

    QPoint getPoint();
    void setPoint(QPoint point);
    int getAbsolutePosition();
    void setAbsolutePosition(int );

private:
    QRect _context;
    QPoint _point;
    int _absolutePosition;
};

#endif // KEYPOSITION_H
