#ifndef UNIQUEID
#define UNIQUEID

#include <cstdint>
#include "ids.h"

class UniqueId
{
public:
    UniqueId(int32_t id);
    UniqueId(UniqueId&& move);
    ~UniqueId();
    UniqueId& operator=(UniqueId&& move);
    operator int32_t();
    int data(void);

private:
    UniqueId(const UniqueId& copy);

private:
    int _id = INVALID_ID;
};

#endif