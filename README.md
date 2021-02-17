# ROS_tutorial


## Ubuntu와 ROS 기본학습
- Ubuntu 14.04와 ROS indigo 설치 및 개발환경 설정
- 추후 실제 개발과 다른 버전의 ROS 사용을 위한 기본 학습  
- Oracle VM VirtualBox 사용  

## Ubuntu 16.04 + ROS Kinetic
- https://releases.ubuntu.com/xenial/
- http://wiki.ros.org/kinetic/Installation/Ubuntu
- ROS Kinetic ONLY supports Wily (Ubuntu 15.10), Xenial (Ubuntu 16.04) and Jessie (Debian 8) for debian packages.  

- ### Part 1
  1. Ubuntu 16.04(LTS) 설치
  2. `sudo apt-get install chrony`  
  3. `sudo apt-get install ntpdate`  
  4. `sudo ntpdate ntp.ubuntu.com` -> 서버시간 동기화  
  5. http://wiki.ros.org/kinetic/Installation/Ubuntu의 1.4 Installation의 첫번째까지 진행 후  
  6. `sudo apt-get upgrade` 진행  

- ### Part 2
  1. http://wiki.ros.org/kinetic/Installation/Ubuntu
  2. `sudo apt-get install ros-kinetic-desktop-full`
  3. 
