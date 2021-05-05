# This project demonstrates how to use QtWebAppLib by linking to the shared library (*.dll or *.so).

TARGET = Demo2
TEMPLATE = app
QT = core network
CONFIG += console depend_includepath

HEADERS += src/requesthandler.h

SOURCES += src/main.cpp  src/requesthandler.cpp

DISTFILES += ../CHANGELOG.txt ../LICENSE.txt ../README.txt

#---------------------------------------------------------------------------------------
# The following lines import the shared QtWebApp library.
# You may need to modify the path names to match your computer.
#---------------------------------------------------------------------------------------

CONFIG += depend_includepath

win32 {
   DEFINES += QTWEBAPPLIB_IMPORT
}

# Directories, where the *.h files are stored
INCLUDEPATH += $$PWD/../QtWebApp

# Directory where the release version of the shared library (*.dll or *.so) is stored, and base name of the file.
# You must copy this file also into the target folder of Demo2
CONFIG(release, debug|release) {
    win32:      LIBS += -L$$PWD/../build-QtWebApp-Desktop_Qt_5_15_2_MinGW_64bit-Release/release/  -lQtWebApp1
    mac:        LIBS += -L$$PWD/../build-QtWebApp-Desktop_Qt_5_15_2_clang_64bit-Release/          -lQtWebApp
    unix:!mac:  LIBS += -L$$PWD/../build-QtWebApp-Desktop_Qt_5_15_2_GCC_64bit-Release/            -lQtWebApp
  }

# Same for the debug version
CONFIG(debug, debug|release) {
    win32:      LIBS += -L$$PWD/../build-QtWebApp-Desktop_Qt_5_15_2_MinGW_64bit-Debug/debug/      -lQtWebAppd1
    mac:        LIBS += -L$$PWD/../build-QtWebApp-Desktop_Qt_5_15_2_clang_64bit-Debug/            -lQtWebApp_debug
    unix:!mac:  LIBS += -L$$PWD/../build-QtWebApp-Desktop_Qt_5_15_2_GCC_64bit-Debug/              -lQtWebAppd
}

win32 {
   DEFINES += QTWEBAPPLIB_IMPORT
}
