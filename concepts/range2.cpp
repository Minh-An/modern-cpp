#include <iostream>
#include <string>
#include <vector>
#include <ranges>

struct User {
  std::string name;
  int age;
};

std::vector<User> users = {
  {"Thanh", 49},
  {"Hang", 49}, 
  {"An", 20},
  {"Quang", 15}
 };

bool underage(const User& user) {
  return user.age < 18;
}

int main() {
  auto result = users
    | std::views::filter(std::not_fn(underage))
    | std::views::transform([] (const auto& user) { return user.age; });

  std::ranges::copy(result, std::ostream_iterator<int>(std::cout, "\n"));
}