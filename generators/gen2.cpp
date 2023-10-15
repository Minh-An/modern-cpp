/*
 * Implement generators using C++14 lambda feature.
 */

#include <iostream> 

int main() {

  auto f = [i = 0]() mutable {
    return i++;
  };

  std::cout << f() << std::endl;
  std::cout << f() << std::endl;
  std::cout << f() << std::endl;
}
