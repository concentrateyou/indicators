#ifndef INDEX_H
#define INDEX_H 1

#include "value.hpp"
#include <QObject>
#include <QDataStream>
namespace core {
	class Index : public Value {
		Q_OBJECT
   		Q_PROPERTY(double borneFav READ getBorneFav WRITE setBorneFav NOTIFY borneFavChanged)
   		Q_PROPERTY(double borneUnfav READ getBorneUnfav WRITE setBorneUnfav NOTIFY borneUnfavChanged)
	private:
		double borneFav;
		double borneUnfav;
	public:
		Index();
		Index(QString, int, double, double, double, double);
		Index(const Index &i);
		Index& operator=(const Index &i);
		double getBorneFav() const;
		double getBorneUnfav() const;
		void setBorneFav(double);
		void setBorneUnfav(double);
		void updateValues();
		
		void toCSV(int, QTextStream&);
		void toXML(QXmlStreamWriter&);
		bool fromXML(QXmlStreamReader&);
	signals:
		void borneFavChanged();
		void borneUnfavChanged();
	};

QDataStream& operator>>(QDataStream& in, Index& index);
QDataStream& operator<<(QDataStream& out, const Index& index);
}

#endif
