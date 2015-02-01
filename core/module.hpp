#ifndef MODULE_H
#define MODULE_H 1

#include "value.hpp"
#include <QVector>
#include <QObject>
#include <QDataStream>
namespace core {
	class Module : public Value{
		Q_OBJECT
   		Q_PROPERTY(QVector<int> childs READ getChilds WRITE setChilds NOTIFY childsChanged)
	
	private:
		QVector<int> childs; 
	public:
		Module();
		Module(QString, int, double, double);
		Module(const Module &m);
		Module& operator=(const Module &m);
		void addChild(int);
		bool removeChild(int);
		int getChild(int) const;
		const QVector<int>& getChilds() const;
		void setChilds(QVector<int>& childs);
	signals:
		void childsChanged();
	};
QDataStream& operator>>(QDataStream& in, Module& module);
QDataStream& operator<<(QDataStream& out, const Module& module);

}

#endif
