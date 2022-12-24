<div align="center">
  <a align="center" href="https://www.youtube.com/watch?v=mvC81eguSn8">
    <img src="https://img.youtube.com/vi/mvC81eguSn8/mqdefault.jpg" width=30%>
  </a>
  <h1>STD Accumulate Examples</h1>
  <p>
    Git repo for the video <a href="https://www.youtube.com/watch?v=mvC81eguSn8">C++ Accumulate: More Powerful Than You Think</a>.
    <br>
    <sub>By <a href="https://www.youtube.com/@ElisePlusPlus">Elise++</a></sub><br><br>
    <a href="/../../actions/workflows/cmake.yml">
      <img src="/../../actions/workflows/cmake.yml/badge.svg">
    </a>
    <a href="LICENSE">
      <img src="https://img.shields.io/badge/License-MIT-yellow.svg">
    </a>
  </p>
</div>

---

## Introduction
This repo contains all the code files shown in the video [C++ Accumulate: More Powerful Than You Think](https://youtu.be/mvC81eguSn8). `main.cpp` contains all the unit tests, other classes can be found in their corresponding files.

## Building and testing
### Manually
Build the project using cmake and a compiler with C++ 20 abilities. Most modern compilers should work. Making the file will result in the unit tests getting executed automatically.

```shell
git clone https://github.com/EliseBriers/std-accumulate-examples
cd std-accumulate-examples
mkdir build
cd build
cmake ..
cmake --build .
```

### Visual Studio (Windows)
The easiest way to build and run the project on windows is opening it in a recent version of Vidual Studio. This project has been tested using Visual Studio 2022.

## Contributing
Since this project is the example code for a youtube video, no PRs will be accepted that modify code visible in this video. Code that adds unit tests or other examples might be merged, but it's low on my priority list.
