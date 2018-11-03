#include <string>
#include <iostream>
#include <typeinfo>
#include <memory>
#include <cstdint>

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

    /* nullptr */
    std::shared_ptr<std::string> testnullsmartptr = nullptr;
    std::string* testnullptr = nullptr;

    /* nullptr_t */
    double *dp;
    function(dp);
    function(nullptr);

    /* Strongly typed enumerations */
    enum class Colors : std::int8_t { RED = 1, GREEN = 2, BLUE = 3 };
    auto realColor = Colors::RED;
}
