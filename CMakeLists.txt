cmake_minimum_required(VERSION 3.10)

project(Engine VERSION 0.1)

set(SRC_DIR "${CMAKE_CURRENT_SOURCE_DIR}/src")
set(LIB_DIR "${CMAKE_CURRENT_SOURCE_DIR}/lib")
set(BIN_DIR "${CMAKE_CURRENT_SOURCE_DIR}/bin")
set (CMAKE_RUNTIME_OUTPUT_DIRECTORY ${BIN_DIR})


set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED True)

set(GLFW_BUILD_DOCS OFF CACHE BOOL "" FORCE)
set(GLFW_BUILD_TESTS OFF CACHE BOOL "" FORCE)
set(GLFW_BUILD_EXAMPLES OFF CACHE BOOL "" FORCE)

configure_file(src/EngineConfig.h.in src/EngineConfig.h)

add_executable(Main src/main.cpp)
add_library(Engine src/engine/Engine.cpp)
target_link_libraries(Main PUBLIC Engine)

add_subdirectory(lib/glfw)
target_link_libraries(Engine glfw)

add_subdirectory(lib/gl3w)
target_link_libraries(Engine gl3w)

target_include_directories(Main PUBLIC
				bin
				src/Engine)

