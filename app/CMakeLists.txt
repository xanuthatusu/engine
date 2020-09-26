add_executable(app main.cpp)

configure_file(AppConfig.h.in AppConfig.h)

target_link_libraries(app engine)
