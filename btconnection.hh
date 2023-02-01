#ifndef BTCONNECTION_HH
#define BTCONNECTION_HH


#include <QBluetoothDeviceInfo>
#include <QBluetoothDeviceDiscoveryAgent>
#include <QBluetoothLocalDevice>
#include <QBluetoothDeviceInfo>
#include <QDebug>
#include <QObject>

class BtConnection : public QObject
{
    Q_OBJECT
public:
    explicit BtConnection(QObject *parent = 0);
    ~BtConnection();

public slots:
    void deviceDiscovered(const QBluetoothDeviceInfo&);
    void startDeviceDiscovery();
    void stopDeviceDiscovery();

private:
    QBluetoothDeviceDiscoveryAgent *discoveryAgent_;
};

#endif // BTCONNECTION_HH
