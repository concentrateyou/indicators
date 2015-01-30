#ifndef VALUE_H
#define VALUE_H 1
#include <QString>
namespace core {
	class Value {
	protected:
		static int id;
		int parentId;
		double weight;
		double value;
		QString name;
	public:
		Value();
		Value(QString, int, double, double);
		Value(const Value &v);
		Value& operator=(const Value &v);
		int getParentId() const;
		double getWeight() const;
		double getValue() const;
		QString getName() const;
		void setParentId(int);
		void setName(QString);
		void setValue(double);
		void setWeight(double);

	};
}

#endif
