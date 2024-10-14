cmake_minimum_required(VERSION 3.28)
project(CMakeSFMLProject LANGUAGES CXX)

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)
option(BUILD_SHARED_LIBS "Build shared libraries" OFF)

include(FetchContent)
FetchContent_Declare(SFML
    GIT_REPOSITORY https://github.com/SFML/SFML.git
    GIT_TAG 2.6.x
    GIT_SHALLOW ON
    EXCLUDE_FROM_ALL
    SYSTEM)
FetchContent_MakeAvailable(SFML)

add_executable(main src/main.cpp)
target_link_libraries(main PRIVATE sfml-graphics)
target_compile_features(main PRIVATE cxx_std_17)

if(APPLE)
    # On macOS, bundle the executable into an .app bundle
    set(MACOSX_BUNDLE_BUNDLE_NAME main)
    set(MACOSX_BUNDLE_GUI_IDENTIFIER "com.example.main") # com.YOURCOMPANY.YOURAPP
    set(MACOSX_BUNDLE_BUNDLE_VERSION "1.0")
    set(MACOSX_BUNDLE_SHORT_VERSION_STRING "1.0")

    # Specify the output format as a macOS bundle
    set_target_properties(main PROPERTIES
        MACOSX_BUNDLE TRUE
        MACOSX_BUNDLE_INFO_PLIST ${CMAKE_BINARY_DIR}/Info.plist
        INSTALL_RPATH "@loader_path/../Frameworks" # Set the runtime search path
    )

    # Fill in the Info.plist file with the project's name and other variables
    configure_file(${CMAKE_SOURCE_DIR}/Info.plist.in ${CMAKE_BINARY_DIR}/Info.plist @ONLY)

    # After building, copy SFML frameworks into the .app bundle
    add_custom_command(TARGET main POST_BUILD
        # Ensure the Frameworks directory exists
        COMMAND ${CMAKE_COMMAND} -E make_directory $<TARGET_BUNDLE_DIR:main>/Contents/Frameworks
        # Copy the necessary SFML frameworks
        COMMAND ${CMAKE_COMMAND} -E copy_directory
            ${CMAKE_BINARY_DIR}/_deps/sfml-src/extlibs/libs-osx/Frameworks
            $<TARGET_BUNDLE_DIR:main>/Contents/Frameworks
        COMMENT "Copying SFML frameworks to the .app bundle"
        VERBATIM
    )

    # Add install target (macOS app bundle)
    install(TARGETS main BUNDLE DESTINATION /Applications)
else()
    # Add install target (regular executable)
    install(TARGETS main RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR})
endif()

if(WIN32)
    add_custom_command(
        TARGET main
        COMMENT "Copy OpenAL DLL"
        PRE_BUILD COMMAND ${CMAKE_COMMAND} -E copy ${SFML_SOURCE_DIR}/extlibs/bin/$<IF:$<EQUAL:${CMAKE_SIZEOF_VOID_P},8>,x64,x86>/openal32.dll $<TARGET_FILE_DIR:main>
        VERBATIM)
endif()
