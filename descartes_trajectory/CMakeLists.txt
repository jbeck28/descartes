cmake_minimum_required(VERSION 3.5)
project(descartes_trajectory)

# default to c++17
if(NOT CMAKE_CXX_STANDARD)
  set(CMAKE_CXX_STANDARD 17)
  set(CMAKE_CXX_STANDARD_REQUIRED ON)
endif()

find_package(ament_cmake REQUIRED)
find_package(rclcpp REQUIRED)
find_package(descartes_core REQUIRED)
find_package(moveit REQUIRED)
find_package(moveit_ros_planning_interface REQUIRED)
find_package(moveit_kinematics REQUIRED)
find_package(moveit_core REQUIRED)
find_package(moveit_ros REQUIRED)


###########
## Build ##
###########

include_directories(include
)

add_library(${PROJECT_NAME}
            src/axial_symmetric_pt.cpp
            src/cart_trajectory_pt.cpp
            src/joint_trajectory_pt.cpp
)

#target_link_libraries(${PROJECT_NAME}
#)
target_include_directories(${PROJECT_NAME} PRIVATE

<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>

<INSTALL_INTERFACE:include>)

ament_target_dependencies(
  ${PROJECT_NAME}
  moveit_core
  descartes_core
)


#############
## Install ##
#############
install(DIRECTORY include/
  DESTINATION include
)

install(TARGETS ${PROJECT_NAME}
  RUNTIME DESTINATION bin
  ARCHIVE DESTINATION lib
  LIBRARY DESTINATION lib
)

ament_export_dependencies(
  ${THIS_PACKAGE_INCLUDE_DEPENDS}
)

ament_export_include_directories(
  include
)
ament_export_libraries(
  ${PROJECT_NAME}
)
ament_package()

