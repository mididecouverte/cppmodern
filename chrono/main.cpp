#include <chrono>
#include <iostream>

using namespace std;

void DoNothing(int loop)
{
    for (int i=0;i<loop;i++)
        cout << "Do nothing " << i << "\r";
    cout << std::endl;
}

int main (int argc, char *argv[])
{
    std::chrono::steady_clock::time_point start = std::chrono::steady_clock::now();
    DoNothing(100000);
    auto end = std::chrono::steady_clock::now();
    auto duration = end - start;
    std::cout << "Do nothing took "
              << std::chrono::duration_cast<std::chrono::microseconds>(duration).count()
              << "us." << std::endl
              << std::chrono::duration_cast<std::chrono::seconds>(duration).count()
              << "s" << std::endl;

    return 0;
}
