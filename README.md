# CMake SFML Project Template

This repository template, should allow for a fast and hassle-free kick start of your next SFML project using CMake.  
Thanks to [GitHub's nature of templates](https://docs.github.com/en/repositories/creating-and-managing-repositories/creating-a-repository-from-a-template), you can fork this repository without inheriting its Git history.

The template starts out very basic, but might receive additional features over time:

- Basic CMake script to build your project and link SFML
- Basic [GitHub Actions](https://github.com/features/actions) script for all major platforms

## How to Use

1. Follow the above instructions about how to use GitHub's project template feature to create your own project.
1. Open [CMakeLists.txt](CMakeLists.txt). Rename the project and the executable to whatever name you want. The project and executable names don't have to match.
1. Install SFML 2.5.1.

    On Ubuntu Linux:
    ```
    sudo apt install libsfml-dev
    ```
    On macOS
    ```
    brew install sfml
    ```
1. Change the source files listed in [`add_executable`](CMakeLists.txt#L6) to match the source files your project requires.
1. Configure and build your project.

   On Linux or macOS, run these commands from the root directory of your project.
    ```cmake
    cmake -B build
    cmake --build build
    ```

    Alternatively, use [VS Code](https://code.visualstudio.com) with its [CMake extension](https://code.visualstudio.com/docs/cpp/cmake-linux) on any OS.
1. Enjoy!

## More Reading

Here are some useful resources if you want to learn more about CMake:

- [How to Use CMake Without the Agonizing Pain - Part 1](https://alexreinking.com/blog/how-to-use-cmake-without-the-agonizing-pain-part-1.html)
- [How to Use CMake Without the Agonizing Pain - Part 2](https://alexreinking.com/blog/how-to-use-cmake-without-the-agonizing-pain-part-2.html)
- [Better CMake YouTube series by Jefferon Amstutz](https://www.youtube.com/playlist?list=PL8i3OhJb4FNV10aIZ8oF0AA46HgA2ed8g)

## License

The source code is dual licensed under Public Domain and MIT -- choose whichever you prefer.
