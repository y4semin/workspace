#include <ros/ros.h>
#include "alignment_package/AlignmentPackage.hpp"

int main(int argc, char** argv)
{
    init(argc, argv, "alignment_package");
    ros::NodeHandle nh;
    
    ros::spin();
    return 0;
}
