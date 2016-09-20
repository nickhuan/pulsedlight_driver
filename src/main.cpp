#include <ros/ros.h>
#include <sensor_msgs/Range.h>

#include "lidarLite.h"

int main(int argc,char **argv){
	ros::init(argc, argv, "lidar");
	ros::NodeHandle n;
	ros::Publisher lidar_pub = n.advertise<sensor_msgs::Range>("/lidar/range", 10);

    int fd, res, i, del;
    unsigned char st, ver;
    sensor_msgs::Range msg;
    msg.max_range = 40; //in meter
    msg.min_range = 0;

    // First arg is delay in ms (default is 1000)
    if (argc > 1) 
       del = atoi(argv[1]);
    else del=1000;
    
    fd = lidar_init(true);
   
    if (fd == -1) {
        printf("initialization error\n");
    }
    else {
        while(ros::ok()){
            res = lidar_read(fd);
            st = lidar_status(fd);
            //ver = lidar_version(fd);
            
            printf("%3.0d cm \n", res);
            lidar_status_print(st);
            
            //TODO: fill up the message for rostopic /lidar/range
            msg.header.stamp = ros::Time::now();
            msg.range = res/100.0; //convert centimeter into meter
            lidar_pub.publish(msg);

            delay(del);
        }
    }
}
