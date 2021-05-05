#include <QTimer>

#include "ProDeckOS.h"
#include "Core/Logging/Logging.h"
#include <unistd.h>

ProDeckOS::ProDeckOS(StreamDeckDevice *device): _device(device)
{
    log("Starting ProDeckOS");
    ClearScreen();
    SetBrightness(25);

    _pUpdateFrameTimer = new QTimer(this);
    connect(_pUpdateFrameTimer, SIGNAL(timeout()), this, SLOT(updateFrames()));
    _pUpdateFrameTimer->setSingleShot(false);
    _pUpdateFrameTimer->start(100);

}

ProDeckOS::~ProDeckOS() {
    log("Stopping ProDeckOS");
    _pUpdateFrameTimer->stop();
}

int row = 0;
int colorIndex = 0;

void ProDeckOS::updateFrames() {
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

    _device->Draw(row, colors[colorIndex]);
    _device->Draw(row+8, colors[colorIndex]);
    _device->Draw(row+16, colors[colorIndex]);
    _device->Draw(row+24, colors[colorIndex]);
    row++;

    if (row > 7) {
        row = 0;
        colorIndex++;
    }

    if (colorIndex >= colors.count()) {
        colorIndex = 0;
    }
}

void ProDeckOS::ClearScreen() {
    log("Clearing screen");
    _device->Clear();
}

void ProDeckOS::SetBrightness(short brightness) {
    log(QString("Setting brightness to %1%").arg(brightness));
}

void ProDeckOS::log(QString info) {
    Logging::log(QString("[%1] %2").arg(_device->serialNumber()).arg(info));
}
