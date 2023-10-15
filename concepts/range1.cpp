#include <iostream>
#include <string>
#include <vector>

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

int main() {
  std::ranges::sort(users, std::less{}, &User::age);

  for(auto user: users) {
    std::cout << user.name << ", " << user.age << std::endl;
  }
}