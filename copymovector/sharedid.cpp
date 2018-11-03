#include <atomic>
#include <cstdint>
#include "ids.h"
#include "rang.hpp"
#include "sharedid.h"

using namespace rang;

SharedId::SharedId(int32_t id){
    _id = id;
    RefcountIncrease();
    std::cout << "default shared this:" <<  this << " id:" << _id << " count:" << RefCount() << std::endl;
}

SharedId::SharedId(const SharedId& copy){
    this->_id = copy._id;
    this->_refcount = copy._refcount;
    RefcountIncrease();
    std::cout << "Copy shared this:" <<  this << " copy:" << &copy << " id:" << _id << " count:" << RefCount() << std::endl;
}

SharedId::SharedId(SharedId&& move){
    this->_id = std::move(move._id);
    this->_refcount = std::move(move._refcount);
    move._id = INVALID_ID;
    move._moved = true;
    std::cout << "Move shared this:" <<  this << " copy:" << &move << " id:" << _id << " count:" << RefCount() << std::endl;
}

SharedId::~SharedId(){
    RefcountDecrease();
    std::cout << "destroy shared id this:" <<  this << " id:" << _id << " Moved:" << _moved << std::endl;
    _id = INVALID_ID;
}

SharedId& SharedId::operator=(SharedId&& move){
    RefcountDecrease();
    this->_id = std::move(move._id);
    this->_refcount = std::move(move._refcount);
    move._id = INVALID_ID;
    move._moved = true;
    std::cout << "Move assign shared this:" <<  this << " copy:" << &move << " id:" << _id << " count:" << RefCount() << std::endl;
    return *this;
}

SharedId& SharedId::operator=(SharedId& copy){
    this->_id = copy._id;
    this->_refcount = copy._refcount;
    RefcountIncrease();
    std::cout << "Copy assign shared this:" <<  this << " copy:" << &copy << " id:" << _id << " count:" << RefCount() << std::endl;
    return *this;
}

SharedId::operator int32_t(){
    return _id;
}

int SharedId::data(void){
    std::cout << "data shared"  << std::endl;
    return _id;
}

int SharedId::RefCount() {
    if (!this->_refcount)
        return -1;
    return *this->_refcount;
}

void SharedId::RefcountIncrease() {
    std::cout << "Refcount increase this:" << this << " refcount:" << RefCount() << std::endl;
    if (this->_refcount)
        this->_refcount->fetch_add(1);
}
void SharedId::RefcountDecrease() {
    std::cout << "Refcount decrease this:" << this << " refcount:" << RefCount() << std::endl;
    if (this->_refcount) {
        this->_refcount->fetch_sub(1);
        if (*this->_refcount == 0)
            Free();
    }
}

void SharedId::Free() {
    if (RefCount() == 0) {
        if (Typeof(_id) == OJECT_A_TYPE)
            FreeA(_id);
        else if (Typeof(_id) == OJECT_B_TYPE)
            FreeB(_id);
        else
            std::cout << fg::red << style::bold << "free shared id INVALID TYPE this:" << this << "id:" << _id << style::reset << std::endl;
    }
}