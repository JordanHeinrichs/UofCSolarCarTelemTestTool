INCLUDEPATH += .
QT+=widgets serialport

CONFIG += c++11 debug

!win32 {
   QMAKE_CXXFLAGS += -Werror
}

DESTDIR = ../release
OBJECTS_DIR = ../release/.obj
MOC_DIR = ../release/.moc
RCC_DIR = ../release/.rcc
UI_DIR = ../release/.ui
