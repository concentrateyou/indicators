#include "value.hpp"
int Value::id = 0;
Value::Value(){
	parentId = 0;
	value = 0.0;
	weigth = 0.0;
	id++;
}
Value::Value(QString name, int parentId, double weigth, double value){
	this->name = name;	
	this->parentId = parentId;
	this->weigth = weigth;
	this->value = value;
	id++
}
Value::Value(const Value &v){
	this->name = v.name;	
	this->parentId = v.getParentId();
	this->weigth = v.getWeight();
	this->value = v.getValue();
	id++;
}
Value& Value::operator=(const Value &v){
	this->name = v.getName();
	this->parentId = v.getParentId();
	this->weigth = v.getWeight();
	this->value = v.getValue();
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
QString Value::getName() const{
	return name;
}
void Value::setParentId(int parentId){
	this->parentId = parentId;
}
void Value::setValue(double value){
	this->value = value;
}
void Value::setWeight(double weigth){
	this->weigth = weigth;
}
void Value::setName(QString name){
	this->name = name;
}