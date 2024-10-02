import QtQuick 2.15
import QtQuick.Window 2.15
import QtQuick.Controls 2.15
import DICE_TEST 1.0
import Theme 1.0

Window {
    id: window
    visible: true
    width: 640
    height: 400
    title: qsTr("tr_Sensor_List")
    color: Theme.background

    Rectangle {
        anchors.fill: parent
        color: Theme.background

        Timer {
            interval: 1000  // 1 seconde
            running: true  // Démarre automatiquement
            repeat: true  // Se répète indéfiniment

            onTriggered: {
                  sensorModel.updateDatas(); // Appeler la méthode Test
            }
        }

        ListView {
            anchors{
                top: parent.top
                bottom: parent.bottom
                left: parent.left
                right: parent.right
                margins: 50
            }
            model: sensorModel
            spacing: Theme.spacing

            delegate: Rectangle {
                anchors{
                    left: parent.left
                    right: parent.right
                }

                height: 50
                color:  Theme.region

                Rectangle {
                    MouseArea {
                        anchors.fill: parent
                        cursorShape: Qt.PointingHandCursor
                        hoverEnabled: true
                        onEntered: parent.hovered = true
                        onExited: parent.hovered = false
                    }
                    property bool hovered: false

                    anchors {
                        left: parent.left
                        verticalCenter: parent.verticalCenter
                        margins: Theme.marging
                    }

                    width: 16
                    height: 16
                    radius: 8
                    color: getStateColor(model.stateType)
                    ToolTip.visible: hovered
                    ToolTip.text: getStateText(model.stateType)
                }

                Text {
                    anchors.centerIn: parent
                    text: "[" + getSensorTypeText(model.sensorType) + "]" + " - " + model.name
                    color: Theme.foreground
                }

                Text {
                    anchors {
                        right: parent.right
                        verticalCenter: parent.verticalCenter
                        margins: Theme.marging
                    }
                    text: model.signalStrength + " %"
                    color: Theme.foreground
                }
            }
        }
    }

    function getStateColor(stateType) {
        switch (stateType) {
            case Enums.StateType_Nominal:
                return "lightgreen";
            case Enums.StateType_Warning:
                return "#FFD580";
            case Enums.StateType_Error:
            default:
                return "#FF7F7F";
        }
    }

    function getStateText(stateType) {
        switch (stateType) {
            case Enums.StateType_Nominal:
                return qsTr("tr_Nominal");
            case Enums.StateType_Warning:
                return qsTr("tr_Warning");
            case Enums.StateType_Error:
                return qsTr("tr_Error");
            default:
                return "";
        }
    }

    function getSensorTypeText(sensorType) {
        switch (sensorType) {
             case Enums.SensorType_Anemometer:
                 return qsTr("tr_Anemometer");
             case Enums.SensorType_Compass:
                 return qsTr("tr_Compass");
             case Enums.SensorType_GPS:
                 return qsTr("tr_GPS");
             case Enums.SensorType_Gyro:
                 return qsTr("tr_Gyro");
            default:
                return "";
        }
    }
}
