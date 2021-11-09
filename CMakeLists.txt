cmake_minimum_required(VERSION 3.20)
project(CSE474)

find_package(BISON REQUIRED)
find_package(FLEX REQUIRED)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -fsanitize=address -fsanitize=undefined -fno-omit-frame-pointer -g")

bison_target(bison bison.yy ${CMAKE_CURRENT_SOURCE_DIR}/bison.cpp
        DEFINES_FILE ${CMAKE_CURRENT_SOURCE_DIR}/bison.h)
flex_target(flex flex.ll ${CMAKE_CURRENT_SOURCE_DIR}/flex.cpp)
add_flex_bison_dependency(flex bison)

set(SOURCES ${BISON_bison_OUTPUT_SOURCE} ${FLEX_flex_OUTPUTS})
add_library(parser STATIC ${SOURCES})

add_executable(CSE474 main.cpp driver.cpp)
target_link_libraries(CSE474 parser)