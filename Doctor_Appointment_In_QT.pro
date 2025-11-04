#-------------------------------------------------
#
# Project: Doctor Appointment In Qt (OOP - No DB)
#
#-------------------------------------------------

QT       += core gui
greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = Doctor_Appointment_In_QT
TEMPLATE = app

DEFINES += QT_DEPRECATED_WARNINGS
CONFIG += c++11

SOURCES += \
    logindialog.cpp \
    main.cpp \
    mainwindow.cpp \
    booking.cpp \
    cancellation.cpp \
    availableslots.cpp \
    records.cpp \
    userprofile.cpp

HEADERS += \
    bookinginfo.h \
    bookinginfo.h \
    logindialog.h \
    mainwindow.h \
    booking.h \
    cancellation.h \
    availableslots.h \
    records.h \
    userprofile.h

FORMS += \
    logindialog.ui \
    mainwindow.ui \
    booking.ui \
    cancellation.ui \
    availableslots.ui \
    records.ui \
    userprofile.ui

# Deployment
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

RESOURCES += \
    resources.qrc
