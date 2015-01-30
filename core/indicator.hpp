#ifndef INDICATOR_H
#define INDICATOR_H 1
#include <QString>
#include <QVector>
namespace core {
	class Indicator {
	private:
		QString name;
		double value;
		QVector<int> childs;
	public:
		Indicator();
		Indicator(const Indicator &i);
		Indicator(QString, double);
		Indicator& operator=(const Indicator &i);
		void setName(QString);
		void setValue(double);
		QString getName() const;
		double getValue() const;
		void addChild(int);
		void removeChild(int);
		QVector<int>& getChilds();
		int getChild(int);
	};
}

#endif
