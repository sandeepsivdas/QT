import QtQuick 2.9
import QtQuick.Window 2.2
import QtQuick.Controls 1.4
import QtCharts 2.2

Item {
    id:child2
    property int timeStep
    Rectangle{
            width: 800; height: 480
            color: "white"
            visible: true
        ChartView {
            id: chartView
            anchors.fill: parent
            ValueAxis {
                id: axisXdata
                min:dataModel.xMin
                max:dataModel.xMax
            }
            ValueAxis {
                id: axisYdata
                min: 0
                max: 1
            }
            LineSeries {
                id:  dataLineSeries
                name: "Angle"
                axisX: axisXdata
                axisY: axisYdata
                useOpenGL: true
            }
            VXYModelMapper {
                id:  dataModelMapper
                model: dataModel
                series: dataLineSeries
                firstRow: 0
                xColumn: 0
                yColumn: 1
            }
        }
            MouseArea{
                anchors.fill: parent
                onClicked: {
                    mytime.restart()
                }
            }

        Timer{
            id:mytime
            interval: 100
            repeat: true
            running: true
            onTriggered: {
                classA.callMe()
                classA.readtext()
            }

        }
  }
}
