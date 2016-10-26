# Overview

This provides a simple C interface to the LidarLite. This is forked from answer17's lidarlite. (https://github.com/answer17/lidarLite)

This is made for Odroid U3+ with GPIO#199 set up as SCL and #200 as SDA. I copied several wiring libraries from https://github.com/hardkernel/wiringPi to make it standalone.

Change the device path to make the package work for your own microprocessor: https://github.com/nickhuan/pulsedlight_driver/blob/master/src/wiringPiI2C.c#L210 

The master branch is for ROS. There is a cmake-version which can be used without ROS.
