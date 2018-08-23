#include <any>
#include <iostream>
#include <string>

using namespace std;

int main()
{
    std::cout << std::boolalpha;
    std::any anyValue = 1;
    std::cout << anyValue.type().name() << ": " << std::any_cast<int>(anyValue) << std::endl;
    anyValue = 3.14;
    std::cout << anyValue.type().name() << ": " << std::any_cast<double>(anyValue) << std::endl;
    anyValue = true;
    std::cout << anyValue.type().name() << ": " << std::any_cast<bool>(anyValue) << std::endl;
    anyValue = std::string("Super string");
    std::cout << anyValue.type().name() << ": " << std::any_cast<std::string>(anyValue) << std::endl;
}
