#include <QApplication>
#include <QQmlApplicationEngine>
#include <QtQml>

#include <QtDebug>

#include <QMap>
#include "app.hpp"

int main(int argc, char** argv){
	qRegisterMetaType<User>("User");

	QApplication app(argc, argv);
    QQmlApplicationEngine engine;
    
    qmlRegisterType<User>("Indicators.Models", 1, 0, "User");
    qmlRegisterType<App>("Indicators.Models", 1, 0, "App");
    
    engine.load(QUrl(QStringLiteral("qrc:/main.qml")));
    
    return app.exec();
}