#ifndef IDS
#define IDS

#include <cstdint>
#include <iostream>
#include <string>
#include <vector>

const static std::string OJECT_A_TYPE = "A";
const static std::string OJECT_B_TYPE = "B";
const static int32_t INVALID_ID = 0;

class Id {
public:
    Id(std::string type, int32_t id){
        this->type = type;
        this->id = id;
        std::cout << "Id Constructor type:" << type << " id:" << id << std::endl;
    }
    ~Id() {
        std::cout << "Id Destructor type:" << type << " id:" << id << std::endl;
        this->type = "";
        this->id = INVALID_ID;
    }

    std::string type;
    int32_t id = INVALID_ID;
};

int32_t Alloc(std::string type);
bool Exist(int32_t id);
Id& Find(int32_t id);
std::string Typeof(int32_t id);
void Use(int id);
void Free(int32_t id);

int AllocA();
void FreeA(int id);

int AllocB();
void FreeB(int id);

#endif