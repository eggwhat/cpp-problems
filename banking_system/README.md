# How to build the project

## Requirements
- CMake 3.12
- C++ 14 compatible compiler
- Conan 2.5

## Steps to build
Note that these steps work for MacOS only.

First we need a Conan profile 
```bash
conan profile detect --force
```
Install packages with Conan
```bash
conan install . --output-folder=build --build=missing
```
Build
```bash
cd build
cmake .. -DCMAKE_TOOLCHAIN_FILE=conan_toolchain.cmake -DCMAKE_BUILD_TYPE=Release -GNinja
cmake --build .
```
