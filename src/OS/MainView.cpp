#include "MainView.h"
#include <QDebug>

MainView::MainView(QRect window): DeckView(window)
{
}

void MainView::refresh() {
    for(int i = 0; i < 32; i++) {
        if (i != 0 && i != 8 && i != 16 && i != 24) {
            auto black = QPixmap(96, 96);
            black.fill(QColor("green"));

            emit refreshKey(i, black);
        }
    }
}

void MainView::keyDown(QPoint point) {
    if (point.x() == 0) {
        qDebug() << "MainView::keyDown" << point;
    }
}

void MainView::keyUp(QPoint point) {
    if (point.x() == 0) {
        qDebug() << "MainView::keyUp" << point;
    }
}