#include "module.hpp"
Module::Module(){}
Module::Module(QString name, int parentId, double weight, double value):Value(name, parentId, weight, value){}
Module::Module(const Module &m):Value(m){
	for(int i = 0; i < childs.size(); i++){
		this->childs[i] = m.getChild(i);
	}	
}
Module& Module::operator=(const Module &m){
	Value::operator=(m);
	for(int i = 0; i < childs.size(); i++){
		this->childs[i] = m.getChild(i);
	}	
	return *(this); 
}
void Module::addChild(int child){
	childs.push_back(child);
}
void Module::removeChild(int index){
	if(index >= 0 && index < childs.size())
		childs.remove(index);
}
int Module::getChild(int index){
	if(index >= 0 && index < childs.size())
		return childs[index];

}
QVector<int>& Module::getChilds(){
	return childs;
}
