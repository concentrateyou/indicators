#include "index.hpp"
using namespace core;
Index::Index(){}
Index::Index(QString name, int parentId, double weight, double value, double borneFav, double borneUnfav):Value(name, parentId, weight, value){
	this->borneFav = borneFav;
	this->borneUnfav = borneUnfav;
}
Index::Index(const Index &i):Value(i){
	this->borneFav = i.borneFav;
	this->borneUnfav = i.borneUnfav;
}
Index& Index::operator=(const Index &i){
	Value::operator=(i);
	this->borneFav = i.borneFav;
	this->borneUnfav = i.borneUnfav;
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
	emit borneFavChanged();
}
void Index::setBorneUnfav(double borneUnfav){
	this->borneUnfav = borneUnfav;
	emit borneUnfavChanged();
}
QDataStream& core::operator>>(QDataStream& in, Index& index){
	int id, parentId;
	QString name;
	double value, weight, borneFav, borneUnfav;
	in >> id;
	index.setId(id);
	in >> parentId;
	index.setParentId(parentId);
	in >> name;
	index.setName(name);
	in >> value;
	index.setValue(value);
	in >> weight;
	index.setWeight(weight);
	in >> borneFav;
	index.setBorneFav(borneFav);
	in >> borneUnfav;
	index.setBorneUnfav(borneUnfav);
	return in;
}
QDataStream& core::operator<<(QDataStream& out, const Index& index){
	out << index.getId();
	out << index.getParentId();
	out << index.getName();
	out << index.getValue();
	out << index.getWeight();
	out << index.getBorneFav();
	out << index.getBorneUnfav();
	return out;
}