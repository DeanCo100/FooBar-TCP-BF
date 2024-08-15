cmake_minimum_required(VERSION 3.14)
project(FooBar-Project) 
set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

include(FetchContent)
FetchContent_Declare(
  googletest
  URL https://github.com/google/googletest/archive/03597a01ee50ed33e9dfd640b249b4be3799d395.zip
)

FetchContent_MakeAvailable(googletest)
enable_testing()

set(SOURCE_FILES
  src/ListExistenceChecker.cpp
  src/BloomFilter.cpp
  src/BloomFilterChecker.cpp
  src/UrlCommandChecker.cpp
  src/IterativeHash.cpp
  src/BasicHash.cpp
)

set(TEST_FILES
  tests/test_main.cpp
  tests/ListExistenceCheckerTest.cpp
  tests/BloomFilterTest.cpp
  tests/BloomFilterCheckerTest.cpp
  tests/BasicHashTest.cpp
  tests/IterativeHashTest.cpp
  tests/UrlCommandCheckerTests.cpp
)

add_executable(FilterTests ${TEST_FILES} ${SOURCE_FILES})
target_link_libraries(FilterTests PRIVATE gtest gtest_main)
target_include_directories(FilterTests PRIVATE src tests)
target_include_directories(FilterTests PRIVATE src headers)
include(GoogleTest)
gtest_discover_tests(FilterTests)

