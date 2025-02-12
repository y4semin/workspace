#include <ros/ros.h>
#include <sensor_msgs/PointCloud2.h>

void sourcecallback (const sensor_msgs::PointCloud2ConstPtr& lidar_data);

void targetcallback (const sensor_msgs::PointCloud2ConstPtr& lidar_data);

void icp_alignment();
