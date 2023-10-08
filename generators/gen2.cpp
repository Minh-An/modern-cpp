/*
 * This implementation of generators is the C++14 implementation using lambdas.
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
