TARGET = ../build/indicators
QT += qml quick widgets core
HEADERS += $$files(src/*.hpp)
SOURCES += $$files(src/*.cpp)
INCLUDEPATH += ../core
LIBS += -L../core -lcore
RESOURCES += qml/resources.qrc