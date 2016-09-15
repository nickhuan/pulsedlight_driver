cmake_minimum_required (VERSION 2.6)
project(lidar)

find_package(catkin REQUIRED COMPONENTS
  roscpp
  rospy
)

catkin_package()

include_directories(
	${catkin_INCLUDE_DIRS}
	include)
	
add_executable(lidar
	src/main.cpp 
	src/lidarLite.c 
	include/lidarLite.h
	src/wiringPiI2C.c
	include/wiringPiI2C.h
) 

target_link_libraries (lidar
${catkin_LIBRARIES}
#pthread
)
