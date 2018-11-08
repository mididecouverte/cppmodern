#include <string>
#include <iostream>
#include <typeinfo>
#include <map>
#include <memory>
#include <cstdint>
#include <vector>

void function(double* pd)
{
   std::cout << "Pointer to double overload" << std::endl;
}
 
void function(std::nullptr_t nullp)
{
   std::cout << "null pointer overload" << std::endl;
}

int main (int argc, char *argv[])
{
    /* Type inference */
    auto text = std::string("test");
    std::cout << "Type:" << typeid(text).name() << " Value:" << text << std::endl;

    std::map<std::uint16_t, std::string> myMap;
    // fill map
    std::map<std::uint16_t, std::string>::iterator it = myMap.find(42);
    auto it2 = myMap.find(42);


    /* nullptr */
    std::shared_ptr<std::string> testnullsmartptr = nullptr;
    std::string* testnullptr = nullptr;

    /* nullptr_t */
    double dp = 3.1416;
    function(&dp);
    function(nullptr);

    /* Strongly typed enumerations */
    enum class Colors : std::int8_t { RED = 1, GREEN = 2, BLUE = 3 };
    auto realColor = Colors::RED;
}
