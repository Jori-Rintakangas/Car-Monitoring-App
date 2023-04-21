#include <QBluetoothDeviceDiscoveryAgent>
#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <QQmlContext>
#include <QSettings>
#include <QIcon>

#include "btconnection.hh"

int main(int argc, char *argv[])
{
    QGuiApplication::setApplicationName("Car Monitoring");
    QGuiApplication app(argc, argv);

    QIcon::setThemeName("Car Monitoring");

    BtConnection bt_connection;

    QQmlApplicationEngine engine;
    QQmlContext *root_context = engine.rootContext();
    root_context->setContextProperty("btConnection", &bt_connection);

    engine.load(QUrl("qrc:/main.qml"));
    if (engine.rootObjects().isEmpty())
        return -1;

    return app.exec();
}
