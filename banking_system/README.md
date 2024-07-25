# How to build the project

## Requirements
- CMake 3.12
- C++ 14 compatible compiler
- Conan 2.5
- Ninja

## Steps to build
Note that these steps work for macOS only.

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
cd build;
cmake .. -DCMAKE_TOOLCHAIN_FILE=conan_toolchain.cmake -DCMAKE_BUILD_TYPE=Release -GNinja;
cmake --build .;
```
Run
```bash
./build/apps/banking_system
```

## Debugging
First create a new conan profile and set its build_type to Debug
```bash
conan profile new debugprofile --detect   
```
Example profile
```
[settings]
arch=armv8
build_type=Debug
compiler=clang
compiler.cppstd=gnu14
compiler.libcxx=libc++
compiler.version=12
os=Macos
```


Install packages with Conan
```bash
conan install . --output-folder=build --build=missing -pr debugprofile
```
Build
```bash
cd build;
cmake .. -DCMAKE_TOOLCHAIN_FILE=conan_toolchain.cmake -DCMAKE_BUILD_TYPE=Debug -GNinja;
cmake --build .;
```

