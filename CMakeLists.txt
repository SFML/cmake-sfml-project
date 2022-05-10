cmake_minimum_required(VERSION 3.15)
project(CMakeSFMLProject LANGUAGES CXX)

find_package(SFML 2.5 COMPONENTS graphics REQUIRED)

add_executable(CMakeSFMLProject src/main.cpp)
target_link_libraries(CMakeSFMLProject PRIVATE sfml-graphics)
target_compile_features(CMakeSFMLProject PRIVATE cxx_std_17)

install(TARGETS CMakeSFMLProject)
