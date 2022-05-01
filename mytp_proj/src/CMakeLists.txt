cmake_minimum_required(VERSION 3.6)

project(Classes)

add_subdirectory(Tools/math)

set(SOURCE_LIB

	Graphics/menu/about.cpp
	Graphics/menu/menu.cpp

       	Graphics/Drawer.cpp 
	Graphics/score.cpp
	
	Game/Game.cpp	

	Control/Updater.cpp
	Control/Controller.cpp
	Control/FoodSpamer.cpp 

	Classes/Units.cpp
	Classes/herb.cpp
	Classes/Food.cpp
       	Classes/pred.cpp
	Classes/omni.cpp

	Tools/find_nearest.cpp
	Tools/find_nearest_herb.cpp
) 

add_library(Sec SHARED ${SOURCE_LIB})

#SFML#############
set(SFML_DIR "${CMAKE_SOURCE_DIR}/SFML_LIB/SFML-2.5.1/lib/cmake/SFML")
set(CMAKE_MODULE_PATH "${CMAKE_MODULE_PATH} ${CMAKE_CURRENT_LIST_DIR}/cmake_modules")
target_link_libraries(Sec sfml-graphics)
find_package(SFML 2.5 REQUIRED graphics network audio window system)
##################
target_link_libraries(Sec Math)
