cmake_minimum_required(VERSION 3.17)
project(opengl)

set(CMAKE_CXX_STANDARD 14)

set(GLEW_H /usr/local/Cellar/glew/2.1.0_1/include/GL)
set(GLFW_H /usr/local/Cellar/glfw/3.3.2/include/GLFW)

include_directories(${GLEW_H} ${GLFW_H})

set(GLEW_LINK /usr/local/Cellar/glew/2.1.0_1/lib/libGLEW.2.1.dylib)
set(GLFW_LINK /usr/local/Cellar/glfw/3.3.2/lib/libglfw.3.dylib)

link_libraries(${GLEW_LINK} ${GLFW_LINK})

add_executable(opengl main.cpp)
# mac下这步很重要
if (APPLE)
    target_link_libraries(opengl "-framework OpenGL")
    target_link_libraries(opengl "-framework GLUT")
endif()

