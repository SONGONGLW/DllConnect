cmake_minimum_required(VERSION 3.5)

project(ConnectTest)

add_executable(ConnectTest main.cpp)

target_include_directories(ConnectTest PRIVATE ${CMAKE_SOURCE_DIR}/../CMakeTest/AddLib)

install(TARGETS ${PROJECT_NAME} RUNTIME DESTINATION install)
