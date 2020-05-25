// Aria Killebrew Bruehl, HW09 Exercise 4 
#ifndef __TURTLE_HH
#define __TURTLE_HH

#include <string>
#include <iostream>
#include "Grid.hh"

class Turtle {

private:
  Grid* g;
  int xpos;
  int ypos;
  char dir;
  bool trailState;
public:  
  // constructors 
  Turtle(Grid* grid);
  // methods 
  void trail(bool state);
  void moveForward();
  void turnRight();
  void turnLeft();
  // destructor 
  ~Turtle();
};

#endif