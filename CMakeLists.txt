cmake_minimum_required(VERSION 3.24)
project(SpaceWorks)
# Find GLFW
find_package(glfw3 3.3 REQUIRED)
# Find Boost log
find_package(Boost 1.74.0 REQUIRED COMPONENTS log)
# Find OpenGL
find_package(OpenGL REQUIRED)
# Find GLEW
find_package(GLEW REQUIRED)
include_directories("include")
add_executable(SpaceWorks "src/main.cpp")
target_link_libraries(SpaceWorks glfw Boost::log OpenGL::GL GLEW::GLEW)