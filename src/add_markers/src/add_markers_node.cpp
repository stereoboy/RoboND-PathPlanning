#include <ros/ros.h>
#include <visualization_msgs/Marker.h>

#define MARKER_SIZE 0.3
int main( int argc, char** argv )
{
  ros::init(argc, argv, "add_markers");
  ros::NodeHandle n;
  ros::Rate r(1);
  ros::Publisher marker_pub = n.advertise<visualization_msgs::Marker>("visualization_marker", 1);

  // Set our initial shape type to be a cube
  uint32_t shape = visualization_msgs::Marker::CUBE;

  //-----------------------------------------------
  // show up at the pick up zone
  //-----------------------------------------------
  visualization_msgs::Marker marker;
  // Set the frame ID and timestamp.  See the TF tutorials for information on these.
  marker.header.frame_id = "/map";
  marker.header.stamp = ros::Time::now();

  // Set the namespace and id for this marker.  This serves to create a unique ID
  // Any marker sent with the same namespace and id will overwrite the old one
  marker.ns = "basic_shapes";
  marker.id = 0;

  // Set the marker type.  Initially this is CUBE, and cycles between that and SPHERE, ARROW, and CYLINDER
  marker.type = shape;

  // Set the marker action.  Options are ADD, DELETE, and new in ROS Indigo: 3 (DELETEALL)
  marker.action = visualization_msgs::Marker::ADD;

  // Set the pose of the marker.  This is a full 6DOF pose relative to the frame/time specified in the header
  marker.pose.position.x = 3.75;
  marker.pose.position.y = 3.75;
  marker.pose.position.z = 0;
  marker.pose.orientation.x = 0.0;
  marker.pose.orientation.y = 0.0;
  marker.pose.orientation.z = 0.0;
  marker.pose.orientation.w = 1.0;

  // Set the scale of the marker -- 1x1x1 here means 1m on a side
  marker.scale.x = MARKER_SIZE;
  marker.scale.y = MARKER_SIZE;
  marker.scale.z = MARKER_SIZE;

  // Set the color -- be sure to set alpha to something non-zero!
  marker.color.r = 0.0f;
  marker.color.g = 0.0f;
  marker.color.b = 1.0f;
  marker.color.a = 1.0;

  marker.lifetime = ros::Duration(5.0);

  // Publish the marker
  while (marker_pub.getNumSubscribers() < 1)
  {
    if (!ros::ok())
    {
      return 0;
    }
    ROS_WARN_ONCE("Please create a subscriber to the marker");
    sleep(1);
  }
  marker_pub.publish(marker);

  ROS_INFO("[MARKER] Marker shows up at the PICK-UP ZONE");
  ros::Duration(5.0).sleep();

  //-----------------------------------------------
  // hide the marker
  //-----------------------------------------------
  ROS_INFO("[MARKER] Marker hides...");
  marker.header.stamp = ros::Time::now();

  // Set the marker action.  Options are ADD, DELETE, and new in ROS Indigo: 3 (DELETEALL)
  marker.action = visualization_msgs::Marker::DELETE;
  marker_pub.publish(marker);


  ros::Duration(5.0).sleep();

  //-----------------------------------------------
  // show up at the drop off zone
  //-----------------------------------------------
  ROS_INFO("[MARKER] Marker shows up at the DROP-OFF ZONE");
  marker.header.stamp = ros::Time::now();

  // Set the marker action.  Options are ADD, DELETE, and new in ROS Indigo: 3 (DELETEALL)
  marker.action = visualization_msgs::Marker::ADD;

  // Set the pose of the marker.  This is a full 6DOF pose relative to the frame/time specified in the header
  marker.pose.position.x = 3.75;
  marker.pose.position.y = 0.0;
  marker.pose.position.z = 0.0;
  marker.pose.orientation.x = 0.0;
  marker.pose.orientation.y = 0.0;
  marker.pose.orientation.z = 0.0;
  marker.pose.orientation.w = 1.0;

  // Set the scale of the marker -- 1x1x1 here means 1m on a side
  marker.scale.x = MARKER_SIZE;
  marker.scale.y = MARKER_SIZE;
  marker.scale.z = MARKER_SIZE;

  // Set the color -- be sure to set alpha to something non-zero!
  marker.color.r = 0.0f;
  marker.color.g = 0.0f;
  marker.color.b = 1.0f;
  marker.color.a = 1.0;

  marker.lifetime = ros::Duration();

  marker_pub.publish(marker);

  // to prevent the terminal from closing up
  ros::Duration time_between_ros_wakeups(0.2);
  while (ros::ok()) {
      ros::spinOnce();
      time_between_ros_wakeups.sleep();
  }
}
