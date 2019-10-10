cmake_minimum_required(VERSION 3.5)
project(GL_sample)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_FLAGS "-o2")

find_package(PkgConfig REQUIRED)
find_package(X11 REQUIRED)
pkg_search_module(GLFW REQUIRED glfw3)
find_package(OpenGL REQUIRED)
find_package(GLEW REQUIRED)
include_directories(${GLFW_INCLUDE_DIRS})
add_executable(GL_sample main.cpp )
target_link_libraries(GL_sample ${X11_LIBRARIES} ${OPENGL_LIBRARIES} ${GLFW_LIBRARIES} ${GLEW_LIBRARIES})