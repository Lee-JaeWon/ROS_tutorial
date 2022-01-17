#include "ros/ros.h"
#include "seminar_3/SrvTutorial.h"

#include <cstdlib>

int main(int argc, char **argv)
{
  ros::init(argc, argv, "seminar_client");
  if (argc != 3)
  {
    ROS_INFO("Only 2 args need");
    return 1;
  }

  ros::NodeHandle nh;
  ros::ServiceClient client = nh.serviceClient<seminar_3::SrvTutorial>("baram_service");
  seminar_3::SrvTutorial srv;

  srv.request.a = atoll(argv[1]);
  srv.request.b = atoll(argv[2]);
  if (client.call(srv))
  {
    ROS_INFO("send srv, srv.Request.a and b : %ld, %ld", (long int)srv.request.a, (long int)srv.request.b);
    ROS_INFO("receive srv, srv.Response.result: x -> %f, y ->% f", (float)srv.response.x, (float)srv.response.y);
  }
  else
  {
    ROS_ERROR("Failed to call service baram_service");
    return 1;
  }

  return 0;
}
