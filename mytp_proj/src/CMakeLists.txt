cmake_minimum_required(VERSION 3.6)

project(Classes)

set(SOURCE_LIB Graphics/Game.cpp Classes/Units.cpp Classes/herb.cpp Classes/Food.cpp Classes/pred.cpp Tools/find_nearest.cpp Tools/find_nearest_herb.cpp Tools/random.cpp) 

add_library(Sec SHARED ${SOURCE_LIB})

#SFML#############
set(SFML_DIR "${CMAKE_SOURCE_DIR}/SFML_LIB/SFML-2.5.1/lib/cmake/SFML")
set(CMAKE_MODULE_PATH "${CMAKE_MODULE_PATH} ${CMAKE_CURRENT_LIST_DIR}/cmake_modules")
target_link_libraries(Sec sfml-graphics)
find_package(SFML 2.5 REQUIRED graphics network audio window system)
##################
