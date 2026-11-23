#include <cstdio>
#include <iostream>
#include <memory>
#include <utility>

/* Move semantics. Wrap an Lvalue into an Xvalue (object whose resources can be reused or moved) */

//Lvalue: expression with identity
//int x = 10;
//y;

//PRvalue: produce value without identifying existing object
//10;
//x + y;

//Xvalue: identify reusable or movable object
//std::move(x);

//Rvalue: either PRvalue or Xvalue

class Buffer {
private:
  std::unique_ptr<int[]> data; // destroys when out of scope
  int size;

public:
  explicit Buffer(int n) : data(std::make_unique<int[]>(n)), size(n) {}

  Buffer(const Buffer &) = delete;
  Buffer &operator=(const Buffer &) = delete;

  Buffer(Buffer &&other) noexcept
      : data(std::move(other.data)), size(std::exchange(other.size, 0)) {}

  int getSize() const { return size; }
};

int main() {
  Buffer first(100); //Lvalue

  Buffer second = 
      std::move(first); //Lvalue wrapped by move to become Xvalue

  std::cout << "First buffer: " << first.getSize() << '\n';
  std::cout << "Second buffer: " << second.getSize() << '\n';
}
