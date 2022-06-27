QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++11

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

QMAKE_CXXFLAGS += -std=c++11

SOURCES += \
    Core/DeckController/StreamDeck.cpp \
    Core/DeckController/StreamDeckDiscovery.cpp \
    Core/Device/Elgato/StreamDeckFactory.cpp \
    Core/Device/Elgato/StreamDeckXLDevice.cpp \
    Core/Device/Razer/RazerBlackWidowV3Device.cpp \
    Core/Device/Razer/RazerFactory.cpp \
    Core/Hid/HidDescriptor.cpp \
    Core/Hid/HidDiscovery.cpp \
    Core/Logging/Logging.cpp \
    Core/RazerController/RazerDevice.cpp \
    Core/RazerController/RazerDiscovery.cpp \
    OS/Configuration.cpp \
    OS/DeckView.cpp \
    OS/MainView.cpp \
    OS/NavigationBar.cpp \
    OS/ProDeckOS.cpp \
    OS/SplashScreen.cpp \
    ProDeck.cpp \
    main.cpp

HEADERS += \
    Core/DeckController/StreamDeck.h \
    Core/DeckController/StreamDeckDiscovery.h \
    Core/Device/Elgato/StreamDeckSupportedDevice.h \
    Core/Device/Elgato/StreamDeckDeviceInformation.h \
    Core/Device/Elgato/StreamDeckFactory.h \
    Core/Device/Elgato/StreamDeckXLDevice.h \
    Core/Device/Razer/RazerDevice.h \
    Core/Device/Razer/RazerBlackWidowV3Device.h \
    Core/Device/Razer/RazerDeviceInformation.h \
    Core/Device/Razer/RazerFactory.h \
    Core/Hid/HidDescriptor.h \
    Core/Hid/HidDeviceInformation.h \
    Core/Hid/HidDiscovery.h \
    Core/Logging/Logging.h \
    Core/RazerController/RazerDevice.h \
    Core/RazerController/RazerDiscovery.h \
    OS/Configuration.h \
    OS/DeckView.h \
    OS/MainView.h \
    OS/NavigationBar.h \
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
