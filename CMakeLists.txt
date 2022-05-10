cmake_minimum_required(VERSION 3.15)

project(CMakeSFMLProject LANGUAGES CXX)

# Find all source files
file(GLOB_RECURSE SOURCE_FILES CONFIGURE_DEPENDS ${PROJECT_SOURCE_DIR}/src/*.cpp ${PROJECT_SOURCE_DIR}/src/*.hpp)

# Tell CMake to build a executable
add_executable(CMakeSFMLProject ${SOURCE_FILES})

# CMake SFML Project uses C++17 features
target_compile_features(CMakeSFMLProject PRIVATE cxx_std_17)

# Find SFML
find_package(SFML 2.5 COMPONENTS graphics REQUIRED)

# Link SFML
target_link_libraries(CMakeSFMLProject PRIVATE sfml-graphics)

# Install executable
install(TARGETS CMakeSFMLProject
        RUNTIME DESTINATION .)
