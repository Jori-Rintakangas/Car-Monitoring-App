#include "btconnection.hh"

BtConnection::BtConnection(QObject *parent) : QObject(parent)
{
    discoveryAgent_ = new QBluetoothDeviceDiscoveryAgent();
    QBluetoothDeviceDiscoveryAgent::connect(discoveryAgent_, SIGNAL(deviceDiscovered(QBluetoothDeviceInfo)),
            this, SLOT(deviceDiscovered(QBluetoothDeviceInfo)));
}

BtConnection::~BtConnection()
{
    delete discoveryAgent_;
}

void BtConnection::startDeviceDiscovery()
{
    discoveryAgent_->start(QBluetoothDeviceDiscoveryAgent::ClassicMethod);
    qDebug() << "Started";
}

void BtConnection::stopDeviceDiscovery()
{
    discoveryAgent_->stop();
    qDebug() << "Stopped";
}

void BtConnection::deviceDiscovered(const QBluetoothDeviceInfo &device)
{
    qDebug() << "Found new device:" << device.name() << '(' << device.address().toString() << ')';
}
