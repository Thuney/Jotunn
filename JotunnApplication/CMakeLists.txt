project (JotunnApplication)
cmake_minimum_required(VERSION 3.1)

include_directories(${Jotunn_SOURCE_DIR}/src)

add_executable(JotunnApplication src/JotunnApplication.cpp)

target_link_libraries(JotunnApplication Jotunn)