#ifndef ALIGNMENTPACKAGE_HPP
#define ALIGNMENTPACKAGE_HPP

#include <ros/ros.h>
#include <sensor_msgs/PointCloud2.h>
#include <pcl_conversions/pcl_conversions.h>
#include <pcl/point_types.h>
#include <pcl/registration/icp.h>
#include <Eigen/Dense>

class ICP_Alignment
{
public:
    ICP_Alignment(ros::NodeHandle& nh);
    void sourceCallback(const sensor_msgs::PointCloud2ConstPtr& lidar_data);
    void targetCallback(const sensor_msgs::PointCloud2ConstPtr& lidar_data);
    void alignPointClouds();

private:
    ros::Publisher aligned_pub;
    ros::Subscriber source_sub, target_sub;
    pcl::PointCloud<pcl::PointXYZ>::Ptr source_cloud;
    pcl::PointCloud<pcl::PointXYZ>::Ptr target_cloud;
};

#endif

