#include "indicator.hpp"
using namespace core;
Indicator::Indicator(){}

Indicator::Indicator(const Indicator &i){
	name = i.getName();
	value = i.getValue();
	for(int ii = 0; ii < childs.size(); ii++){
		childs[ii] = i.getChild(ii);
	}
}
Indicator::Indicator(QString n, double v):name(n),value(v){}

Indicator& Indicator::operator=(const Indicator &i){
	name = i.getName();
	value = i.getValue();
	for(int i = 0; i < childs.size(); i++){
		childs[i] = i.getChilds(i);
	}
	return *(this);
}
void Indicator::setValue(double){
	this->value = value;
}
void Indicator::setName(QString name){
	this->name = name;
}
QString Indicator::getName() const{
	return name;
}
double Indicator::getValue() const{
	return value;
}
void Indicator::addChild(int idChild){
	childs.push_back(idChild);
}
QVector<int>& Indicator::getChilds(){
	return childs;
}
int Indicator::getChild(int index){
	if(index >= 0 && index < childs.size())
		return childs[index]; 
}
void Indicator::removeChild(int index){
	if(index >= 0 && index < childs.size())
		childs.remove(index);
}
