#include "value.hpp"
using namespace core;
int Value::count = 0;
Value::Value(){
	Value::count ++;
	id = Value::count;
	parentId = 0;
	value = 0.0;
	weigth = 0.0;
}
Value::Value(QString name, int parentId, double weigth, double value){
	Value::count ++;
	id = Value::count;
	this->name = name;	
	this->parentId = parentId;
	this->weigth = weigth;
	this->value = value;
}
Value::Value(const Value &v){
	this->id = v.id;
	this->name = v.name;	
	this->parentId = v.parentId;
	this->weigth = v.weigth;
	this->value = v.value;
}
Value& Value::operator=(const Value &v){
	this->id = v.id;
	this->name = v.name;	
	this->parentId = v.parentId;
	this->weigth = v.weigth;
	this->value = v.value;
	return *(this);
}
int Value::getParentId() const{
	return parentId;
}
double Value::getWeight() const{
	return weigth;
}
double Value::getValue() const{
	return value;
}
const QString& Value::getName() const{
	return name;
}
void Value::setParentId(int parentId){
	this->parentId = parentId;
	emit parentIdChanged();
}
void Value::setValue(double value){
	this->value = value;
	emit valueChanged();
}
void Value::setWeight(double weigth){
	this->weigth = weigth;
	emit weightChanged();
}
void Value::setName(QString name){
	this->name = name;
	emit nameChanged();
}
void Value::setId(int id){
	this->id = id;
	if(Value::count < id)
		Value::count = id;
}