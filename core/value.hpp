#ifndef VALUE_H
#define VALUE_H 1
#include <QString>
#include <QObject>
#include <QDataStream>
namespace core {
	class Value : public QObject{
		Q_OBJECT
		Q_PROPERTY(int num READ getId)
		Q_PROPERTY(QString name READ getName WRITE setName NOTIFY nameChanged)
		Q_PROPERTY(double value READ getValue WRITE setValue NOTIFY valueChanged)
		Q_PROPERTY(double weight READ getWeight WRITE setWeight NOTIFY weightChanged)
		Q_PROPERTY(int parentId READ getParentId WRITE setParentId NOTIFY parentIdChanged)

	protected:
		static int count;
		int id;
		int parentId;
		double weigth;
		double value;
		QString name;
	public:
		Value();
		Value(QString, int, double, double);
		Value(const Value &v);
		Value& operator=(const Value &v);
		int getId() const;
		int getParentId() const;
		double getWeight() const;
		double getValue() const;
		const QString& getName() const;
		void setId(int);
		void setParentId(int);
		void setName(QString);
		void setValue(double);
		void setWeight(double);
	signals:
		void nameChanged();
		void valueChanged();
		void weightChanged();
		void parentIdChanged();
	};
}

#endif
