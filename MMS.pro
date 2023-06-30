QT       += core gui
QT       += sql

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++17

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    admwindow.cpp \
    c2_admember.cpp \
    c2_admerchandise.cpp \
    c2_adorder.cpp \
    c_memberchat.cpp \
    c_memberinfo.cpp \
    c_membermarket.cpp \
    c_memberorder.cpp \
    database.cpp \
    main.cpp \
    mainpage.cpp \
    mainwindow.cpp \
    memberwindow.cpp

HEADERS += \
    admwindow.h \
    c2_admember.h \
    c2_admerchandise.h \
    c2_adorder.h \
    c_memberchat.h \
    c_memberinfo.h \
    c_membermarket.h \
    c_memberorder.h \
    database.h \
    mainpage.h \
    mainwindow.h \
    memberwindow.h

FORMS += \
    admwindow.ui \
    c2_admember.ui \
    c2_admerchandise.ui \
    c2_adorder.ui \
    c_memberchat.ui \
    c_memberinfo.ui \
    c_membermarket.ui \
    c_memberorder.ui \
    mainpage.ui \
    mainwindow.ui \
    memberwindow.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target
