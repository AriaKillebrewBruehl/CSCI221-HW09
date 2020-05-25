// Aria Killebrew Bruehl HW09 Exercises 1 and 2 
// Stck header file 
#ifndef __STCK_HH
#define __STCK_HH

#include <string>
#include <iostream>

class Stck {

private:
  static const int kInitialCapacity;
  int *elements;
  int num_elements;
  int capacity;
public: 
// constructor  
  Stck(void);
  // methods 
  bool is_empty() const;
  void resize();
  void push(int value);
  int pop();
  int top() const;
  int inspect(int position) const;
  int size(void) const;
  std::string to_string();
  // operators
  void operator+=(int value);
  int operator--(void);
  int operator()(void) const;
  int operator[](int position) const;
  // destructor 
  ~Stck();
};
std::ostream& operator<<(std::ostream& os, const Stck& s);

#endif




