#include "application.hpp"
using namespace core;

int Value::count = 0;
Application* Value::app = NULL;
void Value::setApp(Application* a){
	app = a;
}
Application* Value::getApp(){
	return app;
}
Value& Value::at(int id){
	// On suppose que app != NULL
	return app->valueAt(id);
}
Value::Value(){
	Value::count ++;
	id = Value::count;
	parentId = 0;
	value = 0.0;
	weight = 0.0;
}
Value::Value(QString name, int parentId, double weight, double value){
	Value::count ++;
	id = Value::count;
	this->name = name;	
	this->parentId = parentId;
	this->weight = weight;
	this->value = value;
}
Value::Value(const Value &v){
	this->id = v.id;
	this->name = v.name;	
	this->parentId = v.parentId;
	this->weight = v.weight;
	this->value = v.value;
}
Value& Value::operator=(const Value &v){
	this->id = v.id;
	this->name = v.name;	
	this->parentId = v.parentId;
	this->weight = v.weight;
	this->value = v.value;
	return *(this);
}
int Value::getParentId() const{
	return parentId;
}
int Value::getId() const{
	return id;
}
double Value::getWeight() const{
	return weight;
}
double Value::getValue() const{
	return value;
}
double Value::getFValue() const{
	return fValue;
}
double Value::getUValue() const{
	return uValue;
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
void Value::setWeight(double weight){
	this->weight = weight;
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
void Value::computeFAndUValues(double borneF, double borneU){
	if( borneF < borneU ){
		if(value <= borneF)
			fValue = 1;
		else if(value <= ( borneF + borneU ) / 2.0)
			fValue = 2 * ((value - borneF) / (borneU - borneF)) * ((value - borneF) / (borneU - borneF));
		else if(value <= borneU)
			fValue = 2 * ((borneU - value) / (borneU - borneF)) * ((borneU - value) / (borneU - borneF));
		else
			fValue = 0;
		uValue = 1 - fValue;
	} else if( borneU < borneF ){
		if(value <= borneU)
			uValue = 1;
		else if(value <= ( borneU + borneF ) / 2.0)
			uValue = 2 * ((value - borneU) / (borneF - borneU)) * ((value - borneU) / (borneF - borneU));
		else if(value <= borneF)
			uValue = 2 * ((value - borneF) / (borneF - borneU)) * ((value - borneF) / (borneF - borneU));
		else
			uValue = 0;
		fValue = 1 - uValue;
	} else {
		// borneF == borneU !!
		if(value < borneF){
			fValue = 1;
			uValue = 0;
		} else {
			fValue = 0;
			uValue = 1;
		}
	}
	qDebug() << name << ": (BF:" << borneF << ", BU:" << borneU << ", V:" << value << " ) => ( FV:" << fValue << ", UV:" << uValue << ")";
}