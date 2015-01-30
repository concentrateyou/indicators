#ifndef MODULE_H
#define MODULE_H 1

#include "value.hpp"
#include <QVector>
namespace core {
	class Module : public Value {
	private:
		QVector<int> childs; 
	public:
		Module();
		Module(QString, int, double, double);
		Module(const Module &m);
		Module& operator=(const Module &m);
		void addChild(int);
		void removeChild(int);
		int getChild(int);
		QVector<int>& getChilds();
	};
}

#endif
