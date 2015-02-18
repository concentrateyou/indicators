#include "application.hpp"
using namespace core;

Indicator::Indicator(){}
Indicator::Indicator(const Indicator &i){
	name = i.name;
	value = i.value;
	this->childs = i.childs;
}
Indicator::Indicator(QString n, double v):name(n),value(v){}
Indicator& Indicator::operator=(const Indicator &i){
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
	for (int i = 0; i < childs.size(); ++i){
		if(index == childs[i])
			return childs[i];
	}
	return -1;
}
bool Indicator::removeChild(int index){
	for (int i = 0; i < childs.size(); ++i){
		if(index == childs[i]){
			childs.remove(i);
			return true;
		}
	}
	return false;
}
void Indicator::setChilds(QVector<int>& childs){
	this->childs = childs;
}

void Indicator::toXML(QXmlStreamWriter& w){
    w.writeStartElement("indicator");
    w.writeAttribute("name", name);
    w.writeAttribute("value", QString::number(value));
    foreach(int i, childs){
    	Value& v = Value::at(i);
    	v.toXML(w);
    }
    w.writeEndElement();
}
bool Indicator::fromXML(QXmlStreamReader& r){
    qDebug() << "Start parsing an indicator";
	bool result = true;
	if(!r.atEnd() && !r.hasError() && r.isStartElement() && r.name().compare("indicator") == 0){
	    qDebug() << "Well it's an indicator, filling the name and value ...";
    	name = r.attributes().value("name").toString();
    	value = r.attributes().value("value").toDouble();
    	r.readNext();
    	while(!r.atEnd() && !r.hasError() && result){
    		if(r.isStartElement()){
			    qDebug() << "An element start found";
    			if(r.name().compare("module") == 0){
				    qDebug() << "... it's a module";
    				int id = Value::getApp()->addModule("", 0, 0);
    				result = result && Value::at(id).fromXML(r);
    			} else if(r.name().compare("index") == 0){
				    qDebug() << "... it's an index";
    				int id = Value::getApp()->addIndex("", 0, 0, 0, 0, 0);
    				result = result && Value::at(id).fromXML(r);
    			}
    		}
    		r.readNext();
    	}
	} else 
		result = false;
    qDebug() << "End parsing an indicator";
	return result;
}

QDataStream& core::operator>>(QDataStream& in, Indicator& i){
	QString name;
	double value;
	QVector<int> childs;
	in >> name;
	i.setName(name);
	in >> value;
	i.setValue(value);
	in >> childs;
	i.setChilds(childs);
	return in;
}
QDataStream& core::operator<<(QDataStream& out, Indicator& i){
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
