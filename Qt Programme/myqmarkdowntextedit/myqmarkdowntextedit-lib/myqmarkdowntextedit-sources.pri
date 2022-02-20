INCLUDEPATH += $$PWD/

QT       += gui
greaterThan(QT_MAJOR_VERSION, 4): QT += widgets
SOURCES += \
    $$PWD/markdownhighlighter.cpp \
    $$PWD/qmarkdowntextedit.cpp \
    $$PWD/qownlanguagedata.cpp \
    $$PWD/qplaintexteditsearchwidget.cpp \
    $$PWD/qplaintexteditsearchwidget.cpp

FORMS += \
    $$PWD/qplaintexteditsearchwidget.ui

RESOURCES += \
    $$PWD/media.qrc
