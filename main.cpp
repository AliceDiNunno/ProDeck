#include <QApplication>

#include <QDebug>
#include <signal.h>
#include <hidapi/hidapi.h>

#include "Core/Logging/Logging.h"
#include "ProDeck.h"
#define MAX_STR 255

ProDeck *app;

void exiting() {
    app->deleteLater();
    app = nullptr;

    auto exitStatus = hid_exit();

    if (exitStatus == -1) {
        Logging::error("Hidapi was unable to free itself correctly");
    }
}

void signalCatched(int ) {
    exiting();
}

int main(int argc, char *argv[])
{
    int hidInitStatus = hid_init();
    if (hidInitStatus == -1) {
        Logging::error("Hidapi was unable to start correctly");
        return -1;
    }

    QApplication a(argc, argv);

    app = new ProDeck();

    signal(SIGTERM, signalCatched);

    std::atexit(exiting);

    return a.exec();
}

