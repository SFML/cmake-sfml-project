cmake_minimum_required(VERSION 3.28)
project(RoboOpVisualizer LANGUAGES CXX)

include(FetchContent)

FetchContent_Declare(RoboOp
    GIT_REPOSITORY https://github.com/RandomPythonProgrammer/Library.git
    GIT_TAG origin/main
)
FetchContent_MakeAvailable(RoboOp)

find_package(glfw3 REQUIRED)
find_package(OpenGL REQUIRED)

include_directories(include)
include_directories(imgui)
include_directories(implot)

file(GLOB_RECURSE SOURCES "src/*.cpp")
file(GLOB IMGUI_CORE "imgui/*.cpp")
file(GLOB IMPLOT_CORE "implot/*.cpp")
add_executable(main ${SOURCES} ${IMGUI_CORE} imgui/backends/imgui_impl_glfw.cpp imgui/backends/imgui_impl_opengl3.cpp ${IMPLOT_CORE})

target_link_libraries(main PRIVATE glfw)
target_link_libraries(main PRIVATE ${OPENGL_LIBRARIES})
target_link_libraries(main PRIVATE RoboOp)
target_compile_features(main PRIVATE cxx_std_20)
