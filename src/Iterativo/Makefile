Maze_Iterative: Maze_Iterativo.o Metodos_Pila.o Metodos_Grid.o Visit_Iterativo.o
	g++ -o Maze_Iterativo Maze_Iterativo.o Metodos_Pila.o Metodos_Grid.o Visit_Iterativo.o

Maze_Iterativo.o: Maze_Iterativo.cpp Maze_Iterativo.hpp
	g++ -c Maze_Iterativo.cpp

Metodos_Pila.o: Metodos_Pila.cpp Maze_Iterativo.hpp
	g++ -c Metodos_Pila.cpp

Metodos_Grid.o: Metodos_Grid.cpp Maze_Iterativo.hpp
	g++ -c Metodos_Grid.cpp

Visit_Iterativo.o: Visit_Iterativo.cpp Maze_Iterativo.hpp
	g++ -c Visit_Iterativo.cpp

clean:
	rm -f *.o 
	rm -f Maze_Iterativo
