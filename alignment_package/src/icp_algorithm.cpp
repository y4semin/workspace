#include "alignment_package/AlignmentPackage.hpp"
#include <string>

namespace alignment_package

pcl::PointCloud<PointXYZ>::Ptr source_cloud (new pcl::PointCloud<PointXYZ>);
pcl::PointCloud<PointXYZ>::Ptr target_cloud (new pcl::PointCloud<PointXYZ>);

Subscriber source_sub = nh.subscribe("/source_topic", 10, alignment_package::sourcecallback);

Subscriber target_sub = nh.subscribe("/target_topic",10, alignment_package::targetcallback);

aligned_pub = nh.advertise<sensor_msgs::PointCloud2>("/aligned_cloud", 10);
