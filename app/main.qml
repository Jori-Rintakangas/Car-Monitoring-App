import QtQuick
import QtQuick.Layouts
import QtQuick.Controls
import QtQuick.Controls.Material 2.12
import Qt.labs.settings

ApplicationWindow {
    id: window
    width: 360
    height: 520
    visible: true
    title: "Car Monitoring"

    header: ToolBar {
        Material.background: "#2da968"

        Image {
            source: "qrc:/icons/car.png"
            anchors.left: parent.left
            anchors.leftMargin: 5
            anchors.verticalCenter: parent.verticalCenter
        }

        Image {
            source: btConnection.connection_ === "CONNECT" ? "qrc:/icons/btdisconnected.png" : "qrc:/icons/btconnected.png"
            anchors.left: parent.left
            anchors.leftMargin: 25
            anchors.verticalCenter: parent.verticalCenter
        }

        RowLayout {
            spacing: 20
            anchors.fill: parent

            Label {
                id: titleLabel
                text: "Car Monitoring"
                font.pixelSize: 20
                elide: Label.ElideRight
                horizontalAlignment: Qt.AlignHCenter
                verticalAlignment: Qt.AlignVCenter
                Layout.fillWidth: true
            }
        }
    }

    StackView {
        id: stackView
        anchors.fill: parent

        initialItem: Pane {
            id: pane
            Material.background: "#143455"

            Button {
                id: btButton
                text: btConnection.connection_
                Material.background: "#2da968"
                anchors.horizontalCenter: parent.horizontalCenter
                anchors.verticalCenter: parent.verticalCenter
                anchors.verticalCenterOffset: 240
                enabled: !btConnection.connecting_
                onClicked: {
                    if (btConnection.connection_ === "CONNECT")
                    {
                        btConnection.connectDevice()
                    }
                    else
                    {
                        btConnection.disconnectDevice()
                    }
                }
                Label {
                    anchors.horizontalCenter: parent.horizontalCenter
                    anchors.verticalCenter: parent.bottom
                    anchors.verticalCenterOffset: 4
                    text: "connecting..."
                    visible: btConnection.connecting_
                }
            }

            Label {
                anchors.horizontalCenter: parent.horizontalCenter
                anchors.verticalCenter: parent.bottom
                anchors.verticalCenterOffset: 4
                text: "Icons from <a href=\"https://icons8.com\">Icons8</a>"
                font.pixelSize: 10
                font.italic: true
                color: "#2da968"
                linkColor: "#2da968"
                onLinkActivated: Qt.openUrlExternally("https://icons8.com")
            }

            Grid {
                anchors.horizontalCenter: parent.horizontalCenter
                anchors.verticalCenter: parent.verticalCenter
                columns: 2
                spacing: 20

                Pane {
                    width: 140
                    height: 120
                    Material.elevation: 10
                    Material.background: "#2da968"

                    Image {
                        source: "qrc:/icons/speed.png"
                        anchors.centerIn: parent
                    }
                    Label {
                        text: btConnection.speed_ + " KM/H"
                        font.pixelSize: 16
                        font.italic: true
                        font.bold: true
                        anchors.bottom: parent.bottom
                        anchors.horizontalCenter: parent.horizontalCenter

                    }
                }

                Pane {
                    width: 140
                    height: 120
                    Material.elevation: 10
                    Material.background: "#2da968"

                    Image {
                        source: "qrc:/icons/rpm.png"
                        anchors.centerIn: parent
                    }
                    Label {
                        text: btConnection.rpm_ + " RPM"
                        font.pixelSize: 16
                        font.italic: true
                        font.bold: true
                        anchors.bottom: parent.bottom
                        anchors.horizontalCenter: parent.horizontalCenter

                    }
                }

                Pane {
                    width: 140
                    height: 120
                    Material.elevation: 10
                    Material.background: "#2da968"

                    Image {
                        source: "qrc:/icons/coolant.png"
                        anchors.centerIn: parent
                    }
                    Label {
                        text: btConnection.temp_ + " °C"
                        font.pixelSize: 16
                        font.italic: true
                        font.bold: true
                        anchors.bottom: parent.bottom
                        anchors.horizontalCenter: parent.horizontalCenter

                    }
                }

                Pane {
                    width: 140
                    height: 120
                    Material.elevation: 10
                    Material.background: "#2da968"

                    Image {
                        source: "qrc:/icons/engine.png"
                        anchors.centerIn: parent
                    }
                    Label {
                        text: btConnection.load_ + " %"
                        font.pixelSize: 16
                        font.italic: true
                        font.bold: true
                        anchors.bottom: parent.bottom
                        anchors.horizontalCenter: parent.horizontalCenter

                    }
                }

                Pane {
                    width: 140
                    height: 120
                    Material.elevation: 10
                    Material.background: "#2da968"

                    Image {
                        source: "qrc:/icons/maf.png"
                        anchors.centerIn: parent
                    }
                    Label {
                        text: btConnection.maf_ + " g/s"
                        font.pixelSize: 16
                        font.italic: true
                        font.bold: true
                        anchors.bottom: parent.bottom
                        anchors.horizontalCenter: parent.horizontalCenter

                    }
                }

                Pane {
                    width: 140
                    height: 120
                    Material.elevation: 10
                    Material.background: "#2da968"

                    Image {
                        source: "qrc:/icons/pedal.png"
                        anchors.centerIn: parent
                    }
                    Label {
                        text: btConnection.throttle_ + " %"
                        font.pixelSize: 16
                        font.italic: true
                        font.bold: true
                        anchors.bottom: parent.bottom
                        anchors.horizontalCenter: parent.horizontalCenter

                    }
                }

            }

        }
    }
}
