# STD Accumulate Examples
[![CMake](https://github.com/EliseBriers/std-accumulate-examples/actions/workflows/cmake.yml/badge.svg)](https://github.com/EliseBriers/std-accumulate-examples/actions/workflows/cmake.yml)
[![Lisence](https://img.shields.io/badge/License-MIT-yellow.svg)](LICENSE)

## Introduction
This repo contains all the code files shown in the video [C++ Accumulate: More Powerful Than You Think](https://youtu.be/mvC81eguSn8). `main.cpp` contains all the unit tests, other classes can be found in their corresponding files.

## Building and testing
Build the project using cmake and a compiler with C++ 20 abilities. Most modern compilers should work. Making the file will result in the unit tests getting executed automatically.

```shell
git clone https://github.com/EliseBriers/std-accumulate-examples
cd std-accumulate-examples
mkdir build
cd build
cmake ..
make
```


## Contributing
Since this project is the example code for a youtube video, no PRs will be accepted that modify code visible in this video. Code that adds unit tests or other examples might be merged, but it's low on my priority list.
