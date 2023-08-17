import QtQuick 2.9
import QtQuick.Window 2.2
import QtCharts 2.0
import QtQuick.Controls 1.4

ApplicationWindow {
    id: mainWindow
    visible: true
    width: 800
    height: 480
    title: qsTr("Hello World")
    visibility: Window.FullScreen
    color:"black"

    StackView{
        id:stackView
        anchors.fill:parent
    }
    MenuX {
        id: cl
        width: 800
        height: 480
        collapsedHeight: mainWindow.height * 0.1
        FontLoader{
            id:fixedfont
            name:"Uroob"
        }
     MenuItemX {
                id:forth
                color: "#18A0FA"
                collapsed: cl.collapsed
                index: 3
                title: "Sine Wave"
                icon: "qrc:/images/auto@2x.png"
                font.family: fixedfont.name
            }
    }
}

