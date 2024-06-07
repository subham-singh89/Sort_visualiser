
# Sorting Visualiser

A sorting visualisation application written in C++.

![A Visualisation of the application](visualisation.gif)


## Features

- Can change the number of bars between 1000 - 100000
- Live update on the algorithm
- Can shuffle the bars
- Multiple sorting algorithms
- Visual indication of the number of comparisons and swaps
- Sorting algorithms runs on seperate threads from rendering.

  
## Installation 

This is a basic CMake project so you need to install cmake.

```bash 
  git clone --recursive https://github.com/burakssen/SortingVisualiser
  cd SortingVisualiser
  mkdir build
  cd build
  cmake ..
  make
```

After this now run

```bash
    ./sorting
```

on build directory.


## Used Modules

There some project used for visualisation.

- [ImGui](https://github.com/ocornut/imgui) used for ui buttons.
- [rlImGui](https://github.com/raylib-extras/rlImGui) used for ease of integration between imgui and raylib.
- [raylib](https://github.com/raysan5/raylib) used for rendering.


  
