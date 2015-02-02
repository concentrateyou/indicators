#include "application.hpp"
#include <QFile>
#include <QDataStream>
#include <QDebug>
using namespace core;
void Application::init(){
	qDebug() << "init called !";
	indexes.clear();
	moduls.clear();
}
void Application::create(QString name){
	indicator.setId(0);
	indicator.setName(name);
	// a calculer
	indicator.setValue(10.0);
	emit changed();
}
void Application::load(QString fileName){
	QFile binaryFile(fileName);
	QDataStream data(&binaryFile);
	binaryFile.open(QFile::ReadOnly);
	data >> indicator;
	data >> indexes;
	data >> moduls;
	binaryFile.close();
	emit changed(); 
}
void Application::save(QString fileName){
	qDebug() << "Saving on : " << fileName;
	QFile binaryFile(fileName);
	QDataStream data(&binaryFile);
	binaryFile.open(QFile::WriteOnly);
	data << indicator;
	data << indexes;
	data << moduls;
	binaryFile.close();
}
/*
void Application::export(QString fileName){
	//TO DO
}
void Application::import(QString fileName){
	//TO DO
}
*/

void Application::addIndex(QString name, int parentId, double weight, double value, double borneFav, double borneUnfav){
	Index index(name, parentId, weight, value, borneFav, borneUnfav);
	indexes.insert(index.getId(), index);
	if(indicator.getId() == parentId){
		indicator.addChild(index.getId());
	}else{
		Module& module = moduls[parentId];
		module.addChild(index.getId());
	}
	emit changed();

}
bool Application::removeIndex(int id){
	bool result;
	if(indicator.getChild(id) != -1){
		if(indexes.remove(id) != 0)
			if(indicator.removeChild(id) == true)
				result = true;
			else
				result = false;
		else
			result = false;
	} else
		result = false;

	if(result)
		emit changed();
	return result;
}
void Application::editIndex(int id, QString name, double weight, double value, double borneFav, double borneUnfav){
	if(indexes.contains(id)){
		Index& index = indexes[id];
		index.setName(name);
		index.setWeight(weight);
		index.setValue(value);
		index.setBorneFav(borneFav);
		index.setBorneUnfav(borneUnfav);
		emit changed();
	}
}

void Application::addModule(QString name, int parentId, double weight, double value){
	Module module(name, parentId, weight, value);
	moduls.insert(module.getId(), module);
	if(indicator.getId() == parentId){
		indicator.addChild(module.getId());
	}else{
		Module& module2 = moduls[parentId];
		module2.addChild(module.getId());
	}
	emit changed();
}
bool Application::removeModule(int id){
	if(indicator.getChild(id) != -1){
		if(moduls.remove(id) != 0){
			if(indicator.removeChild(id) == true)
				return true;
			else
				return false;

		}else{
			return false;
		}
	}else
		return false;
}
void Application::editModule(int id, QString name, double weight){
	if(moduls.contains(id)){
		Module& module = moduls[id];
		module.setName(name);
		module.setWeight(weight);
		emit changed();
	}
}
const QMap<int, Module>& Application::getModuls() const{
	return moduls;
}
const QMap<int, Index>& Application::getIndexes() const{
	return indexes;
}
const Indicator& Application::getIndicator() const{
	return indicator;
}
QList<QObject*> Application::getIndexesForQML() {
	QList<QObject*> list;
	QMap<int, Index>::iterator it = indexes.begin();
	while(it != indexes.end()){
		Index& rindex = *it;
		Index* pindex = &rindex;
		list.append(pindex);
		++ it;
	}
	qDebug() << "The size of indexes is : " << list.size();
	return list;
}
QList<QObject*> Application::getModulsForQML() {
	QList<QObject*> list;
	QMap<int, Module>::iterator it = moduls.begin();
	while(it != moduls.end()){
		Module& rmodule = *it;
		Module* pmodule = &rmodule;
		list.append(pmodule);
		++ it;
	}
	return list;
}

QObject* Application::getIndicatorForQML() {
	return &indicator;
}
