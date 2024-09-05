cmake_minimum_required(VERSION 3.5)
project(my_library)

# Find dependencies
find_package(ament_cmake REQUIRED)

# Specify include directories
include_directories(include)

# Library source files
set(LIBRARY_SOURCES src/example.cpp)

# Create the library
add_library(${PROJECT_NAME} SHARED ${LIBRARY_SOURCES})

# Specify include directories for the library
target_include_directories(${PROJECT_NAME} PUBLIC
  $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>
  $<INSTALL_INTERFACE:include>)

# Install the library and include files
install(TARGETS ${PROJECT_NAME}
  EXPORT ${PROJECT_NAME}
  LIBRARY DESTINATION lib
  ARCHIVE DESTINATION lib
  RUNTIME DESTINATION bin
  INCLUDES DESTINATION include)

install(DIRECTORY include/ DESTINATION include)

# Export the library
ament_export_targets(${PROJECT_NAME} HAS_LIBRARY_TARGET)
ament_export_dependencies(ament_cmake)

ament_package()
