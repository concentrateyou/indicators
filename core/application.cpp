#include "application.hpp"
#include <QFile>
#include <QDataStream>
#include <QDebug>
using namespace core;
void Application::init(){
	qDebug() << "init called !";
	indexes.clear();
	moduls.clear();
}
void Application::create(QString name){
	indicator.setId(0);
	indicator.setName(name);
	// a calculer
	indicator.setValue(10.0);
	emit changed();
}
void Application::load(QString fileName){
	QFile binaryFile(fileName);
	QDataStream data(&binaryFile);
	binaryFile.open(QFile::ReadOnly);
	data >> indicator;
	data >> indexes;
	data >> moduls;
	binaryFile.close();
	emit changed(); 
}
void Application::save(QString fileName, Format format){
	qDebug() << "Saving on : " << fileName;
	QFile binaryFile(fileName);
	QDataStream data(&binaryFile);
	binaryFile.open(QFile::WriteOnly);
	data << indicator;
	data << indexes;
	data << moduls;
	binaryFile.close();
}

void Application::export(QString fileName, Format format){
	switch(format){
		case XML: 
			exportXML(fileName); 
			break;
		case PDF:
			exportPDF(fileName); 
			break;
		case JPG:
			exportJPG(fileName); 
			break;;
		case CSV: 
			exportCSV(fileName); 
			break;
		case EXCEL: 
			exportEXCEL(fileName); 
			break;
	}

}
void Application::import(QString fileName, Format format){
	switch(format){
		case XML: 
			importXML(fileName); 
			break;
		case PDF:
			importPDF(fileName); 
			break;
		case JPG:
			importJPG(fileName); 
			break;;
		case CSV: 

			importCSV(fileName); 
			break;
		case EXCEL: 
			importEXCEL(fileName); 
			break;
	}
}
void Application::exportXML(QString fileName){
	int id;
	QFile xmlFile(fileName);
	QXmlStreamWriter xmlWriter(&xmlFile);
	xmlFile.open(QFile::WriteOnly);
    xmlWriter.setAutoFormatting(true);
    xmlWriter.writeStartDocument();
	    xmlWriter.writeStartElement("indicator");
	    xmlWriter.writeAttribute("id", indicator.getId());
	    xmlWriter.writeAttribute("name", indicator.getName());
	    xmlWriter.writeAttribute("value", indicator.getValue());
		writeDocumentXML(indicator.getChilds());	    
	    xmlWriter.writeEndElement();
    xmlWriter.writeEndDocument();
    xmlFile.close();
}
void Application::writeDocumentXML(QVector<int>& childs){

for (int i = 0; i < childs.size(); ++i)
   	{	
		if(indexes.contains(childs[i])){
			id = childs[i];
			Index& index = indexes[id];
			xmlWriter.writeStartElement("index");
				xmlWriter.writeAttribute("id", id);
				xmlWriter.writeAttribute("parentId", index.getParentId());
				xmlWriter.writeAttribute("name", index.getName());
				xmlWriter.writeAttribute("weigth", index.getWeight());
				xmlWriter.writeAttribute("value", index.getValue());
				xmlWriter.writeAttribute("borneFav", index.getBorneFav());
				xmlWriter.writeAttribute("borneUnfav", index.getBorneUnfav());
				xmlWriter.writeCharacters(index.getName());
			xmlWriter.writeEndElement();
		} else if(moduls.contains(childs[i])){
			id = childs[i];
			Module& module = moduls[id];
			xmlWriter.writeStartElement("module");
				xmlWriter.writeAttribute("id", id);
				xmlWriter.writeAttribute("parentId", module.getParentId());
				xmlWriter.writeAttribute("name", module.getName());
				xmlWriter.writeAttribute("weigth", module.getWeight());
				xmlWriter.writeAttribute("value", module.getValue());
				writeDocumentXML(module.getChilds());
			xmlWriter.writeEndElement();
		}
   	}
}
void Application::importXML(QString fileName){
	QString id, name, value, parentId, weigth, borneFav, borneUnfav;

    QFile xmlFile(fileName);
    QXmlStreamReader xmlReader(&xmlFile);
    xmlFile.open(QFile::ReadOnly);
    xmlReader.readNext();
    while(!xmlReader.atEnd() && !xmlReader.hasError()) {
     //   QXmlStreamReader::TokenType token = xmlReader.readNext();
        if(xmlReader.isStartElement() && xmlReader.name() == "indicator"){
        	id = xmlReader.attributes().value("id").toString();
        	indicator.setId(id.toInt());
        	name = xmlReader.attributes().value("name").toString();
        	indicator.setName(name);
        	value = xmlReader.attributes().value("value").toString();
        	indicator.setValue(value.toDouble());

        	readDocumentXML(xmlReader.readNext());

/*
            if(xmlReader.name("index")){
            	id = xmlReader.attributes().value("id").toString();
	        	indicator.addChild(id);

	        	parentId = xmlReader.attributes().value("parentId").toString();
	        	name = xmlReader.attributes().value("name").toString();	
	     		weigth = xmlReader.attributes().value("weigth").toString();
	        	value = xmlReader.attributes().value("value").toString();
	        	borneFav = xmlReader.attributes().value("borneFav").toString();
	        	borneUnfav = xmlReader.attributes().value("borneUnfav").toString();
				Index index(name, parentId.toInt(), weigth.toDouble(), value.toDouble(), borneFav.toDouble(), borneUnfav.toDouble());
				indexes.insert(id, index);
            }else if(xmlReader.name("module")){
            	id = xmlReader.attributes().value("id").toString();
	        	indicator.addChild(id);

	        	parentId = xmlReader.attributes().value("parentId").toString();
	        	name = xmlReader.attributes().value("name").toString();	
	     		weigth = xmlReader.attributes().value("weigth").toString();
	        	value = xmlReader.attributes().value("value").toString();


            }

*/
        }
    }
    if(xmlReader.hasError())
    	qDebug() << "Error while reading the xml !";
    else
    	qDebug() << "XML name: " << name;
    xmlReader.clear();
    xmlFile.close();
}

void Application::readDocumentXML(QXmlStreamReader::TokenType xmlReader){

if(xmlReader.name("index")){
    	id = xmlReader.attributes().value("id").toString();
    	indicator.addChild(id);

    	parentId = xmlReader.attributes().value("parentId").toString();
    	name = xmlReader.attributes().value("name").toString();	
 		weigth = xmlReader.attributes().value("weigth").toString();
    	value = xmlReader.attributes().value("value").toString();
    	borneFav = xmlReader.attributes().value("borneFav").toString();
    	borneUnfav = xmlReader.attributes().value("borneUnfav").toString();
		Index index(name, parentId.toInt(), weigth.toDouble(), value.toDouble(), borneFav.toDouble(), borneUnfav.toDouble());
		indexes.insert(id, index);
    }else if(xmlReader.name("module")){
    	id = xmlReader.attributes().value("id").toString();
    	indicator.addChild(id);

    	parentId = xmlReader.attributes().value("parentId").toString();
    	name = xmlReader.attributes().value("name").toString();	
 		weigth = xmlReader.attributes().value("weigth").toString();
    	value = xmlReader.attributes().value("value").toString();
		xmlReader.readNext();
    	readDocumentXML(xmlReader);
		Module module(name, parentId.toInt(), weight.toDouble(), value.toDouble());
		moduls.insert(id, module);
    }

}
void Application::exportPDF(QString fileName){

}
void Application::importPDF(QString fileName){

}
void Application::exportCSV(QString fileName){

}
void Application::importCSV(QString fileName){

}
void Application::exportEXCEL(QString fileName){

}
void Application::importEXCEL(QString fileName){

}
void Application::exportJPG(QString fileName){

}
void Application::importJPG(QString fileName){

}

void Application::addIndex(QString name, int parentId, double weight, double value, double borneFav, double borneUnfav){
	Index index(name, parentId, weight, value, borneFav, borneUnfav);
	indexes.insert(index.getId(), index);
	if(indicator.getId() == parentId){
		indicator.addChild(index.getId());
	}else{
		Module& module = moduls[parentId];
		module.addChild(index.getId());
	}
	emit changed();

}
bool Application::removeIndex(int id){
	bool result;
	if(indicator.getChild(id) != -1){
		if(indexes.remove(id) != 0)
			if(indicator.removeChild(id) == true)
				result = true;
			else
				result = false;
		else
			result = false;
	} else
		result = false;

	if(result)
		emit changed();
	return result;
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

void Application::addModule(QString name, int parentId, double weight, double value){
	Module module(name, parentId, weight, value);
	moduls.insert(module.getId(), module);
	if(indicator.getId() == parentId){
		indicator.addChild(module.getId());
	}else{
		Module& module2 = moduls[parentId];
		module2.addChild(module.getId());
	}
	emit changed();
}
bool Application::removeModule(int id){
	if(indicator.getChild(id) != -1){
		if(moduls.remove(id) != 0){
			if(indicator.removeChild(id) == true)
				return true;
			else
				return false;

		}else{
			return false;
		}
	}else
		return false;
}
void Application::editModule(int id, QString name, double weight){
	if(moduls.contains(id)){
		Module& module = moduls[id];
		module.setName(name);
		module.setWeight(weight);
		emit changed();
	}
}
const QMap<int, Module>& Application::getModuls() const{
	return moduls;
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
	qDebug() << "The size of indexes is : " << list.size();
	return list;
}
QList<QObject*> Application::getModulsForQML() {
	QList<QObject*> list;
	QMap<int, Module>::iterator it = moduls.begin();
	while(it != moduls.end()){
		Module& rmodule = *it;
		Module* pmodule = &rmodule;
		list.append(pmodule);
		++ it;
	}
	return list;
}

QObject* Application::getIndicatorForQML() {
	return &indicator;
}
