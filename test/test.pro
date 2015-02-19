TARGET = ../build/test
QT += testlib core qml quick printsupport
SOURCES = test_application.cpp
INCLUDEPATH += ../core
LIBS += -L../core -lcore