#include "index.hpp"

Index::Index(){}
Index::Index(QString name, int parentId, double weight, double value, double borneFav, double borneUnfav):Value(name, parentId, weight, value){
	this->borneFav = borneFav;
	this->borneUnfav = borneUnfav;
}
Index::Index(const Index &i):Value(i){
	this->borneFav = i.getBorneFav();
	this->borneUnfav = i.getBorneUnfav();
}
Index& Index::operator=(const Index &i){
	Value::operator=(i);
	this->borneFav = i.getBorneFav();
	this->borneUnfav = i.getBorneUnfav();
	return *(this);
}
double Index::getBorneFav() const{
	return borneUnfav;
}
double Index::getBorneUnfav() const{
	return borneUnfav;
}
void Index::setBorneFav(double borneFav){
	this->borneFav = borneFav;
}
void Index::setBorneUnfav(double borneUnfav){
	this->borneUnfav = borneUnfav;
}