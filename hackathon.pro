QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++11

# The following define makes your compiler emit warnings if you use
# any Qt feature that has been marked deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    #Block.cpp \
    #BlockChain.cpp \
    Block.cpp \
    BlockChain.cpp \
    FI.cpp \
    HashMap.cpp \
    PasswordManager.cpp \
    #Private_Public_generation.cpp \
    #Sha256.cpp \
    Report.cpp \
    Sha256.cpp \
    ThirdParty.cpp \
    access.cpp \
    main.cpp \
    mainwindow.cpp \
    make.cpp \
    second.cpp

HEADERS += \
    #Block.h \
    #BlockChain.h \
    #FI.h \
    Block.h \
    BlockChain.h \
    FI.h \
    PasswordManager.h \
    #Report.h \
    #Sha256.h \
    Report.h \
    Sha256.h \
    ThirdParty.h \
    access.h \
    mainwindow.h \
    make.h \
    picosha2.h \
    second.h

FORMS += \
    access.ui \
    mainwindow.ui \
    make.ui \
    second.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

RESOURCES += \
    belp.qrc \
    belp.qrc \
    belp.qrc

DISTFILES += \
    BELP.png \
    hackathon.pro.user
