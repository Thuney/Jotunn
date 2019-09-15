project (Jotunn)
cmake_minimum_required(VERSION 3.1)
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_definitions(-DGLEW_STATIC)
add_subdirectory(${PROJECT_SOURCE_DIR}/vendor/GLEW ${PROJECT_SOURCE_DIR}/vendor/GLEW/build EXCLUDE_FROM_ALL)
add_subdirectory(${PROJECT_SOURCE_DIR}/vendor/GLFW ${PROJECT_SOURCE_DIR}/vendor/GLFW/build EXCLUDE_FROM_ALL)
add_subdirectory(${PROJECT_SOURCE_DIR}/vendor/GLM ${PROJECT_SOURCE_DIR}/vendor/GLM/build EXCLUDE_FROM_ALL)
add_subdirectory(${PROJECT_SOURCE_DIR}/vendor/ASSIMP ${PROJECT_SOURCE_DIR}/vendor/ASSIMP/build EXCLUDE_FROM_ALL)
add_subdirectory(${PROJECT_SOURCE_DIR}/vendor/SPDLOG ${PROJECT_SOURCE_DIR}/vendor/SPDLOG/build EXCLUDE_FROM_ALL)

include_directories(${Jotunn_SOURCE_DIR}/vendor/IMGUI)
add_library(
	ImGUI
	${PROJECT_SOURCE_DIR}/vendor/IMGUI/imconfig.h
	${PROJECT_SOURCE_DIR}/vendor/IMGUI/imgui.cpp
	${PROJECT_SOURCE_DIR}/vendor/IMGUI/imgui.h
	${PROJECT_SOURCE_DIR}/vendor/IMGUI/imgui_demo.cpp
	${PROJECT_SOURCE_DIR}/vendor/IMGUI/imgui_draw.cpp
	${PROJECT_SOURCE_DIR}/vendor/IMGUI/imgui_internal.h
	${PROJECT_SOURCE_DIR}/vendor/IMGUI/imgui_widgets.cpp
	${PROJECT_SOURCE_DIR}/vendor/IMGUI/imstb_rectpack.h
	${PROJECT_SOURCE_DIR}/vendor/IMGUI/imstb_textedit.h
	${PROJECT_SOURCE_DIR}/vendor/IMGUI/imstb_truetype.h
)
target_link_libraries(ImGUI glm)

include_directories(${Jotunn_SOURCE_DIR}/src)

file(GLOB_RECURSE SRCS src/*.cpp)
file(GLOB_RECURSE HDRS src/*.h)

add_library(Jotunn ${SRCS} ${HDRS})

target_link_libraries(Jotunn glfw)
target_link_libraries(Jotunn libglew_static)
target_link_libraries(Jotunn glm)
target_link_libraries(Jotunn assimp)
target_link_libraries(Jotunn spdlog)
target_link_libraries(Jotunn ImGUI)