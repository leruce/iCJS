//
// Created by Bidbip on 11/12/2017.
//

/*
Garrett Addington

output
s.getTop: -1= -1
s.getTop: 0= 0
s.getTop: 1= 1
s.pop(): 10= 10
s.size(): 3= 3

exact same as the one in java. works

*/

#include <gtest/gtest.h>
#include <gmock/gmock.h>
#include "IntStack.h"


using testing::Eq;

namespace {
    class ClassDeclaration : public testing::Test {
    public:
        IntStack obj;
        ClassDeclaration() {
            obj;
        }
    };
}

TEST_F(ClassDeclaration, testCreateStack) {
    ASSERT_EQ(obj.getTop(), -1);
    std::cout << "s.getTop: " << obj.getTop() << "= -1" << std::endl;
}
TEST_F(ClassDeclaration, testPushStack) {
    obj.push(1);
    ASSERT_EQ(obj.getTop(), 0);
    std::cout << "s.getTop: " << obj.getTop() << "= 0" << std::endl;

}
TEST_F(ClassDeclaration, testPushStackTwice) {
    obj.push(1);
    obj.push(2);
    ASSERT_EQ(obj.getTop(), 1);
    std::cout << "s.getTop: " << obj.getTop() << "= 1" << std::endl;
}
TEST_F(ClassDeclaration, testPopStack) {
    obj.push(12);
    obj.push(10);
    int i = obj.pop();
    ASSERT_EQ(i, 10);
    std::cout << "s.pop(): " << i << "= 10" << std::endl;
}
TEST_F(ClassDeclaration, testStackSize) {
    obj.push(2);
    obj.push(4);
    obj.push(10);
    ASSERT_EQ(obj.size(),3);
    std::cout << "s.size(): " << obj.size() << "= 3" << std::endl;
}


/*
 *
s.getTop: -1= -1
s.getTop: 0= 0
s.getTop: 1= 2
s.pop(): 10= 10
s.size(): 3= 3
 Removed the testting process and left the output to compare with java script
[==========] 5 tests from 1 test case ran. (5 ms total)
[  PASSED  ] 5 tests.
 *
 *
 */
