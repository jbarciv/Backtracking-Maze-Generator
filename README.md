# Recursive VS Iterative Dynamic Backtracking Maze Generator with C++ 

## Description

The next respository has two **C++** programs. Both implement a **Dynamic Maze Generator** with a ramdomized version of the depth-first search algorithm (for more information read https://en.wikipedia.org/wiki/Maze_generation_algorithm#Recursive_division_method). One program uses a **recursive** method and the other an **iterative** method.

## Table of Contents

- [Prerequisites](#prerequisites)
- [Installation](#installation)
- [Usage](#usage)
- [Acknowldegements](#acknowledgements)

## Prerequisites


## Installation

```
$ git clone https://github.com/jbarciv/Recursividad-PS/
```

Change your directory to the one where you have clone the repository. Choose between the Iterative or Recursive program and move to this folder and type:

```
$ make
```

you will be using the Makefile for compiling and linking all the .cpp files.

## Usage

#### The program asks you the dimensions for the maze:
For running the program you have some options (we'll be using  as an example the **recursive** program). Just type this:

```
$ ./Maze_Recursive
```
#### You pass the dimesions directly to the maze:

```
$ ./Maze_Recursive 30 45
```
The firts number is the vertical size (number of rows) and the second one is the horizontal size. 30 and 45 are just examples, try to play whit differents dimesions. I recommend you using a number of columns larger than the number of rows, it will be more square.

#### Testing mode:
```
$ ./Maze_Recursive 30 45 1
```
With a third parameter you can activate the testing mode. You won't see the maze, just the results of time and iterations.

## Acknowldegements
## Future

For the Readme: 
* finish writing basics
* explain in-depth some things
  * +1 in the number of rows or columns + add the code (#macro)
  * how to add UNICODE characters for aesthetics reasons (add the code)
* Add pictures: gif

For coding:
* translate everything to english
* unify everything to c++ -> OOP
