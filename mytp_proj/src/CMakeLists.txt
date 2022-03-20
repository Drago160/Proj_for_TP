cmake_minimum_required(VERSION 3.6)

project(Classes)

set(SOURCE_LIB Classes/Units.cpp Classes/herb.cpp Tools/find_nearest.cpp Tools/random.cpp)

add_library(Sec SHARED ${SOURCE_LIB})



