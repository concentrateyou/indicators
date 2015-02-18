#include "application.hpp"
#include <cmath>
#include <QFile>
#include <QDebug>

using namespace core;

void Application::init(){
	// qDebug() << "init called !";
	indexes.clear();
	modules.clear();
	indicator.setName("");
	indicator.removeAllChilds();
	Value::setApp(this);
}
void Application::create(QString name){
	indicator.setName(name);
	indicator.setValue(-1);
	emit changed();
}
void Application::load(QString fileName){
	QFile binaryFile(fileName);
	QDataStream data(&binaryFile);
	binaryFile.open(QFile::ReadOnly);
	data >> indicator;
	data >> indexes;
	data >> modules;
	binaryFile.close();
	emit changed(); 
}
void Application::save(QString fileName){
	qDebug() << "Saving on : " << fileName;
	QFile binaryFile(fileName);
	QDataStream data(&binaryFile);
	binaryFile.open(QFile::WriteOnly);
	data << indicator;
	data << indexes;
	data << modules;
	binaryFile.close();
}

void Application::exportAs(QString fileName, Format format){
	switch(format){
		case XML: 
			exportAsXML(fileName); 
		break;
		case PDF:
			exportAsPDF(fileName); 
		break;
		case JPG:
			exportAsJPG(fileName); 
		break;;
		case CSV: 
			exportAsCSV(fileName); 
		break;
		case EXCEL: 
			exportAsEXCEL(fileName); 
		break;
	}
}

void Application::exportAsXML(QString fileName){
	QFile xmlFile(fileName);
	QXmlStreamWriter xmlWriter(&xmlFile);
	xmlFile.open(QFile::WriteOnly);
    xmlWriter.setAutoFormatting(true);
    xmlWriter.writeStartDocument();
    indicator.toXML(xmlWriter);
    xmlWriter.writeEndDocument();
    xmlFile.close();
}

void Application::exportModuleAsXML(int id, QString fileName){
	if(modules.contains(id)){
		QFile xmlFile(fileName);
		QXmlStreamWriter xmlWriter(&xmlFile);
		xmlFile.open(QFile::WriteOnly);
	    xmlWriter.setAutoFormatting(true);
	    xmlWriter.writeStartDocument();
	    modules[id].toXML(xmlWriter);
	    xmlWriter.writeEndDocument();
	    xmlFile.close();
	}
}

bool Application::importXML(QString fileName){
	bool result;
    QFile xmlFile(fileName);
    QXmlStreamReader xmlReader(&xmlFile);
    xmlFile.open(QFile::ReadOnly);
    qDebug() << "Start Importing XML";
    while(!xmlReader.atEnd() && !xmlReader.hasError()){
    	xmlReader.readNext();
        if(xmlReader.isStartElement() && xmlReader.name().compare("indicator") == 0){
		    qDebug() << "Indicator Found !";
        	result = indicator.fromXML(xmlReader);
        	break;
        }
    }
    if(xmlReader.hasError())
    	result = false;
    xmlReader.clear();
    xmlFile.close();
    return result;
}



void Application::exportAsPDF(QString fileName){

}
void Application::exportAsCSV(QString fileName){

}
void Application::exportAsEXCEL(QString fileName){

}
void Application::exportAsJPG(QString fileName){

}

int Application::addIndex(QString name, int parentId, double weight, double value, double borneFav, double borneUnfav){
	Index index(name, parentId, weight, value, borneFav, borneUnfav);
	indexes.insert(index.getId(), index);
	if(0 == parentId){
		indicator.addChild(index.getId());
	} else {
		Module& module = modules[parentId];
		module.addChild(index.getId());
	}
	emit changed();
	return index.getId();
}
void Application::editIndex(int id, QString name, double weight, double value, double borneFav, double borneUnfav){
	if(indexes.contains(id)){
		Index& index = indexes[id];
		index.setName(name);
		index.setWeight(weight);
		index.setValue(value);
		index.setBorneFav(borneFav);
		index.setBorneUnfav(borneUnfav);
		emit changed();
	}
}
int Application::addModule(QString name, int parentId, double weight){
	Module module(name, parentId, weight);
	modules.insert(module.getId(), module);
	if(0 == parentId){
		indicator.addChild(module.getId());
	}else{
		Module& module2 = modules[parentId];
		module2.addChild(module.getId());
	}
	emit changed();
	return module.getId();
}
void Application::editModule(int id, QString name, double weight){
	if(modules.contains(id)){
		Module& module = modules[id];
		module.setName(name);
		module.setWeight(weight);
		emit changed();
	}
}

Value& Application::valueAt(int id){
	if(modules.contains(id))
		return modules[id];
	return indexes[id];
}

bool Application::removeValue(int id){
	// qDebug() << "removing value with id : " << id;
	bool result = false;
	if(indexes.contains(id)){
		// qDebug() << "this value is an index";
		result = removeIndex(id);
	} else if(modules.contains(id)){
		// qDebug() << "this value is a module";
		result = removeModule(id);
	}
	if(result)
		emit changed();
	return result;
}
bool Application::removeIndex(int id){
	bool result = false;
	// qDebug() << "removing index:" << id;
	if(indexes.contains(id)){
		// qDebug() << "  index found in indexes";
		int pid = indexes[id].getParentId(); 
		if(pid == 0){
			// qDebug() << "  the parent is the indicator";
			indicator.removeChild(id);
		} else {
			// qDebug() << "  the parent is a module";
			modules[pid].removeChild(id);
		}
		if(indexes.remove(id) == 1){
			// qDebug() << "  the index is removed :D";
			result = true;
		} else {
			// qDebug() << "  the index is not removed :(";
		}
	}
	return result;
}
bool Application::removeModule(int id){
	bool result = false;
	// qDebug() << "removing module: " << id;
	if(modules.contains(id)){
		Module& m = modules[id];
		// qDebug() << "  the module exists in modules";
		int pid = m.getParentId(); 
		if(pid == 0){
			// qDebug() << "  the parent is the indicator";
			indicator.removeChild(id);
		} else {
			// qDebug() << "  the parent is a module";
			modules[pid].removeChild(id);
		}
		foreach(int i, m.getChilds()){
			// qDebug() << "removing child: " << i;
			removeValue(i);
		}
		if(1 == modules.remove(id)){
			// qDebug() << "  the module is removed :D";
			result = true;
		} else {
			// qDebug() << "  the module is not removed :(";
		}
	}
	return result;
}

const QMap<int, Module>& Application::getModules() const{
	return modules;
}
const QMap<int, Index>& Application::getIndexes() const{
	return indexes;
}
const Indicator& Application::getIndicator() const{
	return indicator;
}
QList<QObject*> Application::getIndexesForQML() {
	QList<QObject*> list;
	QMap<int, Index>::iterator it = indexes.begin();
	while(it != indexes.end()){
		Index& rindex = *it;
		Index* pindex = &rindex;
		list.append(pindex);
		++ it;
	}
	return list;
}
QList<QObject*> Application::getModulesForQML() {
	QList<QObject*> list;
	QMap<int, Module>::iterator it = modules.begin();
	while(it != modules.end()){
		Module& rmodule = *it;
		Module* pmodule = &rmodule;
		list.append(pmodule);
		++ it;
	}
	return list;
}

QObject* Application::getIndicatorForQML() {
	// qDebug() << "Indicator Requested !";
	return &indicator;
}

void Application::updateValue(){
	// Calculer la somme des poids des fils
	double totalWeight = 0;
	foreach(int id, indicator.getChilds()){
		totalWeight += valueAt(id).getWeight();
	}
	// Construction de la table des calculs
	int cols = indicator.getChilds().size();
	int rows = pow(2, cols);
	int i, j, k, l;
	bool f;
	Cell ** table = new Cell* [cols];
	table[0] = new Cell[cols * rows];
	for(j = 1; j < cols; ++j)
		table[j] = table[0] + j * rows;
	// Remplir la table par les valeurs F et U
	j = 0; l = 1;
	foreach(int id, indicator.getChilds()){
		Value& v = valueAt(id);
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
	// QDebug dd = qDebug();
	double truthValuesSum = 0, fuzzySolution = 0, w, B;
	// dd << "\n";
	for(i = 0; i < rows; ++ i){
		w = 1; B = 0;
		for(j = 0; j < cols; ++ j){
			// dd << ((table[j][i].isFav)? "F" : "U") << table[j][i].value << "(" << table[j][i].id << ")\t";
			if(w > table[j][i].value)
				w = table[j][i].value;
			if(! table[j][i].isFav)
				B += valueAt(table[j][i].id).getWeight() / totalWeight;
		}
		truthValuesSum += w;
		fuzzySolution += w * B;
		// dd << B << "\t" << w << "\n";
	}
	// dd << "fuzzySolution: " << fuzzySolution << "\n";
	// dd << "truthValuesSum: " << truthValuesSum << "\n";
	indicator.setValue(fuzzySolution / truthValuesSum);
}