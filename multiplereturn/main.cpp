#include <iostream>
#include <string>
#include <tuple>

using namespace std;

std::tuple<int, bool, float, string> foo()
{
  return {128, true, 1.5f, "super string"};
}

int main()
{
  std::tuple<int, bool, float, string> result = foo();
  auto [value1, value2, value3, value4] = foo();
  cout << "Value1: " << value1
       << " Value2: " << value2
       << " Value3: " << value3
       << " Value4: " << value4
       << endl;
}
