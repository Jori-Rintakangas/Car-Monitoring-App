#include "btconnection.hh"

BtConnection::BtConnection(QObject *parent) : QObject(parent)
{
    localDevice_ = new QBluetoothLocalDevice();
    localDevice_->powerOn();

    socket_ = new QBluetoothSocket(QBluetoothServiceInfo::RfcommProtocol);
    connect(socket_, &QBluetoothSocket::readyRead, this, &BtConnection::readSocket);
    connect(socket_, &QBluetoothSocket::connected, this, &BtConnection::connected);
    connect(socket_, &QBluetoothSocket::disconnected, this, &BtConnection::disconnected);
    connect(socket_, &QBluetoothSocket::errorOccurred, this, &BtConnection::onSocketErrorOccurred);
}

BtConnection::~BtConnection()
{
    delete socket_;
    delete localDevice_;
}

QString BtConnection::getConnection()
{
    return connection_;
}

QString BtConnection::getSpeed()
{
    return speed_;
}

QString BtConnection::getRpm()
{
    return rpm_;
}

QString BtConnection::getTemp()
{
    return temp_;
}

QString BtConnection::getLoad()
{
    return load_;
}

QString BtConnection::getMaf()
{
    return maf_;
}

QString BtConnection::getThrottle()
{
    return throttle_;
}

bool BtConnection::getConnecting()
{
    return connecting_;
}

void BtConnection::connectDevice()
{
    connecting_ = true;
    emit connectingChanged();
    localDevice_->powerOn();
    while (localDevice_->hostMode() == QBluetoothLocalDevice::HostPoweredOff);
    socket_->connectToService(QBluetoothAddress(DEVICE_MAC), QBluetoothUuid(UUID));
}

void BtConnection::disconnectDevice()
{
    socket_->disconnectFromService();
}

void BtConnection::readSocket()
{
    if (!socket_)
        return;

    while (socket_->canReadLine())
    {
        QByteArray line = socket_->readLine().trimmed();
        QString newData = QString::fromUtf8(line.constData(), line.length());
        QChar end = newData.at(line.length() - 1);
        newData.chop(1);
        if (end == 'S' && newData != speed_)
        {
            speed_ = newData;
            emit speedChanged();
        }
        else if (end == 'R' && newData != rpm_)
        {
            rpm_ = newData;
            emit rpmChanged();
        }
        else if (end == 'T' && newData != temp_)
        {
            temp_ = newData;
            emit tempChanged();
        }
        else if (end == 'L' && newData != load_)
        {
            load_ = newData;
            emit loadChanged();
        }
        else if (end == 'M' && newData != maf_)
        {
            maf_ = newData;
            emit mafChanged();
        }
        else if (end == 'P' && newData != throttle_)
        {
            throttle_ = newData;
            emit throttleChanged();
        }
    }
}

void BtConnection::connected()
{
    qDebug() << "Connected to bt device";
    connection_ = "DISCONNECT";
    connecting_ = false;
    emit connectingChanged();
    emit connectionChanged();
}

void BtConnection::disconnected()
{
    qDebug() << "Disconnected from bt device";
    connection_ = "CONNECT";
    connecting_ = false;
    emit connectingChanged();
    emit connectionChanged();
}

void BtConnection::onSocketErrorOccurred(QBluetoothSocket::SocketError)
{
    qDebug() << "Socket error";
    connecting_ = false;
    emit connectingChanged();
}
