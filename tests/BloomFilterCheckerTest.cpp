#include <gtest/gtest.h>
#include "BloomFilterChecker.h"

// Test cases for BloomFilterChecker methods

// Test for a valid array size and hash functions
TEST(BloomFilterCheckerTests, ValidArraySize) {
    BloomFilterChecker checker;
    std::string input = "16 1 2";
    EXPECT_TRUE(checker.checkInput(input));
};

// Test for an invalid array size (less than 1)
TEST(BloomFilterCheckerTests, InvalidArraySize) {
    BloomFilterChecker checker;
    std::string input = "0 1 2";
    EXPECT_FALSE(checker.checkInput(input));
};

// Test for a missing hash function in the input
TEST(BloomFilterCheckerTests, MissingHashFunction) {
    BloomFilterChecker checker;
    std::string input = "8 1";
    EXPECT_TRUE(checker.checkInput(input));
};

// Test for using an invalid hash function in the input
TEST(BloomFilterCheckerTests, InvalidHashFunction) {
    BloomFilterChecker checker;
    std::string input = "16 20 3";
    EXPECT_FALSE(checker.checkInput(input));
};

// Test for an invalid input format (non-integer characters)
TEST(BloomFilterCheckerTests, InvalidInputFormat) {
    BloomFilterChecker checker;
    std::string input = "8 a 2";
    EXPECT_FALSE(checker.checkInput(input));
};

// Test for a valid input format with correct array size and hash functions
TEST(BloomFilterCheckerTests, ValidInput) {
    BloomFilterChecker checker;
    std::string input = "8 1 2";
    EXPECT_TRUE(checker.checkInput(input));
};

// Various tests for invalid input formats with non-integer characters
TEST(BloomFilterCheckerTests, InvalidInputFormat2) {
    BloomFilterChecker checker;
    std::string input = "8 1 b";
    EXPECT_FALSE(checker.checkInput(input));
};

TEST(BloomFilterCheckerTests, InvalidInputFormat2b) {
    BloomFilterChecker checker;
    std::string input = "8 1 dd";
    EXPECT_FALSE(checker.checkInput(input));
};

TEST(BloomFilterCheckerTests, InvalidInputFormat2c) {
    BloomFilterChecker checker;
    std::string input = "8 d d";
    EXPECT_FALSE(checker.checkInput(input));
};

TEST(BloomFilterCheckerTests, InvalidInputFormat2d) {
    BloomFilterChecker checker;
    std::string input = "8 dd 1";
    EXPECT_FALSE(checker.checkInput(input));
};

TEST(BloomFilterCheckerTests, InvalidInputFormat2e) {
    BloomFilterChecker checker;
    std::string input = "8 dd dd";
    EXPECT_FALSE(checker.checkInput(input));
};

// Test for an invalid input format with extra hash functions
TEST(BloomFilterCheckerTests, InvalidInputFormat3) {
    BloomFilterChecker checker;
    std::string input = "8 1 2 3";
    EXPECT_FALSE(checker.checkInput(input));
};

// Test for a valid input with duplicated hash functions
TEST(BloomFilterCheckerTests, ValidInput2) {
    BloomFilterChecker checker;
    std::string input = "8 1 2 1";
    EXPECT_TRUE(checker.checkInput(input));
};

// Test for a valid input with all hash functions being the same
TEST(BloomFilterCheckerTests, ValidInput2b) {
    BloomFilterChecker checker;
    std::string input = "8 2 2 2";
    EXPECT_TRUE(checker.checkInput(input));
};

// Test for an invalid input with missing array size
TEST(BloomFilterCheckerTests, ValidInput2c) {
    BloomFilterChecker checker;
    std::string input = "2";
    EXPECT_FALSE(checker.checkInput(input));
};
