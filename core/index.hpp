#ifndef INDEX_H
#define INDEX_H 1

#include "value.hpp"

namespace core {
	class Index : public Value {
	private:
		double borneFav;
		double borneUnfov;
	public:
		Index();
		Index(QString, int, double, double, double, double);
		Index(const Index &i);
		Index& operator=(const Index &i);
		double getBorneFav() const;
		double getBorneUnfav() const;
		void setBorneFav(double);
		void setBorneUnfav(double);
	};
}

#endif
