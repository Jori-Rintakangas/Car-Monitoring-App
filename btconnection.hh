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
    Q_PROPERTY(QString connection_ READ getConnection NOTIFY connectionChanged)

public:
    explicit BtConnection(QObject *parent = 0);
    QString getConnection();
    ~BtConnection();

public slots:
    void deviceDiscovered(const QBluetoothDeviceInfo&);
    void startDeviceDiscovery();
    void stopDeviceDiscovery();
    void disconnectDevice();
    void deviceConnected();
    void deviceDisconnected();

signals:
    void connectionChanged();

private:
    QBluetoothDeviceDiscoveryAgent *discoveryAgent_;
    QString connection_ = "CONNECT";
    QString deviceAddress_ = "44:AF:28:BB:C0:64";
    QBluetoothLocalDevice *localDevice_;
};

#endif // BTCONNECTION_HH
