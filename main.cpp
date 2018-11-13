#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include"mygps.h"
#include"apinet.h"
int main(int argc, char *argv[])
{
    QCoreApplication::setAttribute(Qt::AA_EnableHighDpiScaling);
    QGuiApplication app(argc, argv);

    QQmlApplicationEngine engine;
    qmlRegisterType<MyGPS>("qiuyuhan.org.MyGps",1,0,"MyGps");
    qmlRegisterType<APINet>("qiuyuhan.org.ApiNet",1,0,"ApiNet");
    engine.load(QUrl(QLatin1String("qrc:/main.qml")));

    return app.exec();
}
