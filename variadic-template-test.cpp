#include <iostream>
using namespace std;

void print(){
  cout << "Void arg function called last\n";
}

//take variable number of args of any type and act on all of them (including void)
template <typename T, typename... Types>
void print(T var1, Types... var2){
  cout << var1 << endl;
  print(var2...);
}

int main(){
  print(1, 2, 3.14, "string", 'c',
        "printed int, float, string, char");
  return 0;
}

//COMPILE: c++ variadic-template-test.cpp
//OUTPUT:
// 1
// 2
// 3.14
// string
// c
// printed int, float, string, char
// Void arg function called last
