#-------------------------------------------------
#
# Project created by QtCreator 2018-02-18T14:18:47
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = manager
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    worker.cpp \
    register.cpp \
    findpassword.cpp \
    workerdialog.cpp \
    workermodifydialog.cpp \
    resources.cpp \
    manager.cpp \
    checkwages.cpp \
    managerdialog.cpp \
    findworker.cpp \
    addworker.cpp \
    modifypassword.cpp \
    databackup.cpp \
    displayworker.cpp \
    analys.cpp \
    displaybydepartment.cpp \
    datarecovery.cpp

HEADERS  += mainwindow.h \
    macro.h \
    param.h \
    stdafx.h \
    worker.h \
    register.h \
    findpassword.h \
    workerdialog.h \
    workermodifydialog.h \
    resources.h \
    manager.h \
    checkwages.h \
    managerdialog.h \
    findworker.h \
    addworker.h \
    modifypassword.h \
    databackup.h \
    displayworker.h \
    analys.h \
    displaybydepartment.h \
    datarecovery.h

FORMS    += mainwindow.ui \
    register.ui \
    findpassword.ui \
    workerdialog.ui \
    workermodifydialog.ui \
    checkwages.ui \
    managerdialog.ui \
    findworker.ui \
    addworker.ui \
    modifypassword.ui \
    databackup.ui \
    displayworker.ui \
    analys.ui \
    displaybydepartment.ui \
    datarecovery.ui

DISTFILES +=

RESOURCES += \
    resource.qrc
