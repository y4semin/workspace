#include "alignment_package/AlignmentPackage.hpp"
#include <string>

pcl::PointCloud<PointXYZ>::Ptr source_cloud (new pcl::PointCloud<PointXYZ>);
pcl::PointCloud<PointXYZ>::Ptr target_cloud (new pcl::PointCloud<PointXYZ>);

Subscriber source_sub = nh.subscribe("/cloud_all_fields_fullframe", 10, sourcecallback);
Subscriber target_sub = nh.subscribe("/velodyne_points",10, targetcallback);
