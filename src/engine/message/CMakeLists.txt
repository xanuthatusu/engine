add_library(message Message.cpp)
target_include_directories(message PUBLIC ../../../include)

add_library(messageBus MessageBus.cpp)
target_include_directories(messageBus PUBLIC ../../../include)

target_link_libraries(messageBus glfw)
target_link_libraries(messageBus gl3w)
