#include <string>
#include <vector>
#include <iostream>

using namespace std;

int main (int argc, char *argv[])
{
    vector<int> initializedVector = {1, 2, 3, 4};

    /* For loop */
    for (auto& i: initializedVector)
        cout << i << endl;

    /* Using initializer list */
    for (const int& n : {0, 1, 2, 3, 4, 5}) // the initializer may be a braced-init-list
        std::cout << n << ' ';
    std::cout << std::endl;

    /* Using array initialized with initializer list */
    int a[] = {0, 1, 2, 3, 4, 5};
    for (int& n : a)
        std::cout << n << ' ';
    std::cout << '\n';

    return 0;
}
