/*
 * Implement generators using C++20 coroutines.
 * To compile:
 *    clang++ -std=c++2a gen3.cpp
 */

#include <coroutine>
#include <iostream>
#include <cassert>

template <typename T> 
struct generator {
  struct promise_type;

  using handle_type = std::coroutine_handle<promise_type>;
  handle_type handle;

  struct promise_type {
    T current_value;

    auto get_return_object() {
      return generator(*this);
    }

    std::suspend_always initial_suspend() {
      //return std::experimental::suspend_always();
      return {};
    }

    std::suspend_always  final_suspend() noexcept {
      //return std::experimental::suspend_always();
      return {};
    }

    std::suspend_always  yield_value(const T& value) {
      current_value = value;
      //return std::experimental::suspend_always();
      return {};
    }

    void return_void() {
    }

    void unhandled_exception() {
      std::terminate();
    }

  };

  generator(promise_type& promise) : handle(handle_type::from_promise(promise)) {

  }

  generator(const generator&) = delete;

  generator& operator=(const generator&) = delete;

  generator(generator&& other) : handle(other.handle) {
    other.handle = nullptr;
  }

  generator& operator=(generator&& other) {
    if (this != &other) {
      handle = other.handle;
      other.handle = nullptr;
    }
  }

  ~generator() {
    if (handle) {
      handle.destroy();
    }
  }

  T operator()() {
    assert(handle != nullptr);
    handle.resume();
    return handle.promise().current_value;
  }
};

generator<int> f() {
  int i = 0;
  while (true) {
    co_yield i++;
  }
}


int main() {
  auto g = f();
  std::cout << g() << std::endl;
  std::cout << g() << std::endl;
  std::cout << g() << std::endl;
}