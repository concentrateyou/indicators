#include <QApplication>
#include <QQmlApplicationEngine>
#include <QtQml>

#include <QtDebug>

#include <QMap>
#include "app.hpp"

int main(int argc, char** argv){
	// QApplication app(argc, argv);
 //    QQmlApplicationEngine engine;
 //    // qmlRegisterType<User>("wn.qt", 1, 0, "UserData");
 //    engine.load(QUrl(QStringLiteral("qrc:/main.qml")));
 //    return app.exec();
    App a;
    a.load("data.wnb");
    foreach(User u, a.getUsers()){
    	qDebug() << u.getId() << ": " << u.getName() << endl;
    }
}