cmake_minimum_required (VERSION 2.6)
project (lidarTest)
include_directories(src)
add_executable(lidarTest 
		src/lidarTest.c 
		src/lidarLite.c 
		src/lidarLite.h
		src/wiringPiI2C.c
		src/wiringPiI2C.h
		src/wiringPi.c
		src/wiringPi.h
		src/softPwm.c
		src/softPwm.h
		src/softTone.c
		src/softTone.h)
target_link_libraries (lidarTest pthread)
