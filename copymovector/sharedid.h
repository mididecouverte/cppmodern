#ifndef SHAREDID
#define SHAREDID

#include <atomic>
#include <cstdint>
#include "ids.h"
#include <memory>

class SharedId
{
public:
    SharedId(int32_t id);
    SharedId(const SharedId& copy);
    SharedId(SharedId&& move);
    ~SharedId();
    SharedId& operator=(SharedId& copy);
    SharedId& operator=(SharedId&& move);
    operator int32_t();
    int data(void);

private:
    int RefCount();
    void RefcountIncrease();
    void RefcountDecrease();
    void Free();

private:
    int _id = INVALID_ID;
    std::shared_ptr<std::atomic<int>> _refcount = std::make_shared<std::atomic<int>>(0);
    bool _moved = false;
};

#endif