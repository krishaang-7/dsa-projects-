# Radar / Sensor Data Visualizer

A beginner C++ project that simulates sensor data processing using arrays and fundamental DSA concepts.

## Project Overview

This project simulates a sensor detecting multiple objects and storing information such as:

- Object ID
- Distance
- Angle
- Signal strength

The program provides an interactive menu that allows the user to search, sort, analyze, and generate a report from the simulated sensor data.

> Note: This is a software simulation for learning purposes. It does not connect to real radar or sensor hardware.

## Why I Built This

I built this project to apply the DSA concepts I was learning in C++ to a practical problem instead of practicing only isolated coding questions.

The project helped me understand how arrays, searching, sorting, loops, conditions, and basic statistics can work together inside a complete application.

## Features

- Display all detected objects
- Find the closest object
- Find the farthest object
- Find the strongest signal
- Search for an object by ID
- Sort objects by distance
- Calculate basic statistics
- Generate a sensor report
- Interactive menu-driven interface

## DSA Concepts Used

- Arrays
- Array traversal
- Linear search
- Minimum and maximum search
- Selection sort
- Parallel arrays
- Loops
- Conditional statements
- `switch-case`
- `do-while` loop
- Basic statistical calculations

## Data Representation

The current version uses parallel arrays.

```cpp
int objectID[] = {1, 2, 3, 4, 5};
int distance[] = {350, 460, 330, 110, 250};
int angle[] = {30, 45, 67, 55, 86};
int signal[] = {25, 45, 66, 98, 77};