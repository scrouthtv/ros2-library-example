cmake_minimum_required(VERSION 3.5)
project(my_libuser)

# Find dependencies
find_package(ament_cmake REQUIRED)
find_package(rclcpp REQUIRED)
find_package(my_library REQUIRED)

# Specify include directories
include_directories(include)

add_library(${PROJECT_NAME} src/my_libuser.cpp)

# Create an executable
add_executable(${PROJECT_NAME}_node src/my_node.cpp)

# Link the my_libuser library against the imported my_library
# It is important to use `ament_target_dependencies` instead of
# `target_link_libraries` as `my_library` is an external ament-type
# library, see:
# https://answers.ros.org/question/355980/ament_target_dependencies-vs-target_link_libraries/
ament_target_dependencies(${PROJECT_NAME} my_library)

# As my_libuser is an "internal" library defined in this CMakeLists,
# we now have to use `target_link_libraries` here.
target_link_libraries(${PROJECT_NAME}_node ${PROJECT_NAME})

# Install the executable
install(TARGETS ${PROJECT_NAME}_node
DESTINATION lib/${PROJECT_NAME})

# Remember to also link the node against my_library:
ament_target_dependencies(${PROJECT_NAME}_node
rclcpp
my_library)

ament_package()
