#include "ListExistenceChecker.h"
#include <gtest/gtest.h>

// Test fixture for ListExistenceChecker class
class ListExistenceCheckerTest : public ::testing::Test {
protected:
    ListExistenceChecker checker;
    std::list<std::string> list;

    // Setup function to initialize common objects before each test
    void SetUp() override {
        list = {"apple", "banana", "cherry"};
    }
};

// Test for checking if a value exists in the list
TEST_F(ListExistenceCheckerTest, ValueExists) {
    // The value "banana" should exist in the list
    EXPECT_TRUE(checker.isExist(list, "banana"));
};

// Test for checking if a value does not exist in the list
TEST_F(ListExistenceCheckerTest, ValueDoesNotExist) {
    // The value "dragonfruit" should not exist in the list
    EXPECT_FALSE(checker.isExist(list, "dragonfruit"));
};

// Test for checking if a value exists in an empty list
TEST_F(ListExistenceCheckerTest, EmptyList) {
    std::list<std::string> emptyList;
    // The value "kiwi" should not exist in an empty list
    EXPECT_FALSE(checker.isExist(emptyList, "kiwi"));
};

// Test for checking if an empty value exists in the list
TEST_F(ListExistenceCheckerTest, EmptyValue) {
    // An empty value should not exist in the list
    EXPECT_FALSE(checker.isExist(list, ""));
};

// Test for checking if an empty value exists in a list containing empty strings
TEST_F(ListExistenceCheckerTest, ListWithEmptyStrings) {
    std::list<std::string> listWithEmpty = {"", "banana", ""};
    // An empty value should exist in a list containing empty strings
    EXPECT_TRUE(checker.isExist(listWithEmpty, ""));
};
