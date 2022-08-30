cmake_minimum_required(VERSION 3.5)
project(descartes_utilities)

if(NOT CMAKE_CXX_STANDARD)
  set(CMAKE_CXX_STANDARD 17)
  set(CMAKE_CXX_STANDARD_REQUIRED ON)
endif()


find_package(ament_cmake REQUIRED)
find_package(descartes_core REQUIRED)
find_package(descartes_trajectory REQUIRED)
find_package(trajectory_msgs REQUIRED)
find_package(urdf REQUIRED)
find_package(rclcpp REQUIRED)

include_directories(
  include
)

add_library(${PROJECT_NAME}
  src/ros_conversions.cpp
)

target_include_directories(${PROJECT_NAME} PUBLIC

<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>

<INSTALL_INTERFACE:include>)

ament_target_dependencies(
  ${PROJECT_NAME}
  descartes_core
  descartes_trajectory
  trajectory_msgs
  urdf
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
  trajectory_msgs
  urdf
  rclcpp
)
ament_export_include_directories(
  include
)
ament_export_libraries(
  ${PROJECT_NAME}
)
ament_package()

