cmake_minimum_required(VERSION 3.28)
project(CMakeSFMLProject LANGUAGES CXX)

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)

include(FetchContent)
FetchContent_Declare(SFML
    GIT_REPOSITORY https://github.com/SFML/SFML.git
    GIT_TAG 3.0.2
    GIT_SHALLOW ON
    EXCLUDE_FROM_ALL
    SYSTEM)
FetchContent_MakeAvailable(SFML)

# Android requires a shared library for the main executable
if(ANDROID)
    add_library(main SHARED src/main.cpp)
else()
    add_executable(main src/main.cpp)
endif()

target_compile_features(main PRIVATE cxx_std_17)
target_link_libraries(main PRIVATE SFML::Graphics)

# Mobile platforms need the main module
if(ANDROID OR IOS)
    target_link_libraries(main PRIVATE SFML::Main)
endif()

# iOS requires a bundle with an identifier to build
if(IOS)
    set_target_properties(main PROPERTIES
        MACOSX_BUNDLE TRUE
        MACOSX_BUNDLE_BUNDLE_NAME "CMakeSFMLProject"
        MACOSX_BUNDLE_GUI_IDENTIFIER "com.example.cmake-sfml-project")
endif()

set_property(DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR} PROPERTY VS_STARTUP_PROJECT main)