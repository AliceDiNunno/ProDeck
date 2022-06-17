cmake_minimum_required(VERSION 3.22)
project(ProDeck VERSION 1.0.0)

#/Qt/6.3.0/macos/lib/cmake/Qt6/

set(CMAKE_PREFIX_PATH
        ${CMAKE_PREFIX_PATH}
        /Users/Alice/Qt/6.3.0/macos/lib/cmake/Qt6
        /Users/Alice/Qt/6.3.0/macos/lib/cmake/Qt6Tools
        /Users/Alice/Qt/6.3.0/macos/lib/cmake/Qt6CoreTools
        /Users/Alice/Qt/6.3.0/macos/lib/cmake/Qt6WidgetsTools
        /Users/Alice/Qt/6.3.0/macos/lib/cmake/Qt6GuiTools
        /Users/Alice/Qt/6.3.0/macos/lib/cmake/Qt6DBusTools
        )

set(CMAKE_INCLUDE_CURRENT_DIR ON)
set(CMAKE_CXX_STANDARD 17)

include_directories(.)
include_directories(src/core)
include_directories(src/core/DeckController)
include_directories(src/core/Device)
include_directories(src/core/Device/Elgato)
include_directories(src/core/Device/Razer)
include_directories(src/core/Hid)
include_directories(src/core/Logging)
include_directories(src/core/RazerController)
include_directories(libs)
include_directories(libs/hidapi)
include_directories(src/OS)

find_package(Qt6 COMPONENTS Core Widgets Network REQUIRED)
qt_standard_project_setup()

add_executable(ProDeck
        src/core/DeckController/StreamDeckDevice.cpp
        src/core/DeckController/StreamDeckDevice.h
        src/core/DeckController/StreamDeckDiscovery.cpp
        src/core/DeckController/StreamDeckDiscovery.h
        src/core/Device/Elgato/StreamDeckAvailableDevice.h
        src/core/Device/Elgato/StreamDeckDeviceInformation.h
        src/core/Device/Elgato/streamdeckfactory.cpp
        src/core/Device/Elgato/StreamDeckFactory.h
        src/core/Device/Elgato/StreamDeckXLDevice.cpp
        src/core/Device/Elgato/StreamDeckXLDevice.h
        src/core/Device/Razer/RazerAvailableDevice.h
        src/core/Device/Razer/RazerBlackWidowV3Device.cpp
        src/core/Device/Razer/RazerBlackWidowV3Device.h
        src/core/Device/Razer/RazerDeviceInformation.h
        src/core/Device/Razer/RazerFactory.cpp
        src/core/Device/Razer/RazerFactory.h
        src/core/Hid/HidDevice.cpp
        src/core/Hid/HidDevice.h
        src/core/Hid/HidDeviceInformation.h
        src/core/Hid/HidDiscovery.cpp
        src/core/Hid/HidDiscovery.h
        src/core/Logging/Logging.cpp
        src/core/Logging/Logging.h
        src/core/RazerController/RazerDevice.cpp
        src/core/RazerController/RazerDevice.h
        src/core/RazerController/RazerDiscovery.cpp
        src/core/RazerController/RazerDiscovery.h
        libs/hidapi/mac/hid.c
        libs/hidapi/hidapi.h
        src/OS/Configuration.cpp
        src/OS/Configuration.h
        src/OS/DeckView.cpp
        src/OS/DeckView.h
        src/OS/MainView.cpp
        src/OS/MainView.h
        src/OS/NavigationBar.cpp
        src/OS/NavigationBar.h
        src/OS/ProDeckOS.cpp
        src/OS/ProDeckOS.h
        src/OS/SplashScreen.cpp
        src/OS/SplashScreen.h
        macos_appnap.h
        macos_appnap.mm
        main.cpp
        ProDeck.cpp
        ProDeck.h)

target_link_libraries(ProDeck PUBLIC
        "-framework Foundation" PRIVATE Qt6::Core Qt6::Widgets)