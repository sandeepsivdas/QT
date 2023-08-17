#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <QPalette>
#include <iostream>
#include <string.h>
#include <QtGlobal>
#include <QCoreApplication>
#include <QFile>
#include <QIODevice>
#include <QTextStream>
#include <QDebug>
#include <some_class.h>

#include <QQmlContext>
#include <QApplication>
#include "some_class.h"
#include <iostream>
#include <list>
#include <QQuickView>
#include <QTimer>

#include <QtCharts/QVXYModelMapper>
#include <cmath>
#include "mydatamodel.h"

using namespace std;


int main(int argc, char *argv[])
{
    QCoreApplication::setAttribute(Qt::AA_EnableHighDpiScaling);

    QApplication app(argc, argv);
    some_class testClass;
    MyDataModel myDataModel;

    QQmlApplicationEngine engine;
    auto context = engine.rootContext();

    engine.load(QUrl(QStringLiteral("qrc:/main.qml")));
    QQmlContext*rootContext = engine.rootContext();
    rootContext->setContextProperty("dataModel", &myDataModel);
    context->setContextProperty("classA",&testClass);

    int i = 0;

    QTimer *timer = new QTimer();

    QObject::connect(timer, &QTimer::timeout, &myDataModel, [&i, &myDataModel]() {
        double y = arr[0];
        qDebug() << y;
        myDataModel.addData(QPointF(i++, y));

    });

    timer->start(10);

    return app.exec();
}
