Maze_Recursive: Maze_Recursivo.o Metodos_Grid.o Visit_Recursivo.o
	g++ -o Maze_Recursive Maze_Recursivo.o Metodos_Pila.o Metodos_Grid.o Visit_Recursivo.o

Maze_Recursivo.o: Maze_Recursivo.cpp Maze_Recursivo.hpp
	g++ -c Maze_Recursivo.cpp

Metodos_Pila.o: Metodos_Pila.cpp Maze_Recursivo.hpp
	g++ -c Metodos_Pila.cpp

Metodos_Grid.o: Metodos_Grid.cpp Maze_Recursivo.hpp
	g++ -c Metodos_Grid.cpp

Visit_Recursivo.o: Visit_Recursivo.cpp Maze_Recursivo.hpp
	g++ -c Visit_Recursivo.cpp

clean:
	rm -f *.o 
	rm  -f Maze_Recursive