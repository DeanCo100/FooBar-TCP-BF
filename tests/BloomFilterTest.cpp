#include <gtest/gtest.h>
#include "BloomFilter.h"

// Constant declarations
const int SIZE_CHECK = 8;
const std::string INPUT_EXAMPLE = "example";
const std::string CLEAN_INPUT = "good address";

// Test to check if the input is inserted to the BloomFilter
TEST(BloomFilterTest, InsertCheck)
{
    std::vector<int> userInput = {1, 2};
    BloomFilter filter(SIZE_CHECK, userInput);
    filter.insert(INPUT_EXAMPLE);
    EXPECT_TRUE(filter.lookup(INPUT_EXAMPLE));
};

// Multiple insertion check
TEST(BloomFilterTest, MultipleInsertionsCheck)
{
    std::vector<int> userInput = {1, 2};
    BloomFilter filter(SIZE_CHECK, userInput);

    // Insert multiple distinct inputs
    filter.insert("example");
    filter.insert("second example");
    filter.insert("third example");

    // Verify each inserted input is present
    EXPECT_TRUE(filter.lookup("example"));
    EXPECT_TRUE(filter.lookup("second example"));
    EXPECT_TRUE(filter.lookup("third example"));
};

// Negative test to check if an incorrect input is not present in the BloomFilter
TEST(BloomFilterTest, NegativeCheck)
{
    std::vector<int> userInput = {1, 2};
    BloomFilter filter1(SIZE_CHECK, userInput);
    filter1.insert("www.example.com0");
    EXPECT_FALSE(filter1.lookup("www.example.com1"));
};

// Test to check if a non-existing address is not in the BloomFilter
TEST(BloomFilterTest, NonExistentCheck)
{
    std::vector<int> userInput = {1, 2};
    BloomFilter filter(SIZE_CHECK, userInput);
    EXPECT_FALSE(filter.lookup(CLEAN_INPUT));
};

// Test to check False Positives in bloom filter
TEST(BloomFilterTest, FalsePositiveCheck)
{
    std::vector<int> userInput = {1, 2};
    BloomFilter filter(SIZE_CHECK, userInput);
    filter.insert("www.example.com0");
    EXPECT_TRUE(filter.isFalsePositive("www.example.com11"));
};