#include <cmath>
#include "application.hpp"
using namespace core;
Module::Module(){}
Module::Module(QString name, int parentId, double weight):Value(name, parentId, weight, 0){}
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
QList<int> Module::getChildsForQML(){
	return childs.toList();
}

void Module::updateValues(){
	// Calculer la somme des poids des fils
	double totalWeight = 0;
	foreach(int id, childs){
		totalWeight += app->valueAt(id).getWeight();
	}
	// Construction de la table des calculs
	int cols = childs.size();
	int rows = pow(2, cols);
	int i, j, k, l;
	bool f;
	Cell ** table = new Cell* [cols];
	table[0] = new Cell[cols * rows];
	for(j = 1; j < cols; ++j)
		table[j] = table[0] + j * rows;
	// Remplir la table par les valeurs F et U
	j = 0; l = 1;
	foreach(int id, childs){
		Value& v = app->valueAt(id);
		v.updateValues();
		i = 0; f = true;
		while(i < rows){
			for(k = 0; k < l; ++k){
				table[j][i].id = v.getId();
				table[j][i].isFav = f;
				table[j][i].value = ( f ) ? v.getFValue() : v.getUValue();
				++ i;
			}
			f = ! f;
		}
		++ j;
		l = 2 * l;
	}
	// Calculer la valeur du module
	double truthValuesSum = 0, fuzzySolution = 0, w, B;
	for(i = 0; i < rows; ++ i){
		w = 1; B = 0;
		for(j = 0; j < cols; ++ j){
			if(w > table[j][i].value)
				w = table[j][i].value;
			if(! table[j][i].isFav)
				B += app->valueAt(table[j][i].id).getWeight() / totalWeight;
		}
		truthValuesSum += w;
		fuzzySolution += w * B;
	}
	value = fuzzySolution / truthValuesSum;
	computeFAndUValues(0, 1);	
}
void Module::toXML(QXmlStreamWriter& w){
	w.writeStartElement("module");
    w.writeAttribute("name", name);
    w.writeAttribute("weight", QString::number(weight));
    w.writeAttribute("value", QString::number(value));
    foreach(int i, childs){
    	Value& v = Value::at(i);
    	v.toXML(w);
    }
    w.writeEndElement();
}
bool Module::fromXML(QXmlStreamReader& r){
	bool result = true;
	qDebug() << "Start parsing a module";
	if(!r.atEnd() && !r.hasError() && r.isStartElement() && r.name().compare("module") == 0){
    	qDebug() << "Well it's a module, filling attributes ...";
    	name = r.attributes().value("name").toString();
    	weight = r.attributes().value("weight").toDouble();
    	value = r.attributes().value("value").toDouble();
    	r.readNext();
    	qDebug() << "Shearing for childs ...";
    	while( !r.atEnd() && !r.hasError() && result){
    		if(r.isStartElement()){
    			qDebug() << "Something found";
    			if(r.name().compare("module") == 0){
    				qDebug() << "it's a module";
    				int i = Value::getApp()->addModule("", id, 0);
    				result = result && Value::at(i).fromXML(r);
    			} else if(r.name().compare("index") == 0){
    				qDebug() << "It's an index";
    				int i = Value::getApp()->addIndex("", id, 0, 0, 0, 0);
    				result = result && Value::at(i).fromXML(r);
    			}
    		}
    		r.readNext();
    	}
	} else 
		result = false;
	qDebug() << "End parsing a module";
	return result;
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
