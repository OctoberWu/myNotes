cmake_minimum_required(VERSION 3.5)
project(env_builder)

# Default to C++17
if(NOT CMAKE_CXX_STANDARD)
  set(CMAKE_CXX_STANDARD 17)
endif()

if(CMAKE_COMPILER_IS_GNUCXX OR CMAKE_CXX_COMPILER_ID MATCHES "Clang")
  add_compile_options(-Wall -Wextra -Wpedantic)
endif()

find_package(ament_cmake REQUIRED)
find_package(rclcpp REQUIRED)
find_package(std_msgs REQUIRED)
find_package(far_task_msgs REQUIRED)
find_package(far_fleet_msgs REQUIRED)
find_package(LibXml2 REQUIRED)

add_executable(env_builder_node env_builder.cpp)
ament_target_dependencies(env_builder_node rclcpp std_msgs far_task_msgs far_fleet_msgs)



include_directories(${LIBXML2_INCLUDE_DIRS})
link_libraries(${LIBXML2_LIBRARY})

add_executable(far_amr_mock far_amr_mock.cpp)
target_link_libraries(far_amr_mock xml2)
ament_target_dependencies(far_amr_mock rclcpp std_msgs far_task_msgs far_fleet_msgs)


add_executable(xml_parser xml_parser.cpp)
target_link_libraries(xml_parser xml2)
ament_target_dependencies(xml_parser rclcpp std_msgs far_task_msgs far_fleet_msgs)


################################################################################
# Install
################################################################################
install(TARGETS
  env_builder_node far_amr_mock xml_parser
  DESTINATION lib/${PROJECT_NAME})

#------------------------------------------------------------------------
install(
  DIRECTORY launch map conf rviz
  DESTINATION share/${PROJECT_NAME}
)

if(BUILD_TESTING)
  find_package(ament_lint_auto REQUIRED)
  ament_lint_auto_find_test_dependencies()
endif()

ament_package()

# Generate version control information for binary package 
set(VERSION_CONTROL ${CMAKE_INSTALL_PREFIX}/DEBIAN)
add_definitions("-D${PROJECT_NAME}_VERSION=\"${${PROJECT_NAME}_VERSION}\"")
add_definitions("-D${PROJECT_NAME}_MAINTAINER=\"${${PROJECT_NAME}_MAINTAINER}\"")
execute_process (
    COMMAND bash -c "mkdir -p '${VERSION_CONTROL}'"
    COMMAND bash -c "touch '${VERSION_CONTROL}'/control"
    COMMAND bash -c "echo 'Package: ${PROJECT_NAME}' | tr _ - > '${VERSION_CONTROL}'/control"
)
execute_process (
    COMMAND bash -c "echo 'Architecture: all' >> '${VERSION_CONTROL}'/control"
    COMMAND bash -c "echo 'Version: ${${PROJECT_NAME}_VERSION}' >> '${VERSION_CONTROL}'/control"
    COMMAND bash -c "echo 'Maintainer: ${${PROJECT_NAME}_MAINTAINER}' >> '${VERSION_CONTROL}'/control"
    COMMAND bash -c "echo 'Description: ${PROJECT_NAME} package release' >> '${VERSION_CONTROL}'/control"
)