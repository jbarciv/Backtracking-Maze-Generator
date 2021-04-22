#include <iostream>

using namespace std;

#define WIDTH 20
#define HEIGHT 20

void init_visited(int visited[WIDTH][HEIGHT]){
    for ( int i = 0; i < HEIGHT; i++ ) {
        for ( int j = 0; j < WIDTH; j++ ) {
            if (j==WIDTH-1 || i==HEIGHT-1 || j==0 || i==0)
                visited[i][j] = 1; 
            else
                visited[i][j] = 0; 
        }
    }
}

void init_vertical(char const *vertical[WIDTH][HEIGHT]){
    for ( int i = 0; i < HEIGHT; i++ ) {
        for ( int j = 0; j < WIDTH; j++ ) {
            if (i==HEIGHT-1 || j==0 || i==0)
                vertical[i][j] = "  ";
            else if (j==WIDTH-1)
                vertical[i][j] = "|"; 
            else 
                vertical[i][j] = "|  ";
        }
    }
}

void init_horizontal(char const *horizontal[WIDTH][HEIGHT]){
    for ( int i = 0; i < HEIGHT; i++ ) {
        for ( int j = 0; j < WIDTH; j++ ) {
            if (j==0 || i==0)
                horizontal[i][j] = "  ";
            else if (j==WIDTH-1)
                horizontal[i][j] = "+"; 
            else
                horizontal[i][j] = "+--"; 
        }
    }
}

void debug(int visited[WIDTH][HEIGHT],
            const char *vertical[WIDTH][HEIGHT],
            const char *horizontal[WIDTH][HEIGHT]){

    // imprimir matriz visited
    for ( int i = 0; i < HEIGHT; i++ ) {
        for ( int j = 0; j < WIDTH; j++ ) 
            cout << visited[i][j] << ", ";
        cout << endl;
    }

    // imprimir laberinto
    for ( int i = 0; i < HEIGHT; i++ ) {
        for ( int j = 0; j < WIDTH; j++ ) {
            cout << horizontal[i][j];
        }
        cout << endl;   
        for ( int j = 0; j < WIDTH; j++ ) {
            cout << vertical[i][j];
        }
        cout << endl;   
    }

}

void walk (int visited[WIDTH][HEIGHT],
            const char *vertical[WIDTH][HEIGHT],
            const char *horizontal[WIDTH][HEIGHT],
            int x, int y) {

    // debug(visited,vertical,horizontal);

    visited[y][x] = 1;
    int directions[4][2] = {{x - 1, y}, {x, y + 1}, {x + 1, y}, {x, y - 1}};
    int rand_index = rand() % 4;
    
    for (int i = 0; i < 4; i++, rand_index=(rand_index+1)%4 ) {
        int xx = directions[rand_index][0];
        int yy = directions[rand_index][1];
        
        if (visited[yy][xx] == 1) continue;
        if (xx==x) horizontal[max(yy,y)][x]= "+  ";
        if (yy==y) vertical[y][max(xx,x)]= "   ";
        walk(visited,vertical,horizontal,xx,yy);
    }
}

int make_maze () {

    int visited[WIDTH][HEIGHT] {};
    init_visited(visited);

    char const *vertical[WIDTH][HEIGHT] {};
    init_vertical(vertical);

    char const *horizontal[WIDTH][HEIGHT] {};
    init_horizontal(horizontal);

    // debug(visited,vertical,horizontal);

    int x = 1, y = 1;

    walk(visited, vertical, horizontal, x, y);

    debug(visited,vertical,horizontal);

    return 0;
}

int main(){
    // initialize random seed
    srand (time(NULL));

    // int width = 0, height = 0;
    // cout << "Enter width: " << endl;
    // cin >> width;
    // cout << "Enter width: " << endl;
    // cin >> height;

    make_maze();
    return 0;
}