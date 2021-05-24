Maze_Iterative: mainMaze_Iterative.o Stack_Methods.o Grid_Methods.o Visit_Iterative.o
	g++ -o Maze_Iterative mainMaze_Iterative.o Stack_Methods.o Grid_Methods.o Visit_Iterative.o

Maze_Iterative.o: mainMaze_Iterative.cpp Maze_Iterative.hpp
	g++ -c mainMaze_Iterative.cpp

Stack_Methods.o: Stack_Methods.cpp Maze_Iterative.hpp
	g++ -c Stack_Methods.cpp

Grid_Methods.o: Grid_Methods.cpp Maze_Iterative.hpp
	g++ -c Grid_Methods.cpp

Visit_Iterative.o: Visit_Iterative.cpp Maze_Iterative.hpp
	g++ -c Visit_Iterative.cpp

clean:
	rm -f *.o 
	rm -f Maze_Iterative
