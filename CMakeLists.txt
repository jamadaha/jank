cmake_minimum_required(VERSION 3.14.0)
project(jank VERSION 0.1.0)

set(CMAKE_CXX_STANDARD 23)

set(DOCTEST third_party/doctest/doctest.h)

set(INCLUDE_DIR include/jank/)

set(JANK_HEADERS 
	${INCLUDE_DIR}/bit/bit.hpp)

add_library(jank ${JANK_HEADERS} ${DOCTEST})
set_target_properties(jank PROPERTIES LINKER_LANGUAGE CXX)
target_include_directories(jank PUBLIC include third_party)

add_executable(test_runner test_runner.cpp ${DOCTEST})
target_include_directories(test_runner PRIVATE third_party)
target_link_libraries(test_runner PUBLIC jank)
