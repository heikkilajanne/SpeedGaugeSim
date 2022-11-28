import QtQuick 2.15
import QtQuick.Window 2.15
import io.qt.examples.backend 1.0

Window {
    width: 520
    height: 520
    visible: true
    title: qsTr("Hello World")

//    Reader{
//        id: reader
//    }

    Image {
        anchors.left: parent.left
        anchors.bottom: parent.bottom
        anchors.margins: 10
        source: "assets/Speed Gauge PNG.png"
        rotation: 0

        Image {
            id: needle
            anchors.horizontalCenter: parent.horizontalCenter
            anchors.verticalCenter: parent.verticalCenter
            rotation: 225
            //anchors.left: parent.left
            //anchors.bottom: parent.bottom
            //anchors.margins: 10
            source: "assets/Needle.png"
        }
        Image {
            anchors.horizontalCenter: parent.horizontalCenter
            anchors.verticalCenter: parent.verticalCenter
            //anchors.left: parent.left
            //anchors.bottom: parent.bottom
            //anchors.margins: 10
            source: "assets/TopCircle.png"
            rotation: 0
        }

        Text {
            id: speedDigital
            text: qsTr("0")
            color: ("#FFFFFF")
            font.pointSize: 40
            anchors.horizontalCenter: parent.horizontalCenter
            anchors.verticalCenter: parent.verticalCenter

        }
    }

}

