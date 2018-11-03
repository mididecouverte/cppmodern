#include <algorithm>
#include <cstdint>
#include "ids.h"
#include <iostream>
#include "rang.hpp"
#include <string>
#include <vector>

using namespace rang;

std::vector<Id> _ids;

int32_t Alloc(std::string type){
    int32_t id = _ids.size()+1;
    _ids.push_back({type, id});
    return id;
}

bool Exist(int32_t id) {
    auto find = std::find_if( _ids.begin(), _ids.end(),
        [&id](const Id& x) { return x.id == id;});
    return find != _ids.end();
}

Id& Find(int32_t id){
    auto find = std::find_if( _ids.begin(), _ids.end(),
        [&id](const Id& x) { return x.id == id;});
    return *find;
}

std::string Typeof(int32_t id){
    if (!Exist(id))
        return "";
    auto idobj = Find(id);
    return idobj.type;
}

void Use(int id){
    if (Exist(id))
        std::cout << "Using buffer id:" << id << std::endl;
    else
        std::cout << fg::red << style::bold << "Using INVALID buffer id:" << id << style::reset << std::endl;
}

void Free(int32_t id){
    auto find = std::find_if( _ids.begin(), _ids.end(),
        [&id](const Id& x) { return x.id == id;});
    _ids.erase(find);
}

int AllocA(){
    int32_t id = Alloc(OJECT_A_TYPE);
    std::cout << fg::yellow  << "Allocating A id:" << id << fg::reset << std::endl;
    return id;
};

void FreeA(int id){
    if (Exist(id)){
        if (Typeof(id) == OJECT_A_TYPE) {
            std::cout << fg::yellow  << "Free A id:" << id << fg::reset << std::endl;
            Free(id);
        }
        else {
            std::cout << fg::red << style::bold << "Free INVALID TYPE A id:" << id << style::reset << std::endl;
        }
    }
    else{
        std::cout << fg::red << style::bold << "Free INVALID A id:" << id << style::reset << std::endl;
    }
};

int AllocB(){
    int32_t id = Alloc(OJECT_B_TYPE);
    std::cout << fg::yellow << "Allocating B id:" << id << fg::reset << std::endl;
    return id;
};

void FreeB(int id){
    if (Exist(id)){
        if (Typeof(id) == OJECT_B_TYPE) {
            std::cout << fg::yellow  << "Free B id:" << id << fg::reset << std::endl;
            Free(id);
        }
        else {
            std::cout << fg::red << style::bold << "Free INVALID TYPE B id:" << id << style::reset << std::endl;
        }
    }
    else{
        std::cout << fg::red << style::bold << "Free INVALID B id:" << id << style::reset << std::endl;
    }
};