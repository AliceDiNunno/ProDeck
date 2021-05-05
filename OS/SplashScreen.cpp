#include "SplashScreen.h"

SplashScreen::SplashScreen(QRect window): DeckView(window)
{

}

void SplashScreen::refresh() {
    if (!isEnding) {
        draw();
    } else {
        drawEndFading();
    }
}

void SplashScreen::draw() {
    auto red = QPixmap(96, 96);
    red.fill(Qt::red);

    auto orange = QPixmap(96, 96);
    orange.fill(QColor(243, 114, 32));

    auto yellow = QPixmap(96, 96);
    yellow.fill(Qt::yellow);

    auto green = QPixmap(96, 96);
    green.fill(Qt::green);

    auto blue = QPixmap(96, 96);
    blue.fill(Qt::blue);

    auto purple = QPixmap(96, 96);
    purple.fill(QColor("purple"));

    auto black = QPixmap(96, 96);
    black.fill(QColor("black"));

    QList<QPixmap> colors = {red, orange, yellow, green, blue, purple};
    QPixmap color;

    color = colors[colorIndex];


    emit refreshKey(row, color);
    emit refreshKey(row+8, color);
    emit refreshKey(row+16, color);
    emit refreshKey(row+24, color);
    row++;

    if (row > 7) {
       row = 0;
       colorIndex++;
    }

    if (colorIndex >= colors.count()) {
       colorIndex = 0;
    }
}

void SplashScreen::drawEndFading() {
    if (row > 7) {
        return;
    }

    auto black = QPixmap(96, 96);
    black.fill(QColor("black"));

    emit refreshKey(row, black);
    emit refreshKey(row+8, black);
    emit refreshKey(row+16, black);
    emit refreshKey(row+24, black);

    row++;
}

void SplashScreen::endSplashScreen() {
    isEnding = true;
    row = 0;
}
