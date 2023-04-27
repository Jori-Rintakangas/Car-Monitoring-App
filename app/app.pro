TEMPLATE = app
TARGET = CarMonitor
QT += quick quickcontrols2

QT += bluetooth

SOURCES += \
    src/btconnection.cc \
    src/main.cpp

RESOURCES += \
    main.qml \
    qtquickcontrols2.conf \
    icons/speed.png \
    icons/pedal.png \
    icons/engine.png \
    icons/rpm.png \
    icons/maf.png \
    icons/coolant.png \
    icons/btconnected.png \
    icons/btdisconnected.png \
    icons/car.png

HEADERS += \
    src/btconnection.hh


