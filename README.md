# gfx-base

## Preface

Graphics-base or `gfx-base` is a template project I have designed for conducting the CSE 4551: Computer Graphics and Multimedia Systems Lab (Bachelor's) course at IUT, Bangladesh.

The base serves two purposes:

1. to be used as a foundation for all the lab tasks
2. to serve as a test for students to run in their computers before attending any lab to ensure that they have the correct toolset installed.

This base over here is dependent on only three third party libraries directly and one indirectly via a custom wrapper:

1. [fmtlib/fmt](https://github.com/fmtlib/fmt) for text formatting and printing
2. [libeigen/eigen](https://gitlab.com/libeigen/eigen) for matrix and mathematical operations
3. [catchorg/catch2](https://github.com/catchorg/catch2) for automated testing of implementations
4. [IshrakAbedin/mpix](https://github.com/IshrakAbedin/mpix) a custom small wrapper over [nothings/stb](https://github.com/nothings/stb) image libraries for image processing

## Intended Usage Style

The project is maintained using [CMake](https://cmake.org/) meta-build-system, where all the third party dependencies are handled using [CPM.cmake](https://github.com/cpm-cmake/cpm.cmake). The tests are discovered with [CTest](https://cmake.org/cmake/help/book/mastering-cmake/chapter/Testing%20With%20CMake%20and%20CTest.html).

For the lab, it is expected that most of the students will work on the tasks using [VS Code](https://code.visualstudio.com/) with the [C/C++ Extension Pack by Microsoft](https://marketplace.visualstudio.com/items?itemName=ms-vscode.cpptools-extension-pack) and [CMake Tools by Microsoft](https://marketplace.visualstudio.com/items?itemName=ms-vscode.cmake-tools) extensions. Alternatively, if the students want to pursue an open-source route with [Code OSS](https://github.com/microsoft/vscode), they can use [clangd by LLVM](https://marketplace.visualstudio.com/items?itemName=llvm-vs-code-extensions.vscode-clangd) with [CMake Tools by Microsoft in Open VSX](https://open-vsx.org/extension/ms-vscode/cmake-tools).

Students who want to use other editors, such as [Zed](https://zed.dev/), [neovim](https://neovim.io/), [GNU Emacs](https://www.gnu.org/software/emacs/), etc., I consider that they are knowledgeable enough to maintain intellisense in the project by their own using [clangd](https://clangd.llvm.org/) and/or any other language server(s) for C++ and/or CMake.

The whole project can definitely be built and tested from the command-line, the instructions for which are given in the next section.

## Toolchain Requirement

### Linux

In Linux systems, the project requires:

- GCC (13+) for building the C++ 20 code
- GDB for debugging
- Ninja as the preferred build system
- CMake (3.31+) for project maintenance

Alternatively, Clang - LLVM (10+) and LLDB can also be used instead of GCC/GDB. Make sure all the dependencies are installed in your system before proceeding.

### Windows

In Windows system, the easiest way to satisfy all the toolchain dependencies is to install the latest version of [Microsoft Visual Studio 2026](https://visualstudio.microsoft.com/) with the _Desktop development with C++_ workload. Do not confuse it with VS Code, as Visual Studio is a separate IDE. We are using it for the ease of toolchain setup.

If you do not wish to install Visual Studio, follow the Linux requirements and setup your own environment. [MSYS2](https://www.msys2.org/) or [Cygwin](https://www.cygwin.com/) are great options here, though I have not tested them myself. Alternatively, you can use [WSL (Windows Subsystem for Linux)](https://learn.microsoft.com/en-us/windows/wsl/install) and follow the Linux dependencies verbatim.

### MacOS

Being from the \*nix family, the dependencies for MacOS are the same as a Linux. But be careful as the out-of-the-box `gcc` or `g++` command often redirects to Apple `clang`, which might be outdated. Before proceeding, ensure all the dependencies are up-to-date.

## Building and Testing the Project

The project is managed using a sets of presets: _debug_, _dev_, and _release_. Since graphical work load can get quite processing intensive, especially in the ray-tracing works, it is not feasible to always work in _debug_ mode. Hence, for regular students, it is expected that they will work in the _dev_ mode, which is basically a relase mode with debug symbols.

> _You must run all the following commands in the root directory of the project, where the outer most [CMakeLists](./CMakeLists.txt) file is located._

## Listing Presets

You can list the available presets using:

```bash
cmake --list-presets
```

Which might produce an output like:

```bash
Available configure presets:

  "debug"   - Debug (-O0, all checks, slow Eigen)
  "dev"     - Dev (optimised + debug info)
  "release" - Release (fastest, no asserts)
```

Rest of the command assume that you are using the _dev_ preset.

## Configuring a Preset

Configure the project to a specific preset using:

```bash
cmake --preset dev # or with debug/release
```

It might take some time depending on your internet connection speed as the third-party dependencies are fetched in this stage.

> _Configuration, build, and test presets have the same names in this project for the ease of maintenance._

## Building the Project

Once the a preset is configured, to build the project with that preset, run the following command:

```bash
cmake --build --preset dev # or wtih debug/release
```

Once the build is complete, the built executables and other files are located in the `./build/<preset>/` folder, depending one which preset you built in. Within there, you can find your executable, which you can run from the command-line.

## Testing the Projcet

Once the project is configured and then built using a preset, you can run the tests for that preset using:

```bash
ctest --preset dev # or with debug/release
```

A successful setup should produce something similar to:

```
Test project <build directory>
    Start 1: Basic C++20 lib works
1/5 Test #1: Basic C++20 lib works .....................................   Passed    0.02 sec
    Start 2: Eigen works
2/5 Test #2: Eigen works ...............................................   Passed    0.02 sec
    Start 3: fmtlib works
3/5 Test #3: fmtlib works ..............................................   Passed    0.02 sec
    Start 4: mpix modify, resize and flip an image in memory works
4/5 Test #4: mpix modify, resize and flip an image in memory works .....   Passed    0.02 sec
    Start 5: mpix writing an image to disk and reading it back works
5/5 Test #5: mpix writing an image to disk and reading it back works ...   Passed    0.03 sec

100% tests passed, 0 tests failed out of 5

Total Test time (real) =   0.20 sec
```

If you can reach up to this stage, your setup is working correctly and hopefully, rest of the labs will not be a issue for you (from building and testing perspective).
