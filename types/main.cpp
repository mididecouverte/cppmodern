#include <string>
#include <iostream>
#include <typeinfo>
#include <memory>
#include <cstdint>

int main (int argc, char *argv[])
{
    /* Type inference */
    auto text = std::string("test");
    std::cout << "Type:" << typeid(text).name() << " Value:" << text << std::endl;

    /* nullptr */
    std::shared_ptr<std::string> testnullsmartptr = nullptr;
    std::string* testnullptr = nullptr;

    /* Strongly typed enumerations */
    enum class Colors : std::int8_t { RED = 1, GREEN = 2, BLUE = 3 };
    auto realColor = Colors::RED;
}
