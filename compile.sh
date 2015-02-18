#!/bin/bash
cd core/
make
cd ../test
touch test_application.cpp
make
cd ../gui
touch main.cpp
make
cd ..