// Aria Killebrew Bruehl HW09 Exercise 1 
// 
#include <iostream>
#include <string>
#include "Stck.hh"

int main() {
  std::cout << "You've just run my version of the Unix calculator utility 'dc'." << std::endl;
  std::cout << "It uses a stack to track intermediate calculations." << std::endl;

  Stck s {};
  std::string entry;
  do {
    std::cout << "Enter a command just below (h for help):" << std::endl;
    std::cin >> entry;
    if (entry == "h") {
      std::cout << "Commands:" << std::endl;
      std::cout << "\t h - display this message" << std::endl;
      std::cout << "\t q - quit" << std::endl;
      std::cout << "\t 42 - push the value 42 onto the stack" << std::endl;
      std::cout << "\t <any other number> - push that number onto the stack" << std::endl;
      std::cout << "\t + - pop off two values add them, push their sum" << std::endl;
      std::cout << "\t <some other op> - same, with times, minus, divide" << std::endl;
      std::cout << "\t ++ - increment the top of the stack" << std::endl;
      std::cout << "\t t - inspect the top of the stack" << std::endl;
      std::cout << "\t d - duplicate the top of the stack" << std::endl;
      std::cout << "\t p - print the stack's contents" << std::endl;
    } else if (entry == "+") {
      int v1 = s.pop();
      int v2 = s.pop();
      int v = v1 + v2;
      s.push(v);
    } else if (entry == "-") {
      int v1 = s.pop();
      int v2 = s.pop();
      int v = v1 - v2;
      s.push(v);
    } else if (entry == "*") {
      int v1 = s.pop();
      int v2 = s.pop();
      int v = v1 * v2;
      s.push(v);
    } else if (entry == "/") {
      int v1 = s.pop();
      int v2 = s.pop();
      int v = v1 / v2;
      s.push(v);
    } else if (entry == "d") {
      s.push(s.top());
    } else if (entry == "++") {
      s.push(s.pop()+1);
    } else if (entry == "--") {
      s.push(s.pop()-1);
    } else if (entry == "t") {
      std::cout << s.top() << std::endl;
    } else if (entry == "p") {
      std::cout << s.to_string() << std::endl;
    } else if (entry != "q") {
      int v = std::stoi(entry);
      s.push(v);
    }
  } while (entry != "q");
}


