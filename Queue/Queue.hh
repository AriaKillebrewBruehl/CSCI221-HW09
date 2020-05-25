// Aria Killebrew Bruehl HW09 Exercise 3 
#ifndef _QUEUE_HH
#define _QUEUE_HH

#include <string>

class Queue {
private:
  int *nodes;
  int num_nodes;
  int capacity;
  int headIndex;
  int tailIndex;
public:  
  // constructor 
  Queue(int capacity);
  // methods 
  bool is_empty() const;
  void enqueue(int value);
  int dequeue();
  int head();
  std::string to_string();
  // desturctor 
  ~Queue();
};
#endif