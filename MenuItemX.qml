import QtQuick 2.0
import QtGraphicalEffects 1.0
import QtQuick.Controls 1.4



Item {

    // ----- Public Properties ----- //

    property bool selected: false
    property bool collapsed: false
    property alias icon: imgIcon.source


    property alias title: lbTitle.text
    property alias color: rectShadow.color
    property int index: 0

    property alias font: lbTitle.font


    id: root
    width: parent.width
    height: _getHeight()
    z: parent.children.length - index
    //z:0
    color: "red"


    Behavior on height { NumberAnimation { duration: 50; easing.type: Easing.OutExpo } }

    DropShadow {
        anchors.fill: rectShadow
        horizontalOffset: 0
        verticalOffset: 5
        radius: root.selected ? 8.0 : 16.0
        samples: 1 + radius * 2
        color: "#80000000"
        source: rectShadow
    }

    Rectangle {
        id: rectShadow
        anchors.fill: parent

    }

    Item {
        id: container
        width: parent.width
        height: root.collapsed ? lbTitle.contentHeight : ((imgIcon.visible ? imgIcon.height : 0) + lbTitle.contentHeight)
        anchors.centerIn: parent

        Image {
            id: imgIcon
            anchors {
                top: parent.top
                horizontalCenter: parent.horizontalCenter
            }
            visible: !root.collapsed || !(status === Image.Null)
            scale: root.collapsed ? 0 : 1

            Behavior on scale { NumberAnimation { duration: 100 } }
        }

        Text {
            id: lbTitle
            anchors {
                top: root.collapsed ? parent.top : imgIcon.bottom
                horizontalCenter: parent.horizontalCenter
            }
            font.pointSize: 16
            visible: !(scale === 0)
            color: "white"
            scale: root.collapsed && !root.selected ? 0 : 1

            Behavior on scale { NumberAnimation { duration: 100 } }
        }
  }

    MouseArea {
        anchors.fill: parent
        onClicked: {
            if(index!=0){
            root.selected = !root.selected;
            root.parent.toggle();
            parent.onTrigger();
            }
        }
    }

    // ----- Private Functions ----- //

    function _getHeight() {
        if (!selected && collapsed) {
            return 0;
        }
        else if (selected && collapsed) {
            return root.parent.collapsedHeight;
        }
        return parent.height / parent.children.length;

    }

    function onTrigger() {
        if(index==3){
            stackView.push(Qt.resolvedUrl("Child_2.qml"))
        }else;
    }

}


