#include <string>
#include <chrono>
#include <iostream>
#include <typeinfo>
#include <memory>
using namespace std::chrono_literals;

int main (int argc, char *argv[])
{
    // Type inference
    auto text = std::string("test");
    std::cout << "Type:" << typeid(text).name() << " Value:" << text << std::endl;

    //nullptr
    std::shared_ptr<std::string> testnullsmartptr = nullptr;
    std::string* testnullptr = nullptr;

    // String litertal
    auto textu8 = u8"I'm a UTF-8 string 😀.";
    auto textu16 = u"This is a UTF-16 string.";
    auto textu32 = U"This is a UTF-32 string.";
    auto textraw = R"(c:\test\toto)";

    std::cout << textu8 << std::endl;
    std::cout << textraw << std::endl;

    //User defined literal
    auto day = 24h;
    std::cout << "one day is " << day.count() << " hours" << std::endl;
    return 0;
}
