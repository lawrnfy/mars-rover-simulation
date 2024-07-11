cmake_minimum_required(VERSION 3.5)
project(mars_rover_simulation)

# Set C++ standard
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Find necessary packages
find_package(catkin REQUIRED COMPONENTS
  roscpp
  rospy
  std_msgs
  # Add any other ROS packages you might need
)

# Catkin specific configuration
catkin_package(
  CATKIN_DEPENDS roscpp rospy std_msgs
  # Add any other ROS packages you depend on
)

# Include directories
include_directories(
  ${catkin_INCLUDE_DIRS}
)

# Build the Mars rover node executable
add_executable(mars_rover_node src/mars_rover_node.cpp)

# Link the executable with catkin libraries
target_link_libraries(mars_rover_node
  ${catkin_LIBRARIES}
)

# Install
install(TARGETS mars_rover_node
  RUNTIME DESTINATION ${CATKIN_PACKAGE_BIN_DESTINATION}
)
