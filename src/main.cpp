#include <ros/ros.h>
#include <sensor_msgs/Range.h>

#include "lidarLite.h"

int main(int argc,char **argv){
	ros::init(argc, argv, "lidar");
	ros::NodeHandle n;
	ros::Publisher lidar_pub = n.advertise<sensor_msgs::Range>("range", 1000);

    int fd, res, i, del;
    unsigned char st, ver;

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
            
            delay(del);
        }
    }
}
