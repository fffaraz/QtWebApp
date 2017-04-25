# This project demonstrates how to use QtWebAppLib by linking to the shared library (*.dll or *.so).

TARGET = Demo2
TEMPLATE = app
QT = core network
CONFIG += console depend_includepath

HEADERS += \
           src/requesthandler.h

SOURCES += src/main.cpp \
           src/requesthandler.cpp

OTHER_FILES += etc/*  logs/* ../readme.txt

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
CONFIG(release, debug|release) {
    win32:      LIBS += -L$$PWD/../build-QtWebApp-Desktop_Qt_5_7_1_MinGW_32bit-Release/release/  -lQtWebApp1
    mac:        LIBS += -L$$PWD/../build-QtWebApp-Desktop_Qt_5_7_1_clang_64bit-Release/          -lQtWebApp
    unix:!mac:  LIBS += -L$$PWD/../build-QtWebApp-Desktop_Qt_5_7_1_GCC_64bit-Debug/              -lQtWebApp
}

# Directory where the debug version of the shared library (*.dll or *.so) is stored, and base name of the file.
CONFIG(debug, debug|release) {
    win32:      LIBS += -L$$PWD/../build-QtWebApp-Desktop_Qt_5_7_1_MinGW_32bit-Debug/debug/      -lQtWebAppd1
    mac:        LIBS += -L$$PWD/../build-QtWebApp-Desktop_Qt_5_7_1_clang_64bit-Debug/            -lQtWebApp_debug
    unix:!mac:  LIBS += -L$$PWD/../build-QtWebApp-Desktop_Qt_5_7_1_GCC_64bit-Debug/              -lQtWebAppd
}

win32 {
   DEFINES += QTWEBAPPLIB_IMPORT
}
