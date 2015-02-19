#include "index.hpp"
#include <QDebug>
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
	return borneFav;
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
void Index::updateValues(){
	// Computing the F and U values 
	computeFAndUValues(borneFav, borneUnfav);
}
void Index::toCSV(int pos, QTextStream& csv){
	for(int i = 0; i < pos; ++i)
		csv << " ,";
	csv << name << ": " << value << " ( W:" << weight << " F:" << borneFav << " U:" << borneUnfav << " )\n";
}

void Index::toXML(QXmlStreamWriter& w){
	w.writeStartElement("index");
	w.writeAttribute("name", name);
	w.writeAttribute("weight", QString::number(weight));
	w.writeAttribute("value", QString::number(value));
	w.writeAttribute("borne-favorable", QString::number(borneFav));
	w.writeAttribute("borne-unfavorable", QString::number(borneUnfav));
	w.writeEndElement();
}
bool Index::fromXML(QXmlStreamReader& r){
	bool result = true;
	qDebug() << "Start parsing an index";
	if(!r.atEnd() && !r.hasError() && r.isStartElement() && r.name().compare("index") == 0){
		qDebug() << "Well it's an index, filling attributes ...";
    	name = r.attributes().value("name").toString();
    	weight = r.attributes().value("weight").toDouble();
    	value = r.attributes().value("value").toDouble();
    	borneFav = r.attributes().value("borne-favorable").toDouble();
    	borneUnfav = r.attributes().value("borne-unfavorable").toDouble();
    	r.readNext();
	} else 
		result = false;
	qDebug() << "End parsing an index";
	return result;
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