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

        ToolButton {
            id: toolButton
            anchors.left: parent.left
            text: qsTr("<")
            onClicked: btConnection.startDeviceDiscovery()
        }

        ToolButton {
            id: toolButton2
            anchors.right: parent.right
            text: qsTr(">")
            onClicked: btConnection.stopDeviceDiscovery()
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
                        text: "0 KM/H"
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
                        text: "0 RPM"
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
                        text: "0 °C"
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
                        text: "0 %"
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
                        text: "0 g/s"
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
                        text: "0 %"
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
