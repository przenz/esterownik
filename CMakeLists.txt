cmake_minimum_required(VERSION 3.16)
project(esterownik)

set(CMAKE_CXX_STANDARD 17)

include_directories(lib/httplib)
include_directories(lib/rapidxml)
include_directories(include)

add_subdirectory(test)

set(SOURCE_FILES main.cpp src/EcoalDataCollector.cpp src/EcoalDataSource.cpp src/EcoalDataParaser.cpp)

add_executable(esterownik ${SOURCE_FILES})
