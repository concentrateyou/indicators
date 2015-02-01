#include <iostream>
#include <indicator.hpp>
#include <gtest/gtest.h>
#include "test_PFA.inl"
using namespace std;

int main(int argc,char * argv[]) {
 ::testing::InitGoogleTest(&argc,argv);
 return RUN_ALL_TESTS();
}