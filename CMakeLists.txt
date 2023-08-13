cmake_minimum_required(VERSION 3.14.0)
project(jank VERSION 0.1.0)

set(CMAKE_CXX_STANDARD 23)

set(DOCTEST third_party/doctest/doctest.h)

set(INCLUDE_DIR include/jank/)

set(JANK_HEADERS 
	${INCLUDE_DIR}/bit/bit.hpp
	${INCLUDE_DIR}/container/fixed_stack.hpp
	${INCLUDE_DIR}/file/file_reading.hpp)

set(JANK_SRC
    ${INCLUDE_DIR}/file/file_reading.cpp)

add_library(jank ${JANK_HEADERS} ${JANK_SRC})
set_target_properties(jank PROPERTIES LINKER_LANGUAGE CXX)
target_include_directories(jank PUBLIC include third_party)

set(JANK_TEST_HEADERS
    ${INCLUDE_DIR}/bit/bit.test.hpp
    ${INCLUDE_DIR}/container/fixed_stack.test.hpp)

add_executable(test_runner test_runner.cpp ${JANK_TEST_HEADERS} ${DOCTEST})
target_include_directories(test_runner PRIVATE third_party)
target_link_libraries(test_runner PUBLIC jank)
