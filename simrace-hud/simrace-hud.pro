QT += quick

CONFIG += c++11

# The following define makes your compiler emit warnings if you use
# any Qt feature that has been marked deprecated (the exact warnings
# depend on your compiler). Refer to the documentation for the
# deprecated API to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

INCLUDEPATH += ../

HEADERS += \
    control/hudcontrol.h \
    registertype.h

SOURCES += \
        control/hudcontrol.cpp \
        registertype.cpp \
        main.cpp

RESOURCES += qml.qrc

TRANSLATIONS += \
    simrace-hud_pt_BR.ts

# Additional import path used to resolve QML modules in Qt Creator's code model
QML_IMPORT_PATH =

# Additional import path used to resolve QML modules just for Qt Quick Designer
QML_DESIGNER_IMPORT_PATH =

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

LIBS += -L$$OUT_PWD/../simrace-core/ -lsimrace-core
INCLUDEPATH += $$PWD/../simrace-core

LIBS += -L$$OUT_PWD/../simrace-demo/ -lsimrace-demo
INCLUDEPATH += $$PWD/../simrace-demo

LIBS += -L$$OUT_PWD/../simrace-projectcars/ -lsimrace-projectcars
INCLUDEPATH += $$PWD/../simrace-projectcars

DISTFILES += \
    Hud.qml \
    HudForm.ui.qml
