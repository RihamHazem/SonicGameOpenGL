cmake_minimum_required(VERSION 3.6)
project(graphics)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(SOURCE_FILES src/Source.cpp src/Window/Window.cpp src/Window/Window.h src/Compontents/Camera.cpp src/Compontents/Camera.h src/Compontents/Mesh.cpp src/Compontents/Mesh.h src/Compontents/Model.cpp src/Compontents/Model.h src/Compontents/Shader.cpp src/Compontents/Shader.h src/Compontents/Texture.cpp src/Compontents/Texture.h Shaders/lamp_fragment.shader Shaders/lamp_vertex.shader Shaders/lighting_fragment.shader Shaders/lighting_vertex.shader Shaders/skybox_fragment.shader Shaders/skybox_vertex.shader )
add_executable(graphics ${SOURCE_FILES})
target_link_libraries(graphics -lglfw -lGL -lglut -lGLEW -lSOIL assimp)
