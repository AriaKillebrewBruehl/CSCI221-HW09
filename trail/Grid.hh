// Aria Killebrew Bruehl, HW09 Exercise 4 
#ifndef __GRID_HH
#define __GRID_HH

#include <string>
#include <iostream>

// Grid class to create grid for turtle to live on 
class Grid {
private:
  bool* grid;
  int num_rows;
  int num_cols;
public:  
  // Grid constructor 
  Grid(int rows, int columns);
  // Grid methods 
  void setEdge(int x1, int y1, int x2, int y2, bool state); // sets state of edge between point (x1, y1) and (x2, y2)
  void setPoint(int x1, int y1, bool state); // sets state of point (x1, y1)
  void display(); // displays grid to terminal 
  int getRows();
  int getCols();
  ~Grid(); // destructor 
};

#endif




