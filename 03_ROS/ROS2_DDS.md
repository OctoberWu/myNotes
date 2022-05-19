### DDS  
updated on: 2021:11:30

ROS2 packages DDS but most AMR companies or robot engineers know few about DDS. This makes them use default DDS configuration.

DDS default configuration for ROS2 have two main limitations:
  * ROS2 has only one domain
  * DDS ROS2 implementation limits the number of AMR/robots to 255
  * Discovery is needed on a regular basis and creates high traffic whenever one AMR leaves or enter the network

Solution brought in by FARobot:
  * Two domains at the robot level, one for internal communication and one for the outside com.
  * DDS tuning to go beyond 255 up to 60000++ (intrinsically limited by the network capability)

Expected output:
  * Discovery bottleneck is solved.
  * Expected up to 500 robots on the network
  * QoS and others distributed network advantages from DDS are conserved