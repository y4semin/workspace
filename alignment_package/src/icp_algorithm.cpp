
#include "alignment_package/AlignmentPackage.hpp"

Subscriber source_sub = nh.subscribe("/cloud_all_fields_fullframe", 10, sourcecallback);
Subscriber target_sub = nh.subscribe("/velodyne_points",10, targetcallback);
