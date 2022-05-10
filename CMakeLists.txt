cmake_minimum_required(VERSION 3.15)

project(CMakeSFMLProject LANGUAGES CXX)

# Tell CMake to build a executable
add_executable(CMakeSFMLProject src/main.cpp)

# CMake SFML Project uses C++17 features
target_compile_features(CMakeSFMLProject PRIVATE cxx_std_17)

# Find SFML
find_package(SFML 2.5 COMPONENTS graphics REQUIRED)

# Link SFML
target_link_libraries(CMakeSFMLProject PRIVATE sfml-graphics)

# Install executable
install(TARGETS CMakeSFMLProject
        RUNTIME DESTINATION .)
