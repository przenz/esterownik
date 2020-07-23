cmake_minimum_required(VERSION 3.16)


include(FetchContent)
FetchContent_Declare(
        googletest
        GIT_REPOSITORY https://github.com/google/googletest.git
        GIT_TAG        release-1.10.0
)
FetchContent_MakeAvailable(googletest)

enable_testing()
add_executable(unit_tests main.cpp)
target_link_libraries(unit_tests gtest gtest_main)
