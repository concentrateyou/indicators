TARGET = ../build/test
QT += testlib core
SOURCES = test_application.cpp
INCLUDEPATH += ../core
LIBS += -L../core -lcore