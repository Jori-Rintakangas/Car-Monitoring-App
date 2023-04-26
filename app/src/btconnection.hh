#ifndef BTCONNECTION_HH
#define BTCONNECTION_HH

#include <QBluetoothLocalDevice>
#include <QBluetoothSocket>
#include <QDebug>
#include <QObject>

const QString UUID = "00001101-0000-1000-8000-00805f9b34fb"; // uuid of SPP protocol
const QString DEVICE_MAC = ""; // MAC address of ESP32

class BtConnection : public QObject
{
    Q_OBJECT
    Q_PROPERTY(QString connection_ READ getConnection NOTIFY connectionChanged)
    Q_PROPERTY(QString speed_ READ getSpeed NOTIFY speedChanged)
    Q_PROPERTY(QString rpm_ READ getRpm NOTIFY rpmChanged)
    Q_PROPERTY(QString temp_ READ getTemp NOTIFY tempChanged)
    Q_PROPERTY(QString load_ READ getLoad NOTIFY loadChanged)
    Q_PROPERTY(QString maf_ READ getMaf NOTIFY mafChanged)
    Q_PROPERTY(QString throttle_ READ getThrottle NOTIFY throttleChanged)
    Q_PROPERTY(bool connecting_ READ getConnecting NOTIFY connectingChanged)

public:
    explicit BtConnection(QObject *parent = 0);
    ~BtConnection();
    QString getConnection();
    QString getSpeed();
    QString getRpm();
    QString getTemp();
    QString getLoad();
    QString getMaf();
    QString getThrottle();
    bool getConnecting();

public slots:
    void connectDevice();
    void disconnectDevice();

signals:
    void connectionChanged();
    void speedChanged();
    void rpmChanged();
    void tempChanged();
    void loadChanged();
    void mafChanged();
    void throttleChanged();
    void connectingChanged();

private slots:
    void readSocket();
    void connected();
    void disconnected();
    void onSocketErrorOccurred(QBluetoothSocket::SocketError);

private:
    QBluetoothLocalDevice *localDevice_ = nullptr;
    QBluetoothSocket *socket_ = nullptr;

    QString connection_ = "CONNECT";
    QString speed_ = "0";
    QString rpm_ = "0";
    QString temp_ = "0";
    QString load_ = "0";
    QString maf_ = "0";
    QString throttle_ = "0";
    bool connecting_ = false;
};

#endif // BTCONNECTION_HH
