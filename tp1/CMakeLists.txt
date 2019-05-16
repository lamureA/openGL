cmake_minimum_required(VERSION 3.13)
project(tp1)

set(CMAKE_CXX_STANDARD 17)

add_executable(tp1 src/main.cpp src/Matrix4.cpp src/Matrix4.h src/Vector3.cpp src/Vector3.h src/Program.cpp src/Program.h)

find_package(GLEW REQUIRED)
find_package(OpenGL REQUIRED)
find_package(GLUT REQUIRED)
include_directories( ${OPENGL_INCLUDE_DIRS}  ${GLUT_INCLUDE_DIRS} ${GLEW_INCLUDE_DIRS})

target_link_libraries(tp1 ${OPENGL_LIBRARIES} ${GLUT_LIBRARY}  ${GLEW_LIBRARIES})