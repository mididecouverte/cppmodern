#include <string>
#include <chrono>
#include <iostream>
#include <typeinfo>
#include <memory>
using namespace std::chrono_literals;

int main (int argc, char *argv[])
{
    /* String litertal */
    auto textu8 = u8"I'm a UTF-8 string 😀.";
    auto textu16 = u"This is a UTF-16 string.";
    auto textu32 = U"This is a UTF-32 string.";
    auto textraw = R"(c:\test\toto)";

    std::cout << textu8 << std::endl;
    std::cout << textraw << std::endl;

    /* User defined literal */
    auto day = 24h;
    std::cout << "one day is " << day.count() << " hours" << std::endl;

    /* Binary literal */
    auto bin = 0b10101010;
    std::cout << "Bin: " << bin << std::endl;
    auto bin2 = 0B10101010;
    std::cout << "Bin2:" << bin2 << std::endl;

    /* Digit sperator */
    auto sperated = 1'000'000;
    std::cout << "sperated:" << sperated << std::endl;
    return 0;
}
