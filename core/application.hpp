#ifndef APPLICATION_H
#define APPLICATION_H 1
#include "indicator.hpp"
#include "index.hpp"
#include "module.hpp"
#include <QMap>
namespace core {
	enum Format {
		XML,
		PDF,
		JPG,
		CSV,
		EXCEL
	};
	typedef QMap<int, Module> modulGroup;
	typedef QMap<int, Index> indexGroup;

	class Application : public QObject{
		Q_OBJECT
   		Q_PROPERTY(Indicator indicator READ getIndicator NOTIFY indicatorChanged)
   		Q_PROPERTY(modulGroup moduls READ getModuls NOTIFY modulChanged)
   		Q_PROPERTY(indexGroup indexes READ getIndexes NOTIFY indexChanged)
	private:
		Indicator indicator;
		QMap<int, Module> moduls;
		QMap<int, Index> indexes;
	public:
		const QMap<int, Module>& getModuls() const;
		const QMap<int, Index>& getIndexes() const;
		const Indicator& getIndicator() const;
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

		void addModule(QString, int, double, double);
		bool removeModule(int);
		void editModule(int, QString, double);
	signals:
		void indicatorChanged();
		void indexChanged();
		void modulChanged();

		
	};	
}

#endif
