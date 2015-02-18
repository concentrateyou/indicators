#ifndef APPLICATION_H
#define APPLICATION_H 1
#include "indicator.hpp"
#include "index.hpp"
#include "module.hpp"
#include <QMap>
#include <QList>
#include <QDebug>
#include <QXmlStreamWriter>
namespace core {
	enum Format {
		XML,
		PDF,
		JPG,
		CSV,
		EXCEL
	};

	class Application : public QObject{
		Q_OBJECT
   		Q_PROPERTY(QObject* indicator READ getIndicatorForQML NOTIFY changed)
   		Q_PROPERTY(QList<QObject*> indexes READ getIndexesForQML NOTIFY changed)
   		Q_PROPERTY(QList<QObject*> modules READ getModulesForQML NOTIFY changed)
	private:
		Indicator indicator;
		QMap<int, Module> modules;
		QMap<int, Index> indexes;
	public:
		const QMap<int, Module>& getModules() const;
		const QMap<int, Index>& getIndexes() const;
		const Indicator& getIndicator() const;
		QList<QObject*> getIndexesForQML() ;
	 	QList<QObject*> getModulesForQML();
	 	QObject* getIndicatorForQML();
	public slots:
		void init();
		void create(QString);
		void load(QString);
		void save(QString);
		
		bool importXML(QString);
		void exportAs(QString, Format);
		void exportAsXML(QString);
		void exportAsPDF(QString);
		void exportAsCSV(QString);
		void exportAsEXCEL(QString);
		void exportAsJPG(QString);
		
		int addIndex(QString, int, double, double, double, double);
		void editIndex(int, QString, double, double, double, double);
		bool removeIndex(int);

		int addModule(QString, int, double);
		void editModule(int, QString, double);
		bool removeModule(int);
		void exportModuleAsXML(int, QString);

		Value& valueAt(int);
		bool removeValue(int);
		void updateValue();
		// void show(){
		// 	qDebug() << "Indexes:";
		// 	foreach(int i, indexes.keys()){
		// 		qDebug() << i << ": { id:" << indexes[i].getId() << ", parent:" << indexes[i].getParentId() << ", name:" << indexes[i].getName() << " }";
		// 	}
		// 	qDebug() << "Modules:";
		// 	foreach(int i, modules.keys()){
		// 		qDebug() << i << ": { id:" << modules[i].getId() << ", parent:" << modules[i].getParentId() << ", name:" << modules[i].getName() << " }";
		// 	}
		// }
	signals:
		void changed();
	};	
}

#endif
