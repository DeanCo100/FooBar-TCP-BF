#include "IterativeHash.h" 
#include <gtest/gtest.h>

// Constant declaration for the hash size used in tests
const int SIZE_CHECK = 2;

// Test for checking the consistency of the hash function
TEST(IterativeHash, ConsistencyTest) {
    // Initialize an IterativeHash object with the specified size
    IterativeHash hashObject(SIZE_CHECK);
    std::string testString = "consistent";
    
    // Applying the hash function twice on the same input should produce the same result
    size_t firstHash = hashObject.applyHash(testString);
    size_t secondHash = hashObject.applyHash(testString);

    EXPECT_EQ(firstHash, secondHash);
};

// Test for checking that different inputs produce different hash values
TEST(IterativeHash, DifferentInputDifferentHashTest) {
    // Initialize an IterativeHash object with the specified size
    IterativeHash hashObject(SIZE_CHECK);
    std::string input1 = "hello";
    std::string input2 = "world";

    // Applying the hash function on different inputs should produce different results
    size_t hash1 = hashObject.applyHash(input1);
    size_t hash2 = hashObject.applyHash(input2);

    EXPECT_NE(hash1, hash2);
};

// Test for checking the hash value of an empty string
TEST(IterativeHash, EmptyStringTest) {
    // Initialize an IterativeHash object with the specified size
    IterativeHash hashObject(SIZE_CHECK);
    std::string emptyString = "";
    
    // The hash value of an empty string should not be zero
    size_t hashValue = hashObject.applyHash(emptyString);

    EXPECT_NE(hashValue, 0);
};

// Test for checking the hash value of a large string
TEST(IterativeHash, LargeStringTest) {
    // Initialize an IterativeHash object with the specified size
    IterativeHash hashObject(SIZE_CHECK);
    std::string largeString(1000, 'x'); // String of 1000 'x' characters

    // The hash value of a large string should not be zero
    size_t hashValue = hashObject.applyHash(largeString);

    EXPECT_NE(hashValue, 0);
};

// Test for checking that a small change in input produces a different hash value
TEST(IterativeHash, SmallChangeDifferentHashTest) {
    // Initialize an IterativeHash object with the specified size
    IterativeHash hashObject(SIZE_CHECK);
    std::string input1 = "test";
    std::string input2 = "tost";

    // Changing a single character in the input should produce a different hash value
    size_t hash1 = hashObject.applyHash(input1);
    size_t hash2 = hashObject.applyHash(input2);

    EXPECT_NE(hash1, hash2);
};
