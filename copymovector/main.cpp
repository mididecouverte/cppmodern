#include <algorithm>
#include <cstdint>
#include <string>
#include <iostream>
#include <typeinfo>
#include <memory>
#include <vector>
#include "ids.h"
#include "uniqueid.h"
#include "sharedid.h"
#include "rang.hpp"
 
using namespace rang;


UniqueId f(UniqueId id){
    std::cout << "function " <<  id.data() << std::endl;
    return id;
}

void TestUniqueId(){
    std::cout << fg::green << style::bold << "===> Alloc A  " << style::reset << std::endl;
    UniqueId a(AllocA());
    UniqueId b(AllocB());

    std::cout << fg::green << style::bold << "===> Move A to NA " << style::reset << std::endl;
    UniqueId na=std::move(a);
    std::cout << fg::green << style::bold << "===> Use NA  " << style::reset << std::endl;
    Use(na);
    std::cout << fg::green << style::bold << "===> Use A INVALID!!! " << style::reset << std::endl;
    Use(a);
    std::cout << fg::green << style::bold << "===> Call f(std::move(NA))  " << style::reset << std::endl;
    na = f(std::move(na));
    std::cout << fg::green << style::bold << "===> Call std::move(f(std::move(NA)))  " << style::reset << std::endl;
    na = std::move(f(std::move(na)));
}

SharedId f(SharedId id){
    std::cout << "shared function " <<  id.data() << std::endl;
    return id;
}

void TestSharedId(){
    std::cout << fg::green << style::bold << "===> Alloc A  " << style::reset << std::endl;
    SharedId a(AllocA());
    SharedId b(AllocB());

    std::cout << fg::green << style::bold << "===> Move A to NA " << style::reset << std::endl;
    SharedId na=std::move(a);
    std::cout << fg::green << style::bold << "===> Use NA  " << style::reset << std::endl;
    Use(na);
    std::cout << fg::green << style::bold << "===> Use A INVALID!!! " << style::reset << std::endl;
    Use(a);
    std::cout << fg::green << style::bold << "===> Call f(std::move(NA))  " << style::reset << std::endl;
    na = f(std::move(na));
    std::cout << fg::green << style::bold << "===> f(NA)  " << style::reset << std::endl;
    na = f(na);
}

int main (int argc, char *argv[])
{
    setControlMode(control::Auto);
    TestUniqueId();
    TestSharedId();
}
