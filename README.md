# ROS2 Library example

This tree features two ROS packages:
 - `my_library` defines an "external" library that exports a class `Example`
   with a function `void say_hello()`. 
 - `my_libuser` defines an "internal" library that defines a class `LibraryUser`
   with a function `void use_library()` that calls `Example::say_hello()`.
 - `my_libuser` exprots a ROS node that uses the `LibraryUser`.

Have a look at the `CMakeLists.txt` and feel free to use them for your projects.

Key takeaways from the `my_library`:
1. export the library: `install` and `ament_export_targets`

Key takeaways from the `my_libuser`:
1. find the dependency: `find_package(my_library REQUIRED)`
2. specify the internal library: `add_library`
3. specify the node executable: `add_executable`
4. link the internal library: `ament_target_dependencies(${PROJECT_NAME} my_library)`
5. link the node against the internal library. Use `target_link_libraries` this time
6. link the node against external libraries: `ament_target_dependencies`
