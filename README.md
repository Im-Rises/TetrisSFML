# TetrisSFML

<p align="center">
      <img src="https://user-images.githubusercontent.com/59691442/183268126-b3d19e66-8f2d-463a-805e-ae6ef7cc6c01.png" alt="cmakeLogo" style="height:60px;"/>
      <img src="https://img.shields.io/badge/C%2B%2B-00599C?style=for-the-badge&logo=c%2B%2B&logoColor=white" alt="cppLogo" style="height:60px;"/>
      <img src="https://user-images.githubusercontent.com/59691442/183268128-6f1a7773-a77c-4635-9a61-daa72c023915.png" alt="sfmlLogo" style="height:60px;"/>
</p>

## Description

Tetris game written in C++ using SFML 2.5.1 lib available for windows, linux and macOS.

The project is compiled using CMake and VisualStudio compiler version.

## Features

- Difficulty increasing depending on your score
- Clearing row animation
- Tetromino preview display
- Soft and Hard drop

## Images

| Screenshot 1                                                                                                      | Screenshot 2                                                                                                      |
|-------------------------------------------------------------------------------------------------------------------|-------------------------------------------------------------------------------------------------------------------|
| ![screen1](https://user-images.githubusercontent.com/59691442/190564537-cb0d0ee4-4135-4062-8834-8774519d4253.png) | ![screen2](https://user-images.githubusercontent.com/59691442/190564542-cd332ed3-c960-4a27-a2d0-3cb06307a4e8.png) |

## Quickstart

To download the game, you can click one of the icons below depending on your operating system, or you can click the
release section of the GitHub page.

Depending on you `operating system` you will need to install some libs, they are installed differently depending on your
system, please follow one of the section below `Windows` or `Linux` or `MacOs`.

> **Note**
> Be carefully you have the Text Font `Arial` in the folder `font` next to the executable. Without it the game will
> crash.

### Windows

<a href="https://github.com/Im-Rises/TetrisSFML/releases/latest"><img src="https://img.shields.io/badge/Windows-0078D6?style=for-the-badge&logo=windows&logoColor=white" alt="cmakeLogo" style="height:40px;"/></a>

For Windows users you don't need to install the libs, you just need to be carefully that you have the
`*.dll` next to the `TetrisSFML.exe` or the game won't start.

Once everything is set up by you can start the game by double-clicking the executable of typing the following
command next to it:

```bash
.\TetrisSFML.exe
```

### Linux

<a href="https://github.com/Im-Rises/TetrisSFML/releases/latest"><img src="https://img.shields.io/badge/Linux-FCC624?style=for-the-badge&logo=linux&logoColor=black" alt="cmakeLogo" style="height:40px;"/></a>

For Linux users, you need to install the SFML lib, to do so type one of the following commands:

```bash
sudo apt-get install libsfml
```

or if you're a developer and want to compile the game, please install this version of SFML:

```bash
sudo apt-get install libsfml-dev
```

Then you can start by double-clicking the executable of typing the following command next to it:

```bash
./TetrisSFML
```

### MacOs

<a href="https://github.com/Im-Rises/TetrisSFML/releases/latest"><img src="https://img.shields.io/badge/mac%20os-000000?style=for-the-badge&logo=apple&logoColor=white" alt="cmakeLogo" style="height:40px;"/></a>

For macOS users you will need to install Brew, please follow the instruction in the link below:  
<https://brew.sh>

Once it is installed, you can type the following command to install SFML.

```bash
brew install sfml
```

Then you can start by double-clicking the executable of typing the following command next to it:

```bash
./TetrisSFML
```

## Game controls

To play the game, you need to use your keyboard with the following controls:

| Description              | Keyboard |
|--------------------------|----------|
| ←                        | ←        |
| →                        | →        |
| Hard Drop                | ↑        |
| Soft Drop                | ↓        |
| Rotate clockwise         | S        |
| Rotate counter clockwise | D        |

## Project architecture

~~~
TetrisSFML
├── .github
|  ├── labels.yml
|  ├── release.yml
│  ├── workflows
│  │   |── cmake.yml
│  │   |── codeql.yml
│  │   |── cpp-cmake-publish.yml
│  │   |── cpp-linter.yml
│  │   |── dependency-review.yml
│  │   |── flawfinder.yml
│  │   |── greetings.yml
│  │   |── label.yml
│  │   |── msvc.yml
│  │   |── stale.yml
├── font
|   ├── arrial.ttf
├── TetrisSFML
|  ├── bin
│  │   |── *
|  ├── include
│  │   |── GLFW
│  │   │   |── *
|  ├── lib
│  │   |── *
|  ├── CMakeLists.txt
|  ├── global.h
|  ├── main.cpp
|  ├── Tetris.cpp
|  ├── Tetris.h
|  ├── Tetromino.cpp
|  ├── Tetromino.h
├── .clang-format
├── .editorconfig
├── .gitaattributes
├── .gitignore
├── CMakelists.txt
├── README.md
~~~

## Compilation

To compile the game, the first thing you need to do is installing a C++ compiler:

- Visual Studio (MSVC)
- Mingw
- ...

You also need to install Cmake:  
<https://cmake.org>

Once your environment is set up, you can download the project. If you have the Visual Studio compiler then you
can directly go to the operating system step compilation in the other case follow, the SFML installation in
the `SFML` section below.

### SFML

Follow this guide to install SFML on your distribution.  
<https://www.sfml-dev.org/tutorials/2.5/>

I compile the program with Visual Studio CMake compiler, so I downloaded the `Visual C++ 15 (2017) - 64-bit` v2.5.1.
If you want to compile the app with Mingw, be sure to download the `GCC 7.3.0 MinGW (SEH) - 64-bit` v2.5.1 and replace
the folders `bin`, `include` and `lib` by the mingw one.

### Windows

Windows users can directly compile the project by typing the following command at the project root folder:

```bash
cmake .
```

### Linux

First thing to do is to install CMake, type the following command to install it.

```bash
sudo apt-get install cmake
```

You also need to install the SFML lib. Type the following command at the project root.

```bash
sudo apt-get install libsfml-dev
```

You are now able to compile the project. Go to the project root and type the following command:

```bash
cmake .
```

### MacOs

For macOS user, you should install brew package manager by following the instructions in the link below:  
<https://brew.sh>

Then type the following command to install cmake:

```bash
brew install cmake
```

and this one to install SFML

```bash
brew install sfml
```

You are now able to compile the project. Go to the project root and type the following command:

```bash
cmake .
```

## Github-Actions

[![flawfinder](https://github.com/Im-Rises/TetrisSFML/actions/workflows/flawfinder.yml/badge.svg?branch=main)](https://github.com/Im-Rises/TetrisSFML/actions/workflows/flawfinder.yml)
[![CMake](https://github.com/Im-Rises/TetrisSFML/actions/workflows/cmake.yml/badge.svg?branch=main)](https://github.com/Im-Rises/TetrisSFML/actions/workflows/cmake.yml)
[![CodeQL](https://github.com/Im-Rises/TetrisSFML/actions/workflows/codeql.yml/badge.svg?branch=main)](https://github.com/Im-Rises/TetrisSFML/actions/workflows/codeql.yml)
[![Microsoft C++ Code Analysis](https://github.com/Im-Rises/TetrisSFML/actions/workflows/msvc.yml/badge.svg?branch=main)](https://github.com/Im-Rises/TetrisSFML/actions/workflows/msvc.yml)
[![Cpp Cmake Publish](https://github.com/Im-Rises/TetrisSFML/actions/workflows/cpp-cmake-publish.yml/badge.svg?branch=main)](https://github.com/Im-Rises/TetrisSFML/actions/workflows/cpp-cmake-publish.yml)
[![cpp-linter](https://github.com/Im-Rises/TetrisSFML/actions/workflows/cpp-linter.yml/badge.svg?branch=main)](https://github.com/Im-Rises/TetrisSFML/actions/workflows/cpp-linter.yml)

The project is set with a set of different scripts:

- flawfinder : to check the code for security flaws
- CMake : to compile the project
- CodeQl : to check quality of the code
- Microsoft C++ Code Analysis : to check the code for security flaws
- Cpp Cmake Publish : to publish the project on GitHub

## Documentations

Main documentation:  
<https://www.youtube.com/watch?v=vkS1fY_UTyg&t=1s>

Tetris Wiki:  
<https://tetris.fandom.com/wiki/SRS>

SFML:  
<https://github.com/SFML/SFML>

## Contributors

Quentin MOREL :

- @Im-Rises
- <https://github.com/Im-Rises>

[![GitHub contributors](https://contrib.rocks/image?repo=Im-Rises/TetrisSFML)](https://github.com/Im-Rises/TetrisSFML/graphs/contributors)
