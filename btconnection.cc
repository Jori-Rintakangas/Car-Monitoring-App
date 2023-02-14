#include "btconnection.hh"

BtConnection::BtConnection(QObject *parent) : QObject(parent)
{
    localDevice_ = new QBluetoothLocalDevice();
    localDevice_->powerOn();
}

BtConnection::~BtConnection()
{
    delete socket_;
}

QString BtConnection::getConnection()
{
    return connection_;
}

QString BtConnection::getData()
{
    return data_;
}

void BtConnection::connectDevice()
{
    socket_ = new QBluetoothSocket(QBluetoothServiceInfo::RfcommProtocol);
    socket_->connectToService(QBluetoothAddress(DEVICE_MAC), QBluetoothUuid(UUID));

    connect(socket_, &QBluetoothSocket::readyRead, this, &BtConnection::readSocket);
    connect(socket_, &QBluetoothSocket::connected, this, &BtConnection::connected);
    connect(socket_, &QBluetoothSocket::disconnected, this, &BtConnection::disconnected);
    connect(socket_, &QBluetoothSocket::errorOccurred, this, &BtConnection::onSocketErrorOccurred);
    qDebug() << "Created socket";
}

void BtConnection::disconnectDevice()
{
    socket_->disconnectFromService();
}

void BtConnection::readSocket()
{
    if (!socket_)
        return;

    while (socket_->canReadLine()) {
        QByteArray line = socket_->readLine().trimmed();
        QString newData = QString::fromUtf8(line.constData(), line.length());
        qDebug() << newData;
        if (newData != data_)
        {
            data_ = newData;
            emit dataChanged();
        }
    }
}

void BtConnection::connected()
{
    qDebug() << "Connected to bt device";
    connection_ = "DISCONNECT";
    emit connectionChanged();
}

void BtConnection::disconnected()
{
    qDebug() << "Disconnected from bt device";
    connection_ = "CONNECT";
    delete socket_;
    emit connectionChanged();
}

void BtConnection::onSocketErrorOccurred(QBluetoothSocket::SocketError)
{
    qDebug() << "Socket error";
}
