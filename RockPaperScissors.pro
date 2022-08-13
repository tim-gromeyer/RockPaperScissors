QT       += core gui svg

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++17

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x051208    # disables all the APIs deprecated before Qt 5.12.8

INCLUDEPATH += \
    src/

SOURCES += \
    src/main.cpp \
    src/mainwindow.cpp

HEADERS += \
    src/mainwindow.h

FORMS += \
    ui/mainwindow.ui

TRANSLATIONS += \
    ressources/translations/RockPaperScissors_de.ts

CONFIG += lrelease
CONFIG += embed_translations

RESOURCES += \
    ressources/ressource.qrc

# Only show qDebug() messages in debug mode
CONFIG(release, debug | release): DEFINES += QT_NO_DEBUG_OUTPUT

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
message("target.path=$$target.path")
!isEmpty(target.path): INSTALLS += target

DISTFILES += \
    CMakeLists.txt
