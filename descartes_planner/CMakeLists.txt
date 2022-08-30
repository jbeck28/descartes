cmake_minimum_required(VERSION 3.5)
project(descartes_planner)

# default to c++17
if(NOT CMAKE_CXX_STANDARD)
  set(CMAKE_CXX_STANDARD 17)
  set(CMAKE_CXX_STANDARD_REQUIRED ON)
endif()

#find_package(catkin REQUIRED COMPONENTS
#  cmake_modules
#  descartes_core
#  descartes_trajectory
# pluginlib
#  roscpp
#)
find_package(ament_cmake REQUIRED)
find_package(descartes_core REQUIRED)
find_package(descartes_trajectory REQUIRED)
find_package(rclcpp REQUIRED)
find_package(urdf REQUIRED)
find_package(pluginlib REQUIRED)
#find_package(Boost REQUIRED)
find_package(Eigen3 REQUIRED)

# Let's try to use open-mp parallization if we can
find_package(OpenMP)
if (OPENMP_FOUND)
  message(STATUS "Descartes will use OpenMP")
  set(OpenMP_FLAGS ${OpenMP_CXX_FLAGS})
endif()

# Eigen 3.2 (Wily) only provides EIGEN3_INCLUDE_DIR, not EIGEN3_INCLUDE_DIRS
if(NOT EIGEN3_INCLUDE_DIRS)
  set(EIGEN3_INCLUDE_DIRS ${EIGEN3_INCLUDE_DIR})
endif()


###########
## Build ##
###########
include_directories(include
)

## DescartesTrajectoryPt lib
add_library(${PROJECT_NAME}
            src/dense_planner.cpp
            src/ladder_graph_dag_search.cpp
            src/planning_graph.cpp
            src/plugin_init.cpp
            src/sparse_planner.cpp
)

target_link_libraries(${PROJECT_NAME}
                      ${OpenMP_FLAGS}
)
target_include_directories(${PROJECT_NAME} PRIVATE

<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>

<INSTALL_INTERFACE:include>)

ament_target_dependencies(
  ${PROJECT_NAME}
  descartes_core
  descartes_trajectory
  rclcpp
  pluginlib
  urdf
)

target_compile_options(${PROJECT_NAME} PRIVATE ${OpenMP_FLAGS})


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
