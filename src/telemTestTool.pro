! include( common.pri ) {
    error( "Couldn't find the common.pri file!" )
}

QT += widgets
TEMPLATE = app
TARGET = telemTestApp
INCLUDEPATH = BusinessLayer \
    DataLayer \
    UILayer \
    ViewLayer \
    Peripherals

HEADERS  += \
    TestApplication.h \
    BusinessLayer/CrcCalculator.h \
    BusinessLayer/TelemetryReporting.h \
    BusinessLayer/CommunicationService.h \
    BusinessLayer/DataModifier.h \
    DataLayer/CcsDefines.h \
    DataLayer/CmuData.h \
    DataLayer/MpptData.h \
    DataLayer/VehicleData.h \
    Peripherals/SerialPortPeripheral.h \
    Peripherals/I_CommPeripheral.h \
    ViewLayer/View.h \
    UILayer/Window.h

SOURCES += \
    main.cpp \
    TestApplication.cpp \
    BusinessLayer/CrcCalculator.cpp \
    BusinessLayer/TelemetryReporting.cpp \
    BusinessLayer/CommunicationService.cpp \
    BusinessLayer/DataModifier.cpp \
    DataLayer/CmuData.cpp \
    DataLayer/MpptData.cpp \
    DataLayer/VehicleData.cpp \
    Peripherals/SerialPortPeripheral.cpp \
    ViewLayer/View.cpp \
    UILayer/Window.cpp

FORMS += \
    UILayer/WindowDesign.ui
