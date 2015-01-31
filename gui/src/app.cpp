#include "app.hpp"
#include <QFile>
#include <QDataStream>

void App::init(){
	users_.clear();
	qDebug() << "App initialized !";
}
void App::load(QString filename){
	QFile binaryFile(filename);
	QDataStream data(&binaryFile);
	binaryFile.open(QFile::ReadOnly);
	data >> users_;
	binaryFile.close();
	show();
	emit changed();
}
void App::save(QString filename){
	QFile binaryFile(filename);
	QDataStream data(&binaryFile);
	binaryFile.open(QFile::WriteOnly);
	data << users_;
	binaryFile.close();
}
void App::addName(QString name){
	User u(name);
	users_.insert(u.getId(), u);
	emit changed();
	show();
}

void App::removeName(int id){
	qDebug() << "Removing " << id;
	users_.erase(users_.find(id));
	emit changed();
	show();
}
const QMap<int,User>& App::getUsers() const {
	return users_;
}