// Aria Killebrew Bruehl HW09 Exercise 4
//

#include <iostream>
#include <string>
#include "Grid.hh"
#include "Turtle.hh"

int main() {
  std::cout << "You've just run my version of trutle!." << std::endl;
  std::cout << "It uses a Grid class and a Turtel class to track a turtle's movements on a 2-D grid space. The turtle is currently in the middle of the grid facing North." << std::endl;

  Grid g {4, 6}; // create grid 
  Turtle t {&g}; // create turtle 

  std::string entry;
  do {
    std::cout << "Enter a command just below (h for help):" << std::endl;
    std::cin >> entry;
    // list of possible commands
    if (entry == "h") {
      std::cout << "Commands:" << std::endl;
      std::cout << "\t h - display this message" << std::endl;
      std::cout << "\t q - quit" << std::endl;
      std::cout << "\t forward - move the turtle forward one square" << std::endl;
      std::cout << "\t left - turn the turtle 90 degrees counterclockwise" << std::endl;
      std::cout << "\t right - turn the turtle 90 degrees clockwise" << std::endl;
      std::cout << "\t on - turn the turtle's trail on" << std::endl;
      std::cout << "\t off - turn the turtle's trail off" << std::endl;
      std::cout << "\t dispaly - display the grid" << std::endl;
    } else if (entry == "display") {
      g.display();
    } else if (entry == "forward") {
        t.moveForward(); 
    } else if (entry == "left") {
        t.turnLeft();
    } else if (entry == "right") {
        t.turnRight();
    } else if (entry == "on") {
        t.trail(true);
    } else if (entry == "off") {
        t.trail(false);
    }
  } while (entry != "q");

    return 0;
}