cmake_minimum_required(VERSION 3.22)
project(elbit_home_assignment)

set(CMAKE_CXX_STANDARD 14)

#set(ENV{OpenCV_DIR} C:\\Users\\User\\OneDrive\\sm-6\\homeassignment-cpp2-Elbit\\opencv\\build)
#set(CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} "${CMAKE_SOURCE_DIR}/cmake/")

#find_package(OpenCV REQUIRED)

#include_directories(${OpenCV_INCLUDE_DIRS})

#target_link_libraries(elbit_home_assignment ${OpenCV_LIBS})

add_executable(elbit_home_assignment question01.cpp question02.cpp question03.cpp question04.cpp question05.cpp bonus.cpp)

