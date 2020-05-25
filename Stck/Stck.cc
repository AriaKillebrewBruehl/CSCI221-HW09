// Aria Killebrew Bruehl HW09 Exercises 1 and 2 
//
#include "Stck.hh"
#include <cassert>
#include <string>
#include <iostream>


const int Stck::kInitialCapacity = 5; // set initial capacity 

Stck::Stck() :
  elements {new int [kInitialCapacity]}, // heap allocate array of ints length kInitialCapacity
  num_elements {0},
  capacity {kInitialCapacity}
{ }

bool Stck::is_empty() const {
  return (num_elements == 0);
}
// 
// resize() funct places items in elements into new array of double the size, then deletes old array
void Stck::resize(){
  int newCapacity = 2*capacity; // compute new capacity 
  int* newElements = new int[newCapacity]; // create new array of size newCapacity
  // traverse old array and copy items into newElements
  for (int i = 0; i < num_elements; i++) {
    newElements[i] = elements[i];
  }
  delete [] elements; // delete old array 
  elements = newElements; // update elements
  capacity = newCapacity; // update capacity 
}
//
// push(value) funct to add vlaue to Stck
void Stck::push(int value) {
  // call to resize funt if num_elements is greater than capacity 
  if (num_elements >= capacity) {
    resize();
  } 
  elements[num_elements] = value; // add value to Stck 
  num_elements++; // update num_elements
}  
//
// pop() funct to remove item from Stck 
int Stck::pop() {
  assert(!is_empty());
  num_elements--; // decreate num_elements
  return elements[num_elements];
}  
//
// top() funct to return top of Stck
int Stck::top() const{
  assert(!is_empty());
  return elements[num_elements-1];
}  
// 
// inspect(p) to return value stored at p
int Stck::inspect(int p) const{
  return elements[p];
}
// 
// to_string() funct uses inpect to construct string of Stck 
std::string Stck::to_string() {
  if (is_empty()) {
    return "[ ]";
  } else {
    int i = num_elements-1;
    std::string ss = "[("+std::to_string(inspect(num_elements-1))+")";
    for (i=num_elements-2; i>=0; i--) {
      ss += " "+std::to_string(inspect(i));
    }
    return ss + "]";
  }
}
// 
// += definition using push()
 void Stck::operator+=(int value){
   push(value);
 }
 //
 // -- definition using pop()
int Stck::operator--(void){
  int v = pop();
  return v;
}
//
// () definition using top()
int Stck::operator()(void) const{
  int v = top();
  return v;
}
//
// [] definition equivalent to insepct(p)
int Stck::operator[](int position) const{
  int v = inspect(position);
  return v;
}
//
// size() funct returns num_elements of Stck 
int Stck::size(void) const{
  return num_elements;
}
//
// << outputs contents of Stck 
std::ostream& operator<<(std::ostream& os, const Stck& s){
  os << "[(" + std::to_string(s()) + ")";
  for (int i = s.size()-2; i >=0; i--) {
    os << " " + std::to_string(s[i]);
  }
  os << "]";
  return os;
}
// destructor 
Stck::~Stck() {
  delete [] elements;
}

