#include "btconnection.hh"

BtConnection::BtConnection(QObject *parent) : QObject(parent)
{
    discoveryAgent_ = new QBluetoothDeviceDiscoveryAgent();
    localDevice_ = new QBluetoothLocalDevice();
    QBluetoothDeviceDiscoveryAgent::connect(discoveryAgent_, SIGNAL(deviceDiscovered(QBluetoothDeviceInfo)),
                                                       this, SLOT(deviceDiscovered(QBluetoothDeviceInfo)));

    QBluetoothDeviceDiscoveryAgent::connect(discoveryAgent_, SIGNAL(finished()),
                                                       this, SLOT(stopDeviceDiscovery()));

    QBluetoothLocalDevice::connect(localDevice_, SIGNAL(deviceConnected(QBluetoothAddress)),
                                                       this, SLOT(deviceConnected()));

    QBluetoothLocalDevice::connect(localDevice_, SIGNAL(deviceDisconnected(QBluetoothAddress)),
                                                       this, SLOT(deviceDisconnected()));

}

QString BtConnection::getConnection()
{
    return connection_;
}

BtConnection::~BtConnection()
{
    delete discoveryAgent_;
}

void BtConnection::startDeviceDiscovery()
{
    localDevice_->powerOn();
    while (localDevice_->hostMode() == QBluetoothLocalDevice::HostPoweredOff)
    {
        qDebug() << "Waiting for bluetooth to turn on";
    }
    discoveryAgent_->start(QBluetoothDeviceDiscoveryAgent::ClassicMethod);
    qDebug() << "Started bt device discovery";
}

void BtConnection::stopDeviceDiscovery()
{
    discoveryAgent_->stop();
    qDebug() << "Stopped bt device discovery";
}

void BtConnection::disconnectDevice()
{
    QBluetoothAddress address(deviceAddress_);
    localDevice_->requestPairing(address, QBluetoothLocalDevice::Unpaired);
}

void BtConnection::deviceConnected()
{
    qDebug() << "Connected to bt device";
    connection_ = "DISCONNECT";
    emit connectionChanged();
}

void BtConnection::deviceDisconnected()
{
    qDebug() << "Disconnected from bt device";
    connection_ = "CONNECT";
    emit connectionChanged();
}

void BtConnection::deviceDiscovered(const QBluetoothDeviceInfo &device)
{
    qDebug() << "Found new device:" << device.name() << '(' << device.address().toString() << ')';
    if (device.address().toString() == deviceAddress_)
    {
        stopDeviceDiscovery();
        QBluetoothAddress address(deviceAddress_);
        localDevice_->requestPairing(address, QBluetoothLocalDevice::Paired);
    }

}
