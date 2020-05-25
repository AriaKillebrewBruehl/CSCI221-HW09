// Aria Killebrew Bruehl, HW09 Exercise 4 
#include "Grid.hh"
#include <string>
#include <iostream>


int rows = 4; 
int columns = 6;


Grid::Grid(int rows, int columns) :
  grid {new bool[(rows * 2 + 1) * (columns * 2 + 1)]()}, // create a bool array filled with false for all points and edges
  num_rows {rows}, // create var to hold number of rows in grid 
  num_cols {columns} // create var to hold number of columns in grid 
{ }
// 
// setEdge(x1, y1, x2, y2, sate) funct to set state of edge connecting points (x1, y1) and (x2, y2)
//
void Grid::setEdge(int x1, int y1, int x2, int y2, bool state) {
    // set state of vertical edges 
    if (y1 - y2 == 0) {
        grid[(2 * num_cols + 1) * (2 * y1) + (2 * x1) + 1] = state; // compute location of edge in array and set state
    } 
    // set state of horizontal edges
    else if (x1 - x2 == 0) {
       grid[(2 * num_cols + 1) * (2 * y2 - 1) + (2 * x1)] = state; // compute location of edge in array and set state
    }
}
//
// setPoint(x1, y1, state) funct to set state of point (x1, y1)
//
void Grid::setPoint(int x1, int y1, bool state) {
    grid[(2 * num_cols + 1) * (2 * y1) + (2 * x1)] = state; // compute location of point in array and set state
    
}
//
// display() function to output grid using std::cout 
//
void Grid::display() {
    int i = 0;
    // loop through every row 
    for (int row = 0; row < num_rows; row++ ){ 
        // loop through every column in row 
        for (int col = 0; col < num_cols; col++){
            std::cout << (grid[i++]?"@":"+"); // output state of grid point and increment i  
            std::cout << (grid[i++]?"zzz":"---"); // output state of horizontal grid edge and increment i 
        } 
        std::cout << (grid[i++]?"@":"+") << std::endl; // output state of furthest right grid point 

        // loop through every column in between two rows 
        for (int col = 0; col < num_cols; col++){
            std::cout << (grid[i++]?"Z":"|"); // output state of vertical edge and increment i 
            std::cout << (i++, "   "); // output spaces between edges and increment i
        } 
        std::cout << (grid[i++]?"Z":"|") << std::endl; // output state of farthest right vertical edge 
    }
    // loop through columns of lowest row 
    for (int col = 0; col < num_cols; col++){
        std::cout << (grid[i++]?"@":"+");
        std::cout << (grid[i++]?"zzz":"---");
    } 
    std::cout << (grid[i++]?"@":"+") << std::endl; 
}
//
// getRows() funct to return num_rows in grid 
int Grid::getRows() {
    return num_rows;
}
//
// getCols() funct to return num_cols in grid 
int Grid::getCols() {
    return num_cols;
}
// destructor 
Grid::~Grid() {
    delete [] grid; // return memory back to heap 
}

