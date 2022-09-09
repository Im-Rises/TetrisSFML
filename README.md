# NesEmulator

<p align="center">
      <img src="https://user-images.githubusercontent.com/59691442/183268126-b3d19e66-8f2d-463a-805e-ae6ef7cc6c01.png" alt="cmakeLogo" style="height:60px;"/>
      <img src="https://img.shields.io/badge/C%2B%2B-00599C?style=for-the-badge&logo=c%2B%2B&logoColor=white" alt="cppLogo" style="height:60px;"/>
      <img src="https://user-images.githubusercontent.com/59691442/183268128-6f1a7773-a77c-4635-9a61-daa72c023915.png" alt="sfmlLogo" style="height:60px;"/>
</p>

## Description

Tetris game written in C++ using SFML lib available for windows, linux and macOS.

## Features

PlaceHolder
<!--
- Audio
- Window resizing without image deformation
- Window full screen
- All main 5 types of cartridge are implemented (a big variety of games can be played)
- cross-platform (WWindows, Linux, MacOs)
-->

## Images

PlaceHolder

## Video

PlaceHolder

## Quickstart

To download the emulator, you can click one of the icons below depending on your operating system, or you can click the
release section of the GitHub page.

Depending on you `operating system` you will need to install some libs, they are installed differently depending on your
system, please follow one of the section below `Windows` or `Linux` or `MacOs`.

### Windows

<a href="https://github.com/Im-Rises/NesEmulator/releases/latest"><img src="https://img.shields.io/badge/Windows-0078D6?style=for-the-badge&logo=windows&logoColor=white" alt="cmakeLogo" style="height:40px;"/></a>

For Windows users you don't need to install the libs, you just need to be carefully that you have the
`*.dll` next to the `space_invaders_arcade_emulator.exe` or the emulator won't start.

Once everything is set up by you can start the emulator by double-clicking the executable of typing the following
command next to it:

```bash
.\NesEmulator.exe
```

### Linux

<a href="https://github.com/Im-Rises/NesEmulator/releases/latest"><img src="https://img.shields.io/badge/Linux-FCC624?style=for-the-badge&logo=linux&logoColor=black" alt="cmakeLogo" style="height:40px;"/></a>

For Linux users, you need to install the SDL2 lib, to do so type one of the following commands:

```bash

```

or if you're a developer and want to compile the Emulator, please install this version of SDL2:

```bash
sudo apt-get install libsfml-dev
```

Then you can start by double-clicking the executable of typing the following command next to it:

```bash
./NesEmulator
```

### MacOs

<a href="https://github.com/Im-Rises/NesEmulator/releases/latest"><img src="https://img.shields.io/badge/mac%20os-000000?style=for-the-badge&logo=apple&logoColor=white" alt="cmakeLogo" style="height:40px;"/></a>

For macOS users you will need to install Brew, please follow the instruction in the link below:  
<https://brew.sh>

Once it is installed, you can type the following command to install SDL2.

```bash
brew install sfml
```

Then you can start by double-clicking the executable of typing the following command next to it:

```bash
./NesEmulator
```

## Game controls

Placeholder

## Project architecture

<!--
~~~
project-revision
├── dataset
|  ├── test
|  ├── train
├── docs
├── misc
|   ├── dataset
|   ├── resize.py
├── src
|   ├── denoise
|   |   |── __init__.py
|   |   |── denoise.py
|   |   |── errors.py
|   ├── noise
|   |   |── __init__.py
|   |   |── errors.py
|   |   |── noise.py
|   ├── results
|   ├── cobra.py
|   ├── cobramachine.py
|   ├── denoise.py
|   ├── helper.py
|   ├── main.py
|   ├── req.txt
├── README.md
├── guidelines.md
├── proposal.md
~~~
-->

## Compilation

To compile the emulator, the first thing you need to do is installing a C++ compiler:
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

## Run tests

Placeholder
<!--
The CPU good behaviour has been tested with the `nestests.nes` test rom that you can find in the test_roms folder.

A CMake test is set up to directly test the program. You can find it in the `test`folder and start it by typing the command below at the project root folder.

```bash
ctest
```
-->

## Github-Actions

[![flawfinder](https://github.com/Im-Rises/NesEmulator/actions/workflows/flawfinder.yml/badge.svg?branch=main)](https://github.com/Im-Rises/NesEmulator/actions/workflows/flawfinder.yml)
[![CMake](https://github.com/Im-Rises/NesEmulator/actions/workflows/cmake.yml/badge.svg?branch=main)](https://github.com/Im-Rises/NesEmulator/actions/workflows/cmake.yml)
[![CodeQL](https://github.com/Im-Rises/NesEmulator/actions/workflows/codeql.yml/badge.svg?branch=main)](https://github.com/Im-Rises/NesEmulator/actions/workflows/codeql.yml)
[![Microsoft C++ Code Analysis](https://github.com/Im-Rises/NesEmulator/actions/workflows/msvc.yml/badge.svg?branch=main)](https://github.com/Im-Rises/NesEmulator/actions/workflows/msvc.yml)
[![Cpp Cmake Publish](https://github.com/Im-Rises/NesEmulator/actions/workflows/cpp-cmake-publish.yml/badge.svg?branch=main)](https://github.com/Im-Rises/NesEmulator/actions/workflows/cpp-cmake-publish.yml)

The project is set with a set of different scripts:

- flawfinder : to check the code for security flaws
- CMake : to compile the project
- CodeQl : to check quality of the code
- Microsoft C++ Code Analysis : to check the code for security flaws
- Cpp Cmake Publish : to publish the project on GitHub

## Documentations

Main documentation:  
<>

SFML:  
<https://github.com/SFML/SFML>  

## Contributors

Quentin MOREL :

- @Im-Rises
- <https://github.com/Im-Rises>

[![GitHub contributors](https://contrib.rocks/image?repo=Im-Rises/TetrisSFML)](https://github.com/Im-Rises/TetrisSFML/graphs/contributors)
