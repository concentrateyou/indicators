#include <QtTest/QtTest>
#include <indicator.hpp>
using namespace core;

class TestIndicator: public QObject
{
	Q_OBJECT

private slots:
	void create();
};
 
void TestIndicator::create()
{	double value = 100.0;
	Indicator indicator("indicator", 100.0);
	QCOMPARE(indicator.getName(), QString("indicator"));
	QCOMPARE(indicator.getValue(), value);
}

QTEST_MAIN(TestIndicator)

#include "testIndicator.moc"