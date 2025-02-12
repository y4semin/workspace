#include <ros/ros.h>
#include <sensor_msgs/PointCloud2.h>
#include <pcl_conversions/pcl_conversions.h>
#include <pcl/point_types.h>
#include <pcl/registration/icp.h>
#include <iostream>

void sourcecallback (const sensor_msgs::PointCloud2ConstPtr& lidar_data)
{
    ros::fromROSMsg(*lidar_data, *source_cloud);  
}


void targetcallback (const sensor_msgs::PointCloud2ConstPtr& lidar_data)
{  
    ros::fromROSMsg(*lidar_data, *target_cloud);    
}


void icp_alignment()
{
    pcl::IterativeClosestPoint<PointXYZ , PointXYZ> icp;
    icp.setInputSource(source_cloud); 
    icp.setInputTarget(target_cloud);   
    pcl::PointCloud<PointXYZ> aligned_cloud;
    icp.align(aligned_cloud);

    sensor_msgs::PointCloud2 output_cloud;
    ros::toROSMsg(aligned_cloud, output_cloud);
    output_cloud.header.frame_id = "map";  
    aligned_pub.publish(output_cloud); 


    Eigen::Matrix4d matrix = icp.getFinalTransformation ().cast<double>();
   
    ros::ROS_INFO("Rotation matrix :");
    ros::ROS_INFO("    | %f %f %f |", matrix (0, 0), matrix (0, 1), matrix (0, 2));
    ros::ROS_INFO("R = | %f %f %f |", matrix (1, 0), matrix (1, 1), matrix (1, 2));
    ros::ROS_INFO("    | %f %f %f |", matrix (2, 0), matrix (2, 1), matrix (2, 2));

    ros::ROS_INFO("Translation vector :");
    ros::ROS_INFO("t = %f, %f, %f", matrix (0, 3), matrix (1, 3), matrix (2, 3));   
}  

ros::NodeHandle& nodeHandle_;

ros::Subscriber source_sub;
ros::Subscriber target_sub;

 
std::string source_topic;
std::string target_topic;  


ros::Pusblisher aligned_pub;
  
  
  
  
  
  
  
  
  
  
  
  
