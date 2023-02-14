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

public:
    explicit BtConnection(QObject *parent = 0);
    ~BtConnection();
    QString getConnection();
    QString getData();

public slots:
    void connectDevice();
    void disconnectDevice();

signals:
    void connectionChanged();
    void dataChanged();

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
};

#endif // BTCONNECTION_HH
