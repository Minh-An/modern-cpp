/*
 * Implement generators using old C++.
 */

#include <iostream>

class my_generator {
  int i = 0;
public: 
  int operator()() {
    return i++;
  }
};

int main() {
  my_generator f;
  std::cout << f() << std::endl;
  std::cout << f() << std::endl;
  std::cout << f() << std::endl;
}