#include <iostream>
//#include <concepts>

bool is_power_of_2(std::integral auto i) {
  return (i & (i - 1)) == 0 && i > 0;
}

template <std::floating_point T>
bool is_power_of_2(T x) {
  int exp;
  const T mantissa = std::frexp(x, &exp);
  return mantissa == T(.5);
}

int main() {
  std::cout << "is_power_of_2(.25) = " << is_power_of_2(.25) << std::endl;
  std::cout << "is_power_of_2(4) = " << is_power_of_2(4) << std::endl;
  std::cout << "is_power_of_2(.125) = " << is_power_of_2(.125) << std::endl;
  std::cout << "is_power_of_2(.1) = " << is_power_of_2(.1) << std::endl;
  std::cout << "is_power_of_2(3) = " << is_power_of_2(3) << std::endl;
}