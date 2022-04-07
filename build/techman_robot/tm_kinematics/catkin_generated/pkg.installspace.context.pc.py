# generated from catkin/cmake/template/pkg.context.pc.in
CATKIN_PACKAGE_PREFIX = ""
PROJECT_PKG_CONFIG_INCLUDE_DIRS = "${prefix}/include".split(';') if "${prefix}/include" != "" else []
PROJECT_CATKIN_DEPENDS = "roscpp;geometry_msgs;moveit_core;moveit_ros_planning;pluginlib;tf_conversions".replace(';', ' ')
PKG_CONFIG_LIBRARIES_WITH_PREFIX = "-ltm700_kin;-ltm900_kin;-ltm700_moveit_plugin;-ltm900_moveit_plugin;-ltm1100_kin;-ltm1300_kin;-ltm1100_moveit_plugin;-ltm1300_moveit_plugin".split(';') if "-ltm700_kin;-ltm900_kin;-ltm700_moveit_plugin;-ltm900_moveit_plugin;-ltm1100_kin;-ltm1300_kin;-ltm1100_moveit_plugin;-ltm1300_moveit_plugin" != "" else []
PROJECT_NAME = "tm_kinematics"
PROJECT_SPACE_DIR = "/home/yc/Lab506_ws/install"
PROJECT_VERSION = "0.0.0"
