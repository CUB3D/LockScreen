cmake_minimum_required(VERSION 3.10)
project(LockScreen)

set(CMAKE_CXX_STANDARD 17)

set(CMAKE_MODULE_PATH ${PROJECT_SOURCE_DIR}/scripts/build)

# Find SDL2
find_package(SDL2 REQUIRED)
if(SDL2_FOUND)
    message("SDL2 Found: ${SDL2_INCLUDE_DIR}:${SDL2_LIBRARY}")
endif()

# Find SDL2_image
find_package(SDL2_image REQUIRED)
if(SDL2_IMAGE_FOUND)
    message("SDL2_image Found: ${SDL2_IMAGE_INCLUDE_DIR}:${SDL2_IMAGE_LIBRARY}")
endif()

# Find SDL2_ttf
find_package(SDL2_ttf REQUIRED)
if(SDL2_TTF_FOUND)
    message("SDL2_ttf Found: ${SDL2_TTF_INCLUDE_DIR}:${SDL2_TTF_LIBRARY}")
endif()

find_package(X11 REQUIRED)
if(X11_FOUND)
    message("X11: ${X11_INCLUDE_DIR}:${X11_LIBRARY}")
endif()

find_package(X11_XCB REQUIRED)
if(X11_XCB_FOUND)
    message("XCB: ${X11_XCB_INCLUDE_DIR}:${X11_XCB_LIBRARIES}")
endif()

find_package(RapidJSON REQUIRED)
If(RAPIDJSON_FOUND)
    message("RapidJSON: ${RAPIDJSON_INCLUDE_DIR}")
endif()

set(CMAKE_CXX_FLAGS ${CMAKE_CXX_FLAGS} -fpermissive)

include_directories(${SDL2_INCLUDE_DIR} ${SDL2_IMAGE_INCLUDE_DIR} ${SDL2_TTF_INCLUDE_DIR} ${X11_INCLUDE_DIR} ${X11_XCB_INCLUDE_DIR} ${RAPIDJSON_INCLUDE_DIR})
link_libraries(${SDL2_LIBRARY} ${SDL2_IMAGE_LIBRARY} ${SDL2_TTF_LIBRARY} ${X11_LIBRARY} ${X11_XCB_LIBRARIES} xcb xcb-util xcb-xkb xcb-xinerama xcb-randr xkbcommon xkbcommon-x11 xcb-image xcb-xrm ev pthread dl util m)
add_executable(LockScreen main.cpp TTFFont.cpp TTFFont.h XCBInstance.cpp XCBInstance.h Image.cpp Image.h widgets/BaseWidget.cpp widgets/BaseWidget.h widgets/ClockWidget.cpp widgets/ClockWidget.h widgets/PasswordEntryWidget.cpp widgets/PasswordEntryWidget.h UIRenderer.cpp UIRenderer.h widgets/BatteryWidget.cpp widgets/BatteryWidget.h ResourceManager.h Config.h main.h Util.h ResouceManager.cpp widgets/StaticImageWidget.cpp widgets/StaticImageWidget.h)