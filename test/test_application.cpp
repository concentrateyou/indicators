#include <QtTest/QtTest>
#include <application.hpp>
using namespace core;

class TestApplication : public QObject {
	Q_OBJECT
private:
	Application app;
private slots:
	void init();
	void initApplication();
	void create();
	void addIndex();
	void editIndex();
	void removeIndex();
	void addModule();
	void editModule();
	void removeModule();
	void saveAndLoad();
	void simpleComputing();
	void exportImportIndicator();
	void exportImportModule();
};

void TestApplication::init(){
	app.init();
	app.create("Indicator");
}

void TestApplication::initApplication(){
	app.addIndex("I", 0, 2, 0, 0, 1);
	app.addModule("M", 0, 2);
	app.init();
	QVERIFY(0 == (int) app.getIndexes().size());
	QVERIFY(0 == (int) app.getModules().size());
	QVERIFY(0 == app.getIndicator().getName().compare(""));
	QVERIFY(0 == (int) app.getIndicator().getChilds().size());
}
void TestApplication::create(){
	QVERIFY(0 == app.getIndicator().getName().compare("Indicator"));
	QVERIFY(0 == (int) app.getIndexes().size());
	QVERIFY(0 == (int) app.getModules().size());
	QVERIFY(0 == (int) app.getIndicator().getChilds().size());
}
void TestApplication::addIndex(){
	int id = app.addIndex("I", 0, 2, 0, 0, 1);
	const Index i = (app.getIndexes())[id];
	QVERIFY(1 == (int) app.getIndexes().size());
	QVERIFY(1 == (int) app.getIndicator().getChilds().size());
	QVERIFY(id == app.getIndicator().getChilds().front());
	QVERIFY(0 == i.getParentId());
	QVERIFY(0 == i.getName().compare("I"));
	QVERIFY(2 == i.getWeight());
	QVERIFY(0 == i.getValue());
	QVERIFY(0 == i.getBorneFav());
	QVERIFY(1 == i.getBorneUnfav());

	app.addModule("M", 0, 2);
	id = app.addIndex("I2", id, 2, 0, 0, 1);
	QVERIFY(1 == (int) app.getModules().first().getChilds().size());
	QVERIFY(id == app.getModules().first().getChilds().front());
}
void TestApplication::editIndex(){
	int id = app.addIndex("I", 0, 2, 0, 0, 1);
	app.editIndex(id, "J", 3, 1, 0.2, 0.8);
	const Index i = (app.getIndexes())[id];
	QVERIFY(1 == (int) app.getIndexes().size());
	QVERIFY(0 == i.getName().compare("J"));
	QVERIFY(3 == i.getWeight());
	QVERIFY(1 == i.getValue());
	QVERIFY(0.2 == i.getBorneFav());
	QVERIFY(0.8 == i.getBorneUnfav());
}
void TestApplication::removeIndex(){
	int id = app.addIndex("I", 0, 2, 0, 0, 1);
	app.removeIndex(id);
	QVERIFY(0 == (int) app.getIndexes().size());

	id = app.addModule("M", 0, 2);
	id = app.addIndex("J", id, 2, 0, 0, 1);

	app.removeIndex(id);
	QVERIFY(0 == (int) app.getIndexes().size());
	QVERIFY(0 == (int) app.getModules().first().getChilds().size());
}
void TestApplication::addModule(){
	int id = app.addModule("M", 0, 2);
	const Module m = (app.getModules())[id];
	QVERIFY(1 == (int) app.getModules().size());
	QVERIFY(0 == m.getParentId());
	QVERIFY(0 == m.getName().compare("M"));
	QVERIFY(2 == m.getWeight());
}
void TestApplication::editModule(){
	int id = app.addModule("M", 0, 2);
	app.editModule(id, "N", 5);
	const Module m = (app.getModules())[id];
	QVERIFY(1 == (int) app.getModules().size());
	QVERIFY(0 == m.getParentId());
	QVERIFY(0 == m.getName().compare("N"));
	QVERIFY(5 == m.getWeight());
}
void TestApplication::removeModule(){
	app.addIndex("I1", 0, 2, 0, 0, 1);
	int id = app.addModule("M1", 0, 2);
	app.addIndex("I10", id, 2, 0, 0, 1);
	int temp = app.addModule("M2", id, 2);
	app.addIndex("I20", temp, 2, 0, 0, 1);

	app.removeModule(id);
	QVERIFY(1 == (int) app.getIndexes().size());
	QVERIFY(0 == app.getIndexes().first().getName().compare("I1"));
	QVERIFY(0 == (int) app.getModules().size());
}
void TestApplication::saveAndLoad(){
	// TODO ...
}
void TestApplication::simpleComputing(){
	app.addIndex("PIdoy", 0, 0.5, 2, 1.0, 2.5);
	app.addIndex("PITmin", 0, 0.5, 1.7, 1.0, 2.5);
	app.updateValue();
	qDebug() << app.getIndicator().getValue();
	QVERIFY(6184 == (int) (10000 * app.getIndicator().getValue()));
}
void TestApplication::exportImportIndicator(){
	int mId = app.addModule("M1", 0, 0.5);
	app.addIndex("A", mId, 0.5, 1.5, 0.5, 2.0);
	app.addIndex("B", mId, 0.5, 1.8, 2.3, 1.2);
	int mId2 = app.addModule("M2", mId, 0.25);
	app.addIndex("C", mId2, 1, 1.3, 0.3, 2.6);

	app.exportAs("files/indicator.xml", XML);

	app.init();
	app.create("");
	app.importXML("files/indicator.xml");

	QVERIFY(0 == app.getIndicator().getName().compare("Indicator"));
	QVERIFY(3 == app.getIndexes().size());
	QVERIFY(2 == app.getModules().size());
}
void TestApplication::exportImportModule(){
	int mId1 = app.addModule("M1", 0, 0.5);
	app.addIndex("A", mId1, 0.5, 1.5, 0.5, 2.0);
	int mId2 = app.addModule("M2", mId1, 0.25);
	app.addIndex("B", mId2, 0.5, 1.8, 2.3, 1.2);
	app.addIndex("C", mId2, 1, 1.3, 0.3, 2.6);
	int mId3 = app.addModule("M3", mId1, 0.25);
	app.addIndex("D", mId3, 1, 1, 0.3, 1.7);

	app.exportModuleAsXML(mId1, "files/module.xml");
}
QTEST_MAIN(TestApplication)
#include "test_application.moc"