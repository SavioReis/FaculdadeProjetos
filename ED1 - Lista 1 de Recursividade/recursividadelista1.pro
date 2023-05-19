QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++17

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    exercicio1.cpp \
    exercicio2.cpp \
    exercicio3.cpp \
    exercicio4.cpp \
    exercicio5.cpp \
    exercicio6.cpp \
    iexe1.cpp \
    iexe2.cpp \
    iexe3.cpp \
    iexe4.cpp \
    iexe5.cpp \
    iexe6.cpp \
    main.cpp \
    mainwindow.cpp

HEADERS += \
    exercicio1.h \
    exercicio2.h \
    exercicio3.h \
    exercicio4.h \
    exercicio5.h \
    exercicio6.h \
    iexe1.h \
    iexe2.h \
    iexe3.h \
    iexe4.h \
    iexe5.h \
    iexe6.h \
    mainwindow.h

FORMS += \
    iexe1.ui \
    iexe2.ui \
    iexe3.ui \
    iexe4.ui \
    iexe5.ui \
    iexe6.ui \
    mainwindow.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target
