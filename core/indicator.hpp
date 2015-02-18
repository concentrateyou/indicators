#ifndef INDICATOR_H
#define INDICATOR_H 1
#include <QString>
#include <QVector>
#include <QList>
#include <QObject>
#include <QDataStream>
#include <QXmlStreamWriter>
#include <QXmlStreamReader>

namespace core {
	class Indicator : public QObject{
		Q_OBJECT
		Q_PROPERTY(QString name READ getName WRITE setName NOTIFY nameChanged)
		Q_PROPERTY(double value READ getValue WRITE setValue NOTIFY valueChanged)
		Q_PROPERTY(QList<int> childs READ getChildsForQML NOTIFY childsChanged)
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
		void setChilds(QVector<int>&);
		void addChild(int);
		double getValue() const;
		const QString& getName() const;
		const QVector<int>& getChilds() const;
		QList<int> getChildsForQML();
		int getChild(int) const;
		bool removeChild(int);
		void removeAllChilds();

		void toXML(QXmlStreamWriter&);
		bool fromXML(QXmlStreamReader&);
	signals:
		void nameChanged();
		void valueChanged();
		void childsChanged();
	};
	QDataStream& operator>>(QDataStream& in, Indicator& i);
	QDataStream& operator<<(QDataStream& out, Indicator& i);
}

#endif
