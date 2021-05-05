#include "SplashScreen.h"

SplashScreen::SplashScreen()
{

}

int row = 0;
int colorIndex = 0;

void SplashScreen::refresh() {
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

       QList<QPixmap> colors = {red, orange, yellow, green, blue, purple};

       emit refreshKey(row, colors[colorIndex]);
       emit refreshKey(row+8, colors[colorIndex]);
       emit refreshKey(row+16, colors[colorIndex]);
       emit refreshKey(row+24, colors[colorIndex]);
       row++;

       if (row > 7) {
           row = 0;
           colorIndex++;
       }

       if (colorIndex >= colors.count()) {
           colorIndex = 0;
       }
}
