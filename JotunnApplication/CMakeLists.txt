project (JotunnApplication)
cmake_minimum_required(VERSION 3.1)

file(GLOB_RECURSE SRCS src/*.cpp)
file(GLOB_RECURSE HDRS src/*.h)

include_directories(${Jotunn_SOURCE_DIR}/src)

add_executable(JotunnApplication ${SRCS} ${HDRS})

target_link_libraries(JotunnApplication Jotunn)