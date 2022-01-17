#include "ros/ros.h"
#include "geometry_msgs/Twist.h"
#include "turtlesim/Pose.h"
#include "seminar_3/SrvTutorial.h"

// 요청 받았을때만 publish하기 위한 flag
bool flag;

geometry_msgs::Twist cmd_vel;
turtlesim::Pose cur_pose;

bool calculation(seminar_3::SrvTutorial::Request &req,
				 seminar_3::SrvTutorial::Response &res)
{	
	//-----------------------------------
	cmd_vel.linear.x = req.a;
	cmd_vel.linear.y = 0.0;
	cmd_vel.linear.z = 0.0;
	cmd_vel.angular.x = 0.0;
	cmd_vel.angular.y = 0.0;
	cmd_vel.angular.z = req.b;
	//-----------------------------------

	// .srv의 response에 결과 전달
	//-----------------------------------
	res.x = cur_pose.x;
	res.y = cur_pose.y;
	//-----------------------------------

	ROS_INFO("request : x = %ld, y = %ld", (long int)req.a, (long int)req.b);

	flag = true;

	return true;
}

// subscribe callback 함수
void callback(const turtlesim::Pose::ConstPtr &lis)
{
	cur_pose.x = lis->x;
	cur_pose.y = lis->y;	
}

int main(int argc, char **argv)
{
	ros::init(argc, argv, "seminar_srv");
	ros::NodeHandle nh;

	ros::ServiceServer service_server = nh.advertiseService("baram_service", calculation);

	ros::Publisher cmd_pub = nh.advertise<geometry_msgs::Twist>("/turtle1/cmd_vel", 1000);

	ros::Subscriber cmd_sub = nh.subscribe<turtlesim::Pose>("/turtle1/pose", 1000, callback);

	ROS_INFO("ready srv server!");

	while (ros::ok())
	{
		if (flag)
		{
			cmd_pub.publish(cmd_vel);

			flag = false;
		}

		ros::spinOnce();
	}

	return 0;
}
