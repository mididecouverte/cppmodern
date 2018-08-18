#include <algorithm>
#include <string>
#include <iostream>
#include <thread>
#include <future>

using namespace std;

double my_divide (double x, double y)
{
    auto result = x/y;
    std::cout << result << std::endl;
    return result;
}

void promised_int (std::future<int>& fut)
{
    int x = fut.get();
    std::cout << "value: " << x << std::endl;
}

void ThreadExample()
{
    /* A simple thread */
    std::thread th(my_divide, 60, 3);
    th.join();
}

void FutureExample()
{
    /* Simple example of a future*/
    auto fut = std::async(my_divide, 60, 3);
    std::cout << "future:" << fut.get() << std::endl;
}

void PromiseExample()
{
    /* Example of promise */
    std::promise<int> prom;
    std::future<int> promFut = prom.get_future();
    std::thread promThread (promised_int, std::ref(promFut));
    prom.set_value (10);
    promThread.join();
}

void PackagedTaskExample()
{
    /* packaged_task example */
    std::packaged_task<double(double,double)> tsk (my_divide);
    std::future<double> ret = tsk.get_future();
    std::thread asycMyDivide (std::move(tsk),10,2);
    double value = ret.get();
    std::cout << "my_divide(10,2) " << value << std::endl;
    asycMyDivide.join();
}

int main (int argc, char *argv[])
{
    ThreadExample();
    FutureExample();
    PromiseExample();
    PackagedTaskExample();
    return 0;
}
