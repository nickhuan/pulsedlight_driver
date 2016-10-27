# Overview

This provides a ROS Driver the LidarLite v1. The is modified from answer17's lidarlite. (https://github.com/answer17/lidarLite) The original driver is a cmake project written in c code for Raspberry Pi and some other Odroid board. And it depends on RPi/Odroid libraries (https://github.com/hardkernel/wiringPi).

I rosified the package and wrap it in C++, modified the device path for Odroid U3+ and also made it independent of the WiringPi libraries. Thus, this is a standalone package that works for Odroid U3+ in ROS.

rosnode: /lidar
rostopic: /lidar/range (/sensor_msgs/Range)

The launch file remaps the rostopic "lidar/range" to "pose_sensor/lidar_state_input".  https://github.com/nickhuan/pulsedlight_driver/blob/master/launch/lidar.launch#L3

This is made for Odroid U3+ with GPIO#199 set up as SCL and #200 as SDA. Set up your own I2C port accordingly.

Change the device path to make the package work for your own microprocessor: https://github.com/nickhuan/pulsedlight_driver/blob/master/src/wiringPiI2C.c#L210 
To check you device path:
user:~# install i2c tools: apt-get install libi2c-dev i2c-tools

user:~# sudo i2cdetect -l

i2c-0	i2c       	s3c2410-i2c                     	I2C adapter<br />
i2c-1	i2c       	s3c2410-i2c                     	I2C adapter<br />
i2c-2	i2c       	i2c-gpio2                       	I2C adapter<br />
i2c-3	i2c       	s3c2410-i2c                     	I2C adapter<br />
i2c-4	i2c       	i2c-gpio4                       	I2C adapter<br />
i2c-7	i2c       	s3c2410-i2c                     	I2C adapter<br />
i2c-8	i2c       	s3c2410-i2c                     	I2C adapter<br />

user:~# i2cdetect -y -r 4 #try different number from the list above (0,1,2,3,4,7 or 8) to find where 62 appears

You will see something like below:

     0  1  2  3  4  5  6  7  8  9  a  b  c  d  e  f
00:          -- -- -- -- -- -- -- -- -- -- -- -- -- <br />
10: -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- <br />
20: -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- <br />
30: -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- <br />
40: -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- <br />
50: -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- <br />
60: -- -- 62 -- -- -- -- -- -- -- -- -- -- -- -- -- <br />
70: -- -- -- -- -- -- -- --<br />

The master branch is for ROS. There is a cmake-version which can be used without ROS.
