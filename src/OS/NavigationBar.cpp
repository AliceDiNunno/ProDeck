#include "NavigationBar.h"

#include <QDebug>

NavigationBar::NavigationBar(QRect window): DeckView(window)
{
}

void NavigationBar::refresh() {
    auto black = QPixmap(96, 96);
    black.fill(QColor("blue"));

    emit refreshKey(0, black);
    emit refreshKey(8, black);
    emit refreshKey(16, black);
    emit refreshKey(24, black);
}

void NavigationBar::keyDown(QPoint point) {
    qDebug() << "NavigationBar::keyDown" << point;
}

void NavigationBar::keyUp(QPoint point) {
    qDebug() << "NavigationBar::keyUp" << point;
}