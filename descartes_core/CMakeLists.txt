cmake_minimum_required(VERSION 3.5)
project(descartes_core)

# add_compile_options(-std=c++11 -Wall -Wextra)
if(NOT CMAKE_CXX_STANDARD)
  set(CMAKE_CXX_STANDARD 17)
  set(CMAKE_CXX_STANDARD_REQUIRED ON)
endif()

#find_package(Boost REQUIRED)
find_package(Eigen3 REQUIRED)
find_package(ament_cmake REQUIRED)
find_package(rclcpp REQUIRED)
find_package(eigen_stl_containers REQUIRED)
find_package(moveit_msgs REQUIRED)
find_package(moveit_core REQUIRED)
find_package(eigen_stl_containers REQUIRED)
# Eigen 3.2 (Wily) only provides EIGEN3_INCLUDE_DIR, not EIGEN3_INCLUDE_DIRS
if(NOT EIGEN3_INCLUDE_DIRS)
  set(EIGEN3_INCLUDE_DIRS ${EIGEN3_INCLUDE_DIR})
endif()

#catkin_package(
#  INCLUDE_DIRS
#    include
#  LIBRARIES
#    ${PROJECT_NAME}
#  CATKIN_DEPENDS
#    moveit_core
#    roscpp
#  DEPENDS
#    Boost
#    EIGEN3
#)

###########
## Build ##
###########
include_directories(include
${EIGEN3_INCLUDE_DIRS}
${EIGEN3_INCLUDE_DIR}
)

add_library(${PROJECT_NAME}
            src/trajectory_id.cpp
)

target_include_directories(${PROJECT_NAME} PUBLIC

<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>

<INSTALL_INTERFACE:include>)


ament_target_dependencies(
  ${PROJECT_NAME}
  moveit_msgs
  rclcpp
  moveit_core
  eigen_stl_containers
)

target_link_libraries(${PROJECT_NAME} )

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
  eigen_stl_containers
)

ament_export_include_directories(
  include
)
ament_export_libraries(
  ${PROJECT_NAME}
)
#ament_export_targets("export_${PROJECT_NAME}")
ament_package()
