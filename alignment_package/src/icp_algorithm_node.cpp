int main(int argc, char** argv)
{
    init(argc, argv, "alignment");
    NodeHandle nh;

    aligned_pub = nh.advertise<sensor_msgs::PointCloud2>("/aligned_cloud", 10);

    Subscriber source_sub = nh.subscribe("/cloud_all_fields_fullframe", 10, sourcecallback);
    Subscriber target_sub = nh.subscribe("/velodyne_points",10, targetcallback);
    spin();
    icp_alignment();  

    return 0;
}
