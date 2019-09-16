# Jötunn
https://en.wikipedia.org/wiki/J%C3%B6tunn

Working on a C++ rendering engine.

# Cloning the repository

Jötunn uses Git submodules to manage its dependencies.

To clone the repository and its submodules, simply clone the repository via `git clone --recursive`

Jötunn currently includes the following dependencies:
* [GLFW](https://github.com/glfw/glfw) for windowing
* [GLEW CMake](https://github.com/Perlmint/glew-cmake) for loading OpenGL extensions
* [GLM](https://github.com/g-truc/glm) for math operations
* [Dear ImGui](https://github.com/ocornut/imgui) for GUI elements
* [SPDLOG](https://github.com/gabime/spdlog) for logging operations (colored console output, etc.)
* [ASSIMP](https://github.com/assimp/assimp) for model loading (not supported yet)

* Also Doxygen for documentation, though it is not submoduled into this project

# Setting up Jötunn

Jotunn uses [CMake](https://cmake.org/) as a build system, requiring at least CMake version 3.1.

## Using CMake GUI

To build Jötunn with CMake GUI, simply select the root of the repository as the source directory and specify your build directory for project files. Then, configure and generate the project files.
