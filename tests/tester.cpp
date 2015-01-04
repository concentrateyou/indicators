#include <QtTest/QtTest>
#include "indicator.hpp"
using namespace std;

class Tester : public QObject {
    Q_OBJECT
private slots:
    void testHello();
};

void Tester::testHello(){
	core::Indicator d;
	string h = d.sayHi();
	QVERIFY (h.compare("Hi") == 0);
}

QTEST_MAIN(Tester)
#include "tester.moc"