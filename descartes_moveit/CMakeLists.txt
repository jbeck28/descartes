cmake_minimum_required(VERSION 3.5)
project(descartes_moveit)

# default to c++17
if(NOT CMAKE_CXX_STANDARD)
  set(CMAKE_CXX_STANDARD 17)
  set(CMAKE_CXX_STANDARD_REQUIRED ON)
endif()

#find_package(catkin REQUIRED COMPONENTS
 # cmake_modules
 # descartes_core
 # descartes_trajectory
 # moveit_core
 # moveit_ros_planning
 # pluginlib
 # rosconsole_bridge
 # tf
#)
find_package(ament_cmake REQUIRED)
find_package(descartes_core REQUIRED)
find_package(descartes_trajectory REQUIRED)
find_package(moveit_core REQUIRED)
find_package(moveit_ros_planning REQUIRED)
find_package(pluginlib REQUIRED)
#find_package(Boost REQUIRED)
find_package(Eigen3 REQUIRED)

# Eigen 3.2 (Wily) only provides EIGEN3_INCLUDE_DIR, not EIGEN3_INCLUDE_DIRS
if(NOT EIGEN3_INCLUDE_DIRS)
  set(EIGEN3_INCLUDE_DIRS ${EIGEN3_INCLUDE_DIR})
endif()


###########
## Build ##
###########
include_directories(include
)

## Descartes MoveIt lib
add_library(${PROJECT_NAME}
            src/ikfast_moveit_state_adapter.cpp
            src/moveit_state_adapter.cpp
            src/plugin_init.cpp
            src/seed_search.cpp
            src/test_object.cpp
)

target_include_directories(${PROJECT_NAME} PUBLIC

<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>

<INSTALL_INTERFACE:include>)

ament_target_dependencies(
  ${PROJECT_NAME}
  moveit_core
  descartes_core
  descartes_trajectory
  moveit_ros_planning
  pluginlib
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
  moveit_core
  descartes_core
  descartes_trajectory
  moveit_ros_planning
  pluginlib
)
ament_export_include_directories(
  include
)
ament_export_libraries(
  ${PROJECT_NAME}
)
ament_package()
