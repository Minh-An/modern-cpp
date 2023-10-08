/*
 * This implementation of generators is the old C++11 implementation before 
 * C++14 using classes.
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