cmake_minimum_required(VERSION 2.8)
project( Web )
find_package( OpenCV REQUIRED )
include_directories( ${OpenCV_INCLUDE_DIRS} )
add_executable( Web Web.cpp )
target_link_libraries( Web ${OpenCV_LIBS} )
