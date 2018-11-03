#include <cstdint>
#include "ids.h"
#include "rang.hpp"
#include "uniqueid.h"

using namespace rang;

UniqueId::UniqueId(int32_t id){
    _id = id;
    std::cout << "default unique this:" <<  this << std::endl;
}

UniqueId::UniqueId(UniqueId&& move){
    std::cout << "Move unique this:" <<  this << " copy:" << &move << std::endl;
    this->_id = std::move(move._id);
    move._id = INVALID_ID;
}

UniqueId::~UniqueId(){
    if (_id) {
        if (Typeof(_id) == OJECT_A_TYPE)
            FreeA(_id);
        else if (Typeof(_id) == OJECT_B_TYPE)
            FreeB(_id);
        else
            std::cout << fg::red << style::bold << "destroy unique id INVALID TYPE this:" << this << "id:" << _id << style::reset << std::endl;
    }
    std::cout << "destroy unique id this:" <<  this << " id:" << _id << std::endl;
    _id = INVALID_ID;
}

UniqueId& UniqueId::operator=(UniqueId&& move){
    std::cout << "Move assign unique this:" <<  this << " copy:" << &move << std::endl;
    this->_id = std::move(move._id);
    move._id = INVALID_ID;
    return *this;
}

UniqueId::operator int32_t(){
    return _id;
}

int UniqueId::data(void){
    std::cout << "data unique"  << std::endl;
    return _id;
}

UniqueId::UniqueId(const UniqueId& copy){
    std::cout << "Copy unique this:" <<  this << " copy:" << &copy << std::endl;
}