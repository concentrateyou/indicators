#ifndef VALUE_H
#define VALUE_H 1
#include <QString>
#include <QObject>
#include <QDataStream>
#include <QXmlStreamWriter>
#include <QXmlStreamReader>

namespace core {
	class Application;
	struct Cell {
		int id; // l'id de l'indice ou module correspondant
		bool isFav; // true if F, false if U
		double value; // la valeur de F ou U
	};
	class Value : public QObject {
		Q_OBJECT
		Q_PROPERTY(int num READ getId)
		Q_PROPERTY(QString name READ getName WRITE setName NOTIFY nameChanged)
		Q_PROPERTY(double value READ getValue WRITE setValue NOTIFY valueChanged)
		Q_PROPERTY(double weight READ getWeight WRITE setWeight NOTIFY weightChanged)
		Q_PROPERTY(int parentId READ getParentId WRITE setParentId NOTIFY parentIdChanged)
	protected:
		static int count;
		static Application* app;
		int id;
		int parentId;
		double weight;
		double value;
		double fValue;
		double uValue;
		QString name;
	public:
		static void setApp(Application*);
		static Application* getApp();
		static Value& at(int);
		Value();
		Value(QString, int, double, double);
		Value(const Value &v);
		Value& operator=(const Value &v);
		int getId() const;
		int getParentId() const;
		double getWeight() const;
		double getValue() const;
		double getFValue() const;
		double getUValue() const;
		const QString& getName() const;
		void setId(int);
		void setParentId(int);
		void setName(QString);
		void setValue(double);
		void setWeight(double);
		void computeFAndUValues(double, double);
		virtual void updateValues() = 0;
		virtual void toXML(QXmlStreamWriter&) = 0;
		virtual bool fromXML(QXmlStreamReader&) = 0;
	signals:
		void nameChanged();
		void valueChanged();
		void weightChanged();
		void parentIdChanged();
	};
}

#endif
