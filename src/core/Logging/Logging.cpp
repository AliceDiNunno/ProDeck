#include <QDateTime>
#include <QDebug>

#include "Logging.h"

void Logging::log(QString entry) {
    writeLog("L: " + entry);
}

void Logging::error(QString entry) {
    writeLog("E: " + entry);
}

void Logging::warning(QString entry) {
    writeLog("W: " + entry);
}

void Logging::writeLog(QString entry) {
    auto currentDate = QDateTime().currentDateTime().toString();

    qDebug() << (currentDate + ": " + entry);
}
