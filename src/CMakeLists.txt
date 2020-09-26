add_library(engine engine/Engine.cpp)
target_include_directories(engine PUBLIC ../include)

target_link_libraries(engine glfw)
target_link_libraries(engine gl3w)

add_subdirectory(shape)
target_link_libraries(engine shape)

add_subdirectory(engine/message)
target_link_libraries(engine message)
target_link_libraries(engine messageBus)

add_subdirectory(engine/framework)
target_link_libraries(engine framework)

add_subdirectory(engine/systems)
target_link_libraries(engine console)
target_link_libraries(engine render)
