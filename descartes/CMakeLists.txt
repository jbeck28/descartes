cmake_minimum_required(VERSION 3.5)
project(descartes)
# find_package(catkin REQUIRED)
# catkin_metapackage()
find_package(ament_cmake REQUIRED)

if(BUILD_TESTING)
    find_package(ament_lint_auto REQUIRED)
    set(ament_cmake_flake8_FOUND True)
    ament_lint_auto_find_test_dependencies()
endif()

ament_package()