#include <QApplication>
#include <QQmlApplicationEngine>
#include <QtQml>
#include <QtDebug>

#include <application.hpp>
using namespace core;

int main(int argc, char** argv){
	// qRegisterMetaType<User>("User");

	QApplication app(argc, argv);
    QQmlApplicationEngine engine;
    
    qmlRegisterType<Application>("Indicators.Models", 1, 0, "App");
    
    engine.load(QUrl(QStringLiteral("qrc:/main.qml")));

    return app.exec();
}