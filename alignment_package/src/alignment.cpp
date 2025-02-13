#include "alignment_package/AlignmentPackage.hpp"


ICP_Alignment::ICP_Alignment(ros::NodeHandle& nh)

source_cloud = pcl::PointCloud<PointXYZ>::Ptr(new pcl::PointCloud<PointXYZ>);
target_cloud = pcl::PointCloud<PointXYZ>::Ptr(new pcl::PointCloud<PointXYZ>);

source_sub = nh.subscribe("/source_topic", 10, alignment_package::sourcecallback);

target_sub = nh.subscribe("/target_topic",10, alignment_package::targetcallback);

aligned_pub = nh.advertise<sensor_msgs::PointCloud2>("/aligned_cloud", 10);


void ICP_Alignment::sourceCallback(const sensor_msgs::PointCloud2ConstPtr& lidar_data)
{
    pcl::fromROSMsg(*lidar_data, *source_cloud);
}

void ICP_Alignment::targetCallback(const sensor_msgs::PointCloud2ConstPtr& lidar_data)
{
    pcl::fromROSMsg(*lidar_data, *target_cloud);
}

void ICP_Alignment::alignPointClouds()
{
    pcl::IterativeClosestPoint<pcl::PointXYZ, pcl::PointXYZ> icp;
    icp.setInputSource(source_cloud);
    icp.setInputTarget(target_cloud);
    
    pcl::PointCloud<pcl::PointXYZ> aligned_cloud;
    icp.align(aligned_cloud);

    sensor_msgs::PointCloud2 output_cloud;
    pcl::toROSMsg(aligned_cloud, output_cloud);
    output_cloud.header.frame_id = "map";
    aligned_pub.publish(output_cloud);

    Eigen::Matrix4d matrix = icp.getFinalTransformation().cast<double>();

    ROS_INFO("Rotation matrix :");
    ROS_INFO("    | %f %f %f |", matrix(0, 0), matrix(0, 1), matrix(0, 2));
    ROS_INFO("R = | %f %f %f |", matrix(1, 0), matrix(1, 1), matrix(1, 2));
    ROS_INFO("    | %f %f %f |", matrix(2, 0), matrix(2, 1), matrix(2, 2));

    ROS_INFO("Translation vector :");
    ROS_INFO("t = %f, %f, %f", matrix(0, 3), matrix(1, 3), matrix(2, 3));
