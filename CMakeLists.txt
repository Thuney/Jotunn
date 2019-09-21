project (JotunnProjectRoot)
cmake_minimum_required(VERSION 3.1)
cmake_policy(VERSION 3.1)

add_subdirectory(${PROJECT_SOURCE_DIR}/Jotunn ${PROJECT_SOURCE_DIR}/Jotunn/build)
add_subdirectory(${PROJECT_SOURCE_DIR}/JotunnApplication ${PROJECT_SOURCE_DIR}/JotunnApplication/build)