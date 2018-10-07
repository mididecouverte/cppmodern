#include <string>
#include <iostream>
#include <typeinfo>
#include <memory>
#include "rang.hpp"

using namespace std;
using namespace rang;

class test
{
public:
        test(std::string text)
        {
            _text = text;
            std::cout << style::bold << "contructor:" << _text << std::endl;
        }

        ~test()
        {
            std::cout << "Destructor:" << _text <<  std::endl;
        }

        std::string text()
        {
            return _text;
        }

        operator std::string()
        {
            return _text;
        }


private:
    std::string _text = "";
};

void shared(std::shared_ptr<test> param)
{
    std::cout << "use count:" << param.use_count() << std::endl;
}

void test_shared()
{
    /* shared_ptr */
    std::cout << fg::green << "shared_ptr" << fg::reset << style::reset << std::endl;
    std::shared_ptr<char> sp( new char[100], std::default_delete<char[]>());

    std::shared_ptr<test> strptr = std::make_shared<test>("Shared");
    std::cout << "Value:" << (std::string)*strptr << std::endl;
    std::cout << "Value:" << strptr->text() << std::endl;
    std::cout << "Value:" << strptr.get()->text() << std::endl;
    std::cout << "use count:" << strptr.use_count() << std::endl;
    shared(strptr);
}

void test_unique()
{
    /* unique_ptr */
    std::cout << fg::green << "unique_ptr" << fg::reset << std::endl;
    std::unique_ptr<test> strunptr = std::make_unique<test>("Unique");
    std::unique_ptr<test> strunptr2;
    strunptr2 = std::move(strunptr);
    std::cout << "Pointer1:" << std::hex << (long long)strunptr.get() << std::dec << std::endl;
    std::cout << "Pointer2:" << std::hex << (long long)strunptr2.get() << std::dec   << std::endl;
}

void test_weak()
{
    /* weak_ptr */
    std::cout << fg::green  << "weak_ptr" << fg::reset << std::endl;
    std::shared_ptr<test> strptr = std::make_shared<test>("Shared");
    std::weak_ptr<test> strweakptr(strptr);
    std::cout << "use count:" << strweakptr.use_count() << std::endl;
    auto sp2 = strweakptr.lock();
    strptr.reset();
    std::cout << "use count:" << sp2.use_count() << std::endl;
    std::cout << "Value:" << (std::string)*sp2 << std::endl;
}

int main (int argc, char *argv[])
{
    setControlMode(control::Auto);
    test_shared();
    std::cout << std::endl;
    test_unique();
    std::cout << std::endl;
    test_weak();
    return 0;
}
