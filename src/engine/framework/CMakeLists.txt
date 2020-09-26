add_library(framework Framework.cpp)
target_include_directories(framework PUBLIC ../../../include)

target_link_libraries(framework glfw)
target_link_libraries(framework gl3w)

add_library(draw Draw.cpp)
target_include_directories(draw PUBLIC ../../../include)

target_link_libraries(draw glfw)
target_link_libraries(draw gl3w)

target_link_libraries(framework draw)
