cmake_minimum_required(VERSION 3.6)

project(Math)

set(CMAKE_CXX_STANDART 11)

set(SOURCE_MATH_LIB

	math_func.cpp
	random.cpp
)

add_library(Math SHARED ${SOURCE_MATH_LIB})
