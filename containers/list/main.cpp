#include <string>
#include <iostream>
#include <list>

using namespace std;

int main (int argc, char *argv[])
{
    /* Simple int list */
    list<int> simpleList;
    cout << "Size:" << simpleList.size() << endl;

    /* Insertion */
    simpleList.push_back(88);
    cout << "Size:" << simpleList.size() << endl;

    /* Vector static initializer */
    list<int> initializedList = {1, 2, 3, 4};
    cout << "Size:" << initializedList.size() << endl;

    /* Access */
    cout << "Value:" << initializedList.front() << endl;

    /* Delete operation */
    cout << "Size:" << initializedList.size() << endl;
    auto begin = initializedList.begin();
    advance(begin, 1);
    initializedList.erase(begin);
    cout << "Size:" << initializedList.size() << endl;

    /* For loop */
    for (auto i: initializedList)
        cout << i << endl;
    return 0;
}
