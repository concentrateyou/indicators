#include "user.hpp"

User::User(){
	User::count_ ++;
	id_ = User::count_;
}
User::User(const QString& name) : name_(name) {
	User::count_ ++;
	id_ = User::count_;
}
User::User(const User& u) : id_(u.id_), name_(u.name_) {}
User& User::operator=(const User& u){
	id_ = u.id_;
	name_ = u.name_;
	return *this;
}

const QString& User::getName() const {
	return name_;
}
void User::setName(const QString& name){
	if(name_ != name){
		name_ = name;
		emit nameChanged();		
	}
}
int User::getId() const {
	return id_;
}
int User::count_ = 0;

QDataStream& operator>>(QDataStream& in, User& user){
	QString name;
	in >> name;
	user.setName(name);
	return in;
}

QDataStream& operator<<(QDataStream& out, const User& user){
	out << user.getName();
	return out;
}