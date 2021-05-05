QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++11

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

QMAKE_CXXFLAGS += -std=c++11

SOURCES += \
    Core/DeckController/StreamDeckDevice.cpp \
    Core/DeckController/StreamDeckDiscovery.cpp \
    Core/Device/StreamDeckFactory.cpp \
    Core/Device/StreamDeckXLDevice.cpp \
    Core/Hid/HidDevice.cpp \
    Core/Hid/HidDiscovery.cpp \
    Core/Logging/Logging.cpp \
    OS/Configuration.cpp \
    OS/ProDeckOS.cpp \
    OS/SplashScreen.cpp \
    ProDeck.cpp \
    main.cpp

HEADERS += \
    Core/DeckController/StreamDeckDevice.h \
    Core/DeckController/StreamDeckDiscovery.h \
    Core/Device/StreamDeckAvailableDevice.h \
    Core/Device/StreamDeckDeviceInformation.h \
    Core/Device/StreamDeckFactory.h \
    Core/Device/StreamDeckXLDevice.h \
    Core/Hid/HidDevice.h \
    Core/Hid/HidDeviceInformation.h \
    Core/Hid/HidDiscovery.h \
    Core/Logging/Logging.h \
    OS/Configuration.h \
    OS/DeckView.h \
    OS/ProDeckOS.h \
    OS/SplashScreen.h \
    ProDeck.h

FORMS +=

TRANSLATIONS += \
    Prodeck_en_GB.ts

INCLUDEPATH += ./libs/ ./libs/hidapi

win32 {
    SOURCES += ./libs/hidapi/windows/hid.c
}
macx {
    HEADERS += macos_appnap.h
    SOURCES += ./libs/hidapi/mac/hid.c
    OBJECTIVE_SOURCES += macos_appnap.mm
    LIBS += -framework Foundation
}
unix:!macx {
    SOURCES += ./libs/hidapi/linux/hid.c
    LIBS += -ludev
}

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target
