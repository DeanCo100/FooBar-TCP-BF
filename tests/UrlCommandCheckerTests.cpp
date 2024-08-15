#include <gtest/gtest.h>
#include "UrlCommandChecker.h"
#include <string>
#include <iostream>

// Tests for UrlCommandChecker Class

// Valid input check
TEST(UrlCommandCheckerTests, ValidInput) {
    UrlCommandChecker urlChecker;
    std:: string input = "1 www.example.com0";
    EXPECT_TRUE(urlChecker.checkInput(input));
}

// Invalid input check
TEST(UrlCommandCheckerTests, InValidInput) {
    UrlCommandChecker urlChecker;
    std:: string input = "2aaa www.example.com0";
    EXPECT_FALSE(urlChecker.checkInput(input));
}


// Invalid command check: integer that is not 1 or 2
TEST(UrlCommandCheckerTests, InvalidIntegerCommand) {
    UrlCommandChecker urlChecker;
    std::istringstream commandStream("3");
    EXPECT_FALSE(urlChecker.isValidCommand(commandStream));
}

// Invalid command check: string that is not 1 or 2
TEST(UrlCommandCheckerTests, InvalidStringCommand) {
    UrlCommandChecker urlChecker;
    std::istringstream commandStream("aaa");
    EXPECT_FALSE(urlChecker.isValidCommand(commandStream));
}

//Invalid command check: integer and string together
TEST(UrlCommandCheckerTests, InvalidIntegerStringCommand) {
    UrlCommandChecker urlChecker;
    std::istringstream commandStream("2a");
    EXPECT_FALSE(urlChecker.isValidCommand(commandStream));
}

// Missing command check
TEST(UrlCommandCheckerTests,MissingCommand) {
    UrlCommandChecker urlChecker;
    std:: string input = "www.example.com0";
    EXPECT_FALSE(urlChecker.checkInput(input));
}

// Missing Url check
TEST(UrlCommandCheckerTests, MissimgUrl) {
    UrlCommandChecker urlChecker;
    std:: string input = "1";
    EXPECT_FALSE(urlChecker.checkInput(input));
}

// Empty input check
TEST(UrlCommandCheckerTests, EmptyInput) {
    UrlCommandChecker urlChecker;
    std:: string input = "";
    EXPECT_FALSE(urlChecker.checkInput(input));
}

// Mixed uppercase and lower case
TEST(UrlCommandCheckerTests, MixedValidInput) {
    UrlCommandChecker urlChecker;
    std:: string input = "1 WWW.ExAmPle.COM";
    EXPECT_TRUE(urlChecker.checkInput(input));
}