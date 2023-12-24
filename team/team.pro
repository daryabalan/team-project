TEMPLATE = app
CONFIG += console
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += main.cpp \
    login.cpp \
    bonussystem.cpp \
    client.cpp \
    clientlist.cpp \
    yearlyreport.cpp \

include(deployment.pri)
qtcAddDeployment()

HEADERS += \
    Client.h \
    ClientList.h\
    YearlyReport.h\
    Login.h\
    BonusSystem.h\
