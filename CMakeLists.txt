cmake_minimum_required(VERSION 3.14)
project(LogPulse VERSION 1.0.0 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

include_directories(include)

# Main Application Executable
add_executable(log_pulse src/main.cpp src/LogParser.cpp)

# Enable Testing & Fetch GoogleTest
enable_testing()
include(FetchContent)
FetchContent_Declare(
  googletest
  URL https://github.com/google/googletest/archive/refs/tags/v1.14.0.zip
)
FetchContent_MakeAvailable(googletest)

# Unit Test Executable
add_executable(run_tests tests/test_main.cpp src/LogParser.cpp)
target_link_libraries(run_tests gtest_main)

include(GoogleTest)
gtest_discover_tests(run_tests)