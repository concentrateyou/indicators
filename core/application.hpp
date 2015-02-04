#ifndef APPLICATION_H
#define APPLICATION_H 1
#include "indicator.hpp"
#include "index.hpp"
#include "module.hpp"
#include <QMap>
#include <QList>
#include <QDebug>
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
   		Q_PROPERTY(QList<QObject*> modules READ getModulsForQML NOTIFY changed)
	private:
		Indicator indicator;
		QMap<int, Module> moduls;
		QMap<int, Index> indexes;
	public:
		const QMap<int, Module>& getModuls() const;
		const QMap<int, Index>& getIndexes() const;
		const Indicator& getIndicator() const;
		QList<QObject*> getIndexesForQML() ;
	 	QList<QObject*> getModulsForQML();
	 	QObject* getIndicatorForQML();	
	public slots:
		void init();
		void create(QString);
		void load(QString);
		void save(QString);
		//void export(QString);
		//void import(QString);

		void addIndex(QString, int, double, double, double, double);
		bool removeIndex(int);
		void editIndex(int, QString, double, double, double, double);

		void addModule(QString, int, double, double = 0);
		bool removeModule(int);
		void editModule(int, QString, double);
		void show(){
			qDebug() << "Indexes:";
			foreach(int i, indexes.keys()){
				qDebug() << i << ": { id:" << indexes[i].getId() << ", parent:" << indexes[i].getParentId() << ", name:" << indexes[i].getName() << " }";
			}
		}
	signals:
		void changed();
	};	
}

#endif
