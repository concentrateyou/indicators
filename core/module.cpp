#include "module.hpp"
using namespace core;
Module::Module(){}
Module::Module(QString name, int parentId, double weight, double value):Value(name, parentId, weight, value){}
Module::Module(const Module &m):Value(m){
	this->childs = m.childs;
}
Module& Module::operator=(const Module &m){
	Value::operator=(m);
	this->childs = m.childs;
	return *(this); 
}
void Module::addChild(int child){
	childs.push_back(child);
	emit childsChanged();
}
bool Module::removeChild(int index){
	for (int i = 0; i < childs.size(); ++i)
	{
		if(index == childs[i]){
			childs.remove(i);
			return true;
		}
	}
	return false;
}
int Module::getChild(int index) const{
	for (int i = 0; i < childs.size(); ++i)
	{
		if(index == childs[i])
			return childs[i];
	}
	return -1;
}
const QVector<int>& Module::getChilds() const{
	return childs;
}
void Module::setChilds(QVector<int>& childs){
	this->childs = childs;
}
QDataStream& core::operator>>(QDataStream& in, Module& module){
	int id, parentId;
	QString name;
	double value, weight;
	QVector<int> childs;
	
	in >> id;
	module.setId(id);
	in >> parentId;
	module.setParentId(parentId);
	in >> name;
	module.setName(name);
	in >> value;
	module.setValue(value);
	in >> weight;
	module.setWeight(weight);
	in >> childs;
	module.setChilds(childs);
	return in;
}
QDataStream& core::operator<<(QDataStream& out, const Module& module){
	out << module.getId();
	out << module.getParentId();
	out << module.getName();
	out << module.getValue();
	out << module.getWeight();
	out << module.getChilds();
	return out;
}
