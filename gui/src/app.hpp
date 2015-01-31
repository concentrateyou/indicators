#ifndef APP_H
#define APP_H 1

#include <QMap>
#include <QDebug>
#include <QList>
#include <QQmlListProperty>
#include "user.hpp"

class App : public QObject {
    Q_OBJECT
    Q_PROPERTY(QList<QObject*> users READ getUsersForQML NOTIFY changed)
private:
	QMap<int,User> users_;
public:
	const QMap<int,User>& getUsers() const;
	QList<QObject*> getUsersForQML() {
		QList<QObject*> list;
		QMap<int,User>::iterator it = users_.begin();
		while(it != users_.end()){
			User& r = *it;
			User* p = &r;
			list.append(p);
			++ it;
		}
		return list;
	}
	void show(){
		qDebug() << "Data:";
		foreach(int i, users_.keys()){
			qDebug() << i << ": {" << users_[i].getId() << ", " << users_[i].getName() << "}";
		}
	}
public slots:
	void init();
	void load(QString filename);
	void save(QString filename);
	void addName(QString name);
	void removeName(int id);
signals:
    void changed();
};

#endif
