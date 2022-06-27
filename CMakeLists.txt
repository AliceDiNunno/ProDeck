cmake_minimum_required(VERSION 3.22)
project(ProDeck VERSION 1.0.0)

#/Qt/6.3.0/macos/lib/cmake/Qt6/

set(CMAKE_PREFIX_PATH
        ${CMAKE_PREFIX_PATH}
        /Users/Alice/Qt/6.3.1/macos/lib/cmake/Qt6
        /Users/Alice/Qt/6.3.1/macos/lib/cmake/Qt6Tools
        /Users/Alice/Qt/6.3.1/macos/lib/cmake/Qt6CoreTools
        /Users/Alice/Qt/6.3.1/macos/lib/cmake/Qt6WidgetsTools
        /Users/Alice/Qt/6.3.1/macos/lib/cmake/Qt6GuiTools
        /Users/Alice/Qt/6.3.1/macos/lib/cmake/Qt6DBusTools
        )

set(CMAKE_INCLUDE_CURRENT_DIR ON)
set(CMAKE_CXX_STANDARD 17)

include_directories(.)
include_directories(src/core)
include_directories(src/core/DeckController)
include_directories(src/core/device)
include_directories(src/core/device/elgato)
include_directories(src/core/device/razer)
include_directories(src/core/hid)
include_directories(src/core/logging)
include_directories(src/core/RazerController)
include_directories(libs)
include_directories(libs/hidapi)
include_directories(src/OS)

find_package(Qt6 COMPONENTS Core Widgets Network REQUIRED)
qt_standard_project_setup()

add_executable(ProDeck
        src/core/device/elgato/StreamDeck.cpp
        src/core/device/elgato/StreamDeck.h
        src/core/device/elgato/StreamDeckSupportedDevice.h
        src/core/device/elgato/StreamDeckDeviceInformation.h
        src/core/device/elgato/StreamDeckFactory.cpp
        src/core/device/elgato/StreamDeckFactory.h
        src/core/device/elgato/metadata/StreamDeckXLDevice.cpp
        src/core/device/elgato/metadata/StreamDeckXLDevice.h
        src/core/device/razer/RazerSupportedDevice.h
        src/core/device/razer/metadata/RazerBlackWidowV3Device.cpp
        src/core/device/razer/metadata/RazerBlackWidowV3Device.h
        src/core/device/razer/metadata/RazerBasiliskV3Device.cpp
        src/core/device/razer/metadata/RazerBasiliskV3Device.h
        src/core/device/razer/RazerDeviceInformation.h
        src/core/device/razer/RazerFactory.cpp
        src/core/device/razer/RazerFactory.h
        src/core/hid/HidDescriptor.cpp
        src/core/hid/HidDescriptor.h
        src/core/hid/HidDiscovery.cpp
        src/core/hid/HidDiscovery.h
        src/core/logging/Logging.cpp
        src/core/logging/Logging.h
        src/core/RazerController/RazerSupportedDevice.cpp
        src/core/RazerController/RazerDevice.h
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
        src/ProDeck.cpp
        src/ProDeck.h src/core/device/HidDevice.hpp src/core/device/razer/RazerDeviceInformation.cpp src/core/device/HidDevice.cpp src/core/device/elgato/StreamDeckDeviceInformation.cpp src/core/device/MacroDevice.cpp src/core/device/MacroDevice.hpp src/core/device/elgato/StreamDeckSupportedDevice.cpp src/core/device/razer/RazerSupportedDevice.cpp src/core/device/DeviceDiscovery.cpp src/core/device/DeviceDiscovery.hpp src/core/device/HidDescriptorFactory.hpp src/OS/NavigationView.cpp src/OS/NavigationView.hpp src/OS/Button.cpp src/OS/Button.hpp)

target_link_libraries(ProDeck PUBLIC
        "-framework Foundation" PRIVATE Qt6::Core Qt6::Widgets)