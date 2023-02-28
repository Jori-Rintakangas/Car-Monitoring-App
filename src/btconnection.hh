#ifndef BTCONNECTION_HH
#define BTCONNECTION_HH

#include <QBluetoothLocalDevice>
#include <QBluetoothSocket>
#include <QDebug>
#include <QObject>

const QString UUID = "";
const QString DEVICE_MAC = "";

class BtConnection : public QObject
{
    Q_OBJECT
    Q_PROPERTY(QString connection_ READ getConnection NOTIFY connectionChanged)
    Q_PROPERTY(QString data_ READ getData NOTIFY dataChanged)
    Q_PROPERTY(bool connecting_ READ getConnecting NOTIFY connectingChanged)

public:
    explicit BtConnection(QObject *parent = 0);
    ~BtConnection();
    QString getConnection();
    QString getData();
    bool getConnecting();

public slots:
    void connectDevice();
    void disconnectDevice();

signals:
    void connectionChanged();
    void dataChanged();
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
    QString data_ = "0";
    bool connecting_ = false;
};

#endif // BTCONNECTION_HH
