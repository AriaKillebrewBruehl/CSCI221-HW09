// Aria Killebrew Bruehl HW09 Exercise 3 
#include "Queue.hh"
#include <string>
#include <iostream>


Queue::Queue(int capacity) :
  nodes {new int [capacity]}, // heap allocate array of ints of length capacity 
  num_nodes {0},
  capacity {capacity},
  headIndex {0}, // intial headIndex = 0
  tailIndex {0} // intital tailIndex = 0
{ }
//
bool Queue::is_empty() const {
  return (num_nodes == 0);
}
//
// enqueue(vlaue) adds vlaue to tail of queue 
void Queue::enqueue(int value) {
    nodes[tailIndex] = value; // insert value at tail of queue
    num_nodes++; // update num_nodes
    tailIndex = (tailIndex+1) % capacity; // update tailIndex, wrapping around if necessary 
}
//
// dequeue() funct removes value at front of queue 
int Queue::dequeue() {
    int node = nodes[headIndex];
    headIndex = (headIndex + 1) % capacity; //update headIndex, wrapping around if necessary 
    num_nodes--; // decrease num_nodes 
    return node;
}
//
// head() funct returns value at head of queue
int Queue::head() {
    return nodes[headIndex];
}
//
// to_string() funct constructs string of queue
std::string Queue::to_string() {
    if (is_empty()) {
        return "[ ]";
  } else {
    std::string ss = "[("+std::to_string(nodes[headIndex])+")";
    for (int i=1; i < num_nodes; i++) {
      ss += " "+std::to_string(nodes[(headIndex + i) % capacity]);
    }
    return ss + "]";
  }
}
// destructor 
Queue::~Queue() {
    delete [] nodes;
}

