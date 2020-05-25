// Aria Killebrew Bruehl HW09 Exercise 4
#include "Turtle.hh"
#include "Grid.hh"
#include <string>
#include <iostream>

Turtle::Turtle(Grid* grid) :
    g {grid},
    trailState {true},
    xpos {grid->getCols()/2}, // position turtle in center of grid 
    ypos {grid->getRows()/2},
    dir {'N'}
{ }
//
// trail(state) funct to set state of trail 
//
void Turtle::trail(bool state) {
    trailState = state;
}
//
// moveForward() funct taken from HW02 turtle.cc to increment turtle's xpos and ypos
// 
void Turtle::moveForward() {
  // move  turtle forward
  // check that moving forward wont move turtle off grid 
  if (xpos <= 0 && dir == 'W') {
      std::cout << "The turtle cannot move forward anymore, turn to continue." << std::endl;
  } else if (xpos >= g->getCols() && dir == 'E') {
      std::cout << "The turtle cannot move forward anymore, turn to continue." << std::endl;
  } else if (ypos <= 0 && dir == 'N') {
      std::cout << "The turtle cannot move forward anymore, turn to continue." << std::endl;
  } else if (ypos >= g->getRows() && dir == 'S') {
      std::cout << "The turtle cannot move forward anymore, turn to continue." << std::endl;
  } else {
    int lastX = xpos; // set lastX as current xpos
    int lastY = ypos; // set lastY as current ypos
    xpos += (dir == 'E') - (dir == 'W'); // using bool values to move turtle according to dir
    ypos -= (dir == 'N') - (dir == 'S');
    g->setPoint(xpos, ypos, trailState);
    // ensure x1 > x2 and y1 > y2 before call to setEdge 
    if (dir == 'W' || dir == 'N') {
        g->setEdge(xpos, ypos, lastX, lastY, trailState);
    } else {
        g->setEdge(lastX, lastY, xpos, ypos, trailState);
    }
  } 
}
void Turtle::turnRight() {
  // trun turtle right
  if (dir == 'E') {
    dir = 'S';
  } else if (dir == 'S') {
    dir = 'W';
  } else if (dir == 'W') {
    dir = 'N';
  } else if (dir == 'N') {
    dir = 'E';
  }
}

void Turtle::turnLeft() {
  // turn turtle left
  if (dir == 'E') {
    dir = 'N';
  } else if (dir == 'N') {
    dir = 'W';
  } else if (dir == 'W') {
    dir = 'S';
  } else if (dir == 'S') {
    dir = 'E';
  }
}
// destructor 
Turtle::~Turtle() {
}