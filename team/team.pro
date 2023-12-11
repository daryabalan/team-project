TEMPLATE = app
CONFIG += console
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += main.cpp

include(deployment.pri)
qtcAddDeployment()

HEADERS += \
    class.h \
    Client.h \
    ClientList.h\
    YearlyReport.h\
    Login.h\
    operation.h\
    BillDetails.h\
