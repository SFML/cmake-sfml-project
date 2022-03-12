cmake_minimum_required(VERSION 3.15)

project(CMakeSFMLProject LANGUAGES CXX)

# Set options
option(CMAKESFMLPROJECT_STATIC_LIBS "Link SFML libraries statically?" OFF)
option(CMAKESFMLPROJECT_STATIC_STD_LIBS "Use statically linked standard/runtime libraries? This option must match the one used for SFML." OFF)

# Find all source files
file(GLOB_RECURSE SOURCE_FILES CONFIGURE_DEPENDS ${PROJECT_SOURCE_DIR}/src/*.cpp ${PROJECT_SOURCE_DIR}/src/*.hpp)

# Tell CMake to build a executable
add_executable(${PROJECT_NAME} ${SOURCE_FILES})

# CMake SFML Project uses C++17 features
target_compile_features(${PROJECT_NAME} PRIVATE cxx_std_17)
set_target_properties(${PROJECT_NAME} PROPERTIES CXX_EXTENSIONS NO CXX_STANDARD_REQUIRED YES)

# Make sure that the runtime library gets linked statically
if(CMAKESFMLPROJECT_STATIC_STD_LIBS)
    if(NOT CMAKESFMLPROJECT_STATIC_LIBS)
        message("\n-> If you check CMAKESFMLPROJECT_STATIC_STD_LIBS, you also need to check CMAKESFMLPROJECT_STATIC_LIBS.")
        message("-> It would lead to multiple runtime environments which results in undefined behavior.\n")
    elseif(WIN32 AND MSVC)
        set_property(TARGET ${PROJECT_NAME} PROPERTY MSVC_RUNTIME_LIBRARY "MultiThreaded$<$<CONFIG:Debug>:Debug>")
    elseif(CMAKE_COMPILER_IS_GNUCXX)
        # Note: Doesn't work for TDM compiler, since it's compiling the runtime libs statically by default
        target_compile_options(${PROJECT_NAME} PRIVATE -static)
    endif()
endif()

# Request static SFML libraries when building statically
if(CMAKESFMLPROJECT_STATIC_LIBS)
    set(SFML_STATIC_LIBRARIES TRUE)
endif()

# Find SFML
find_package(SFML 2.5 COMPONENTS graphics REQUIRED)

# Link SFML
target_link_libraries(${PROJECT_NAME} sfml-graphics)

# Install executable
install(TARGETS ${PROJECT_NAME}
        RUNTIME DESTINATION .)
