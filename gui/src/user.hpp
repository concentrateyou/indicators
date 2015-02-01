#ifndef USER_H
#define USER_H 1

#include <QString>
#include <QObject>
#include <QDataStream>

class User : public QObject {
    Q_OBJECT
    Q_PROPERTY(int num READ getId)
    Q_PROPERTY(QString name READ getName WRITE setName NOTIFY nameChanged)
private:
	static int count_;
	int id_;
	QString name_;
public:
	explicit User(QObject *parent = 0);
	User(const QString& name);
	User(const User&);
	User& operator=(const User&);
	const QString& getName() const;
	void setName(const QString& name );
	int getId() const;
	void setId(int id) { 
		id_ = id;
		if(User::count_ < id)
			User::count_ = id;
	};
signals:
	void nameChanged();
};

QDataStream& operator>>(QDataStream& in, User& user);
QDataStream& operator<<(QDataStream& out, const User& user);

Q_DECLARE_METATYPE(User)

#endif