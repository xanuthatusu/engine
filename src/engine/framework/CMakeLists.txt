add_library(framework Framework.cpp)
target_include_directories(framework PUBLIC ../../../include)

target_link_libraries(framework glfw)
target_link_libraries(framework gl3w)

add_library(draw Draw.cpp)
target_include_directories(draw PUBLIC ../../../include)

target_link_libraries(draw glfw)
target_link_libraries(draw gl3w)
target_link_libraries(draw shape)

target_link_libraries(framework draw)

add_library(fw_input Input.cpp)
target_include_directories(fw_input PUBLIC ../../../include)

target_link_libraries(fw_input glfw)
target_link_libraries(fw_input gl3w)

target_link_libraries(framework fw_input)
