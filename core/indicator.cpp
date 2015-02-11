#include "indicator.hpp"
using namespace core;

Indicator::Indicator(){
	id = 0;
}

Indicator::Indicator(const Indicator &i){
	id = i.id;
	name = i.name;
	value = i.value;
	this->childs = i.childs;
}
Indicator::Indicator(QString n, double v):name(n),value(v){}

Indicator& Indicator::operator=(const Indicator &i){
	id = i.id;
	name = i.name;
	value = i.value;
	this->childs = i.childs;
	return *(this);
}
void Indicator::setValue(double value){
	this->value = value;
	emit valueChanged();
}
void Indicator::setName(QString name){
	this->name = name;
	emit nameChanged();

}
const QString& Indicator::getName() const{
	return name;
}
double Indicator::getValue() const{
	return value;
}
void Indicator::addChild(int idChild){
	childs.push_back(idChild);
	emit childsChanged();
}
const QVector<int>& Indicator::getChilds() const{
	return childs;
}
int Indicator::getChild(int index) const{
	for (int i = 0; i < childs.size(); ++i)
	{
		if(index == childs[i])
			return childs[i];
	}
	return -1;
		
}
int Indicator::getId() const{
	return id;
}
bool Indicator::removeChild(int index){
	for (int i = 0; i < childs.size(); ++i)
	{
		if(index == childs[i]){
			childs.remove(i);
			return true;
		}
	}
	return false;
}
void Indicator::setId(int id){
	this->id = id;
}
void Indicator::setChilds(QVector<int>& childs){
	this->childs = childs;
}
QDataStream& core::operator>>(QDataStream& in, Indicator& i){
	QString name;
	double value;
	QVector<int> childs;
	int child;
	int id;
	in >> id;
	i.setId(id);
	in >> name;
	i.setName(name);
	in >> value;
	i.setValue(value);
	in >> childs;
	i.setChilds(childs);
	return in;
}
QDataStream& core::operator<<(QDataStream& out, Indicator& i){
	out << i.getId();
	out << i.getName();
	out << i.getValue();
	out << i.getChilds();
	return out;
}

QList<int> Indicator::getChildsForQML(){
	return childs.toList();
}
void Indicator::removeAllChilds(){
	childs.clear();
}
