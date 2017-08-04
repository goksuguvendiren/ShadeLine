cmake_minimum_required(VERSION 3.7)
project(Pipeline)

list(APPEND CMAKE_MODULE_PATH "${CMAKE_CURRENT_SOURCE_DIR}/cmake_modules")

find_package(OpenGL REQUIRED)
find_package(OpenCV REQUIRED)
find_package(GLFW REQUIRED)
find_package(GLEW REQUIRED)
find_package(nlohmann_json REQUIRED)

set(CMAKE_CXX_STANDARD 14)

set(SOURCE_FILES main.cpp Nodes/node.cpp Nodes/node.hpp mytypes.hpp Nodes/ShaderNode.cpp Nodes/ShaderNode.h GL/Shader.cpp GL/Shader.h GL/Window.cpp GL/Window.h GL/Texture.cpp GL/Texture.h GL/Program.cpp GL/Program.h GL/GGL.h Graph.cpp Graph.hpp Nodes/TextureNode.cpp Nodes/TextureNode.h Nodes/IntNode.cpp Nodes/IntNode.h)
add_executable(Pipeline ${SOURCE_FILES})

target_compile_definitions(Pipeline PUBLIC PIPELINE_NAMESPACE=ppl)

target_link_libraries(Pipeline ${OPENGL_LIBRARIES})
target_link_libraries(Pipeline ${OpenCV_LIBRARIES})
target_link_libraries(Pipeline ${GLFW_LIBRARIES})
target_link_libraries(Pipeline ${GLEW_LIBRARIES})

target_include_directories(Pipeline PUBLIC ${OpenCV_INCLUDE_DIR})
target_include_directories(Pipeline PUBLIC ${NLOHMANN_JSON_INCLUDE_DIR})