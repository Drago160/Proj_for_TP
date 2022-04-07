cmake_minimum_required(VERSION 3.6)

project(SIM)

set(CMAKE_CXX_STANDART 11)


add_executable(SIM ${CMAKE_SOURCE_DIR}/main/main.cpp)

#SFML######################
#set(SFML_DIR "${CMAKE_SOURCE_DIR}/SFML_LIB/SFML-2.5.1/lib/cmake/SFML")
#target_link_libraries(SIM sfml-graphics)
#set(CMAKE_MODULE_PATH "${CMAKE_MODULE_PATH} ${CMAKE_CURRENT_LIST_DIR}/cmake_modules")
#find_package(SFML 2.5 REQUIRED graphics network audio window system)
###########################


include_directories(include/Graphics include/Tools . include/Classes)#headers

add_subdirectory(src)

target_link_libraries(SIM Sec)





set(EXECUTABLE_OUTPUT_PATH ${PROJECT_SOURCE_DIR}/bin)
