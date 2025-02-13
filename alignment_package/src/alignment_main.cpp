#include <ros/ros.h>
#include "alignment_package/AlignmentPackage.hpp"

int main(int argc, char** argv)
{
    ros::init(argc, argv, "alignment_package_node");
    ICP_Alignment icp_alignment(nh);
    ros::NodeHandle nh;
    ros::spin();
    return 0;
}
