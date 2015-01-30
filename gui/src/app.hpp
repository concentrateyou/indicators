#ifndef APP_H
#define APP_H 1

#include <QMap>
#include "user.hpp"

typedef QMap<int,User> UsersGroup;

class App : public QObject {
    Q_OBJECT
    Q_PROPERTY( UsersGroup users READ getUsers NOTIFY changed)
private:
	QMap<int,User> users_;
public:
	const QMap<int,User>& getUsers() const;
public slots:
	void init();
	void load(QString filename);
	void save(QString filename);
	void addName(QString name);
signals:
    void changed();
};

#endif
