TEMPLATE = app
TARGET = CarMonitor
QT += quick quickcontrols2

QT += bluetooth

SOURCES += \
    btconnection.cc \
    main.cpp

RESOURCES += \
    main.qml \
    qmldir \
    qtquickcontrols2.conf \
    icons/speed.png \
    icons/pedal.png \
    icons/engine.png \
    icons/rpm.png \
    icons/maf.png \
    icons/coolant.png

HEADERS += \
    btconnection.hh


