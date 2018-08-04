#include <string>
#include <iostream>
#include <array>

using namespace std;

int main (int argc, char *argv[])
{
    /* Simple int array */
    std::array<int, 10> simpleArray;
    cout << "Size:" << simpleArray.size() << endl;

    /* Access value */
    cout << "Value:" << simpleArray[0] << endl;

    /* fill */
    simpleArray.fill(10);
    cout << "Size:" << simpleArray.size() << endl;
    cout << "Value:" << simpleArray[0] << endl;

    /* Initialized array */
    std::array<int, 10> initArray = {1, 2, 3, 4};

    /* For loop */
    for (auto i: initArray)
        cout << i << endl;
    return 0;
}
