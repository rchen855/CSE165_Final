QT       += core gui openglwidgets \
            multimedia

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++17

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    Sources/FasterEnemy.cpp \
    Sources/Menu.cpp \
    Sources/RegularEnemy.cpp \
    Sources/TankEnemy.cpp \
    Sources/main.cpp \
    Sources/Bullet.cpp \
    Sources/Enemy.cpp \
    Sources/game.cpp \
    Sources/Player.cpp \
    Sources/Score.cpp \
    Sources/Health.cpp

HEADERS += \
    Headers/Bullet.h \
    Headers/Enemy.h \
    Headers/FasterEnemy.h \
    Headers/Game.h \
    Headers/Menu.h \
    Headers/Player.h \
    Headers/RegularEnemy.h \
    Headers/Score.h \
    Headers/Health.h \
    Headers/TankEnemy.h

RESOURCES += \
    res.qrc


# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target
