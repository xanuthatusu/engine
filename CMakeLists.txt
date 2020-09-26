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

add_library(Shape src/shapes/Shape.cpp)
target_link_libraries(Engine Shape)

add_subdirectory(lib/glfw)
target_link_libraries(Shape glfw)

add_subdirectory(lib/gl3w)
target_link_libraries(Shape gl3w)

add_library(Console src/engine/systems/console/Console.cpp)
target_link_libraries(Engine Console)

add_library(Render src/engine/systems/render/Render.cpp)
target_link_libraries(Engine Render)

add_library(Framework src/engine/framework/Framework.cpp)
target_link_libraries(Engine Framework)

add_library(Draw src/engine/framework/draw/Draw.cpp)
target_link_libraries(Framework Draw)

add_library(Message src/engine/messages/Message.cpp)
target_link_libraries(Engine Message)

add_library(MessageBus src/engine/messages/MessageBus.cpp)
target_link_libraries(Engine MessageBus)

target_include_directories(Main PUBLIC
				bin
				lib
				src/engine)

