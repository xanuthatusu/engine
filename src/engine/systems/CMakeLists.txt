add_library(console Console.cpp)
target_include_directories(console PUBLIC ../../../include)
target_link_libraries(console glfw)
target_link_libraries(console gl3w)

add_library(render Render.cpp)
target_include_directories(render PUBLIC ../../../include)
target_link_libraries(render glfw)
target_link_libraries(render gl3w)
