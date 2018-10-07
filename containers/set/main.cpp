#include <string>
#include <iostream>
#include <set>

using namespace std;

int main (int argc, char *argv[])
{
    /* Simple int set */
    set<int> simpleSet;
    cout << "Size:" << simpleSet.size() << endl;

    /* Insertion */
    simpleSet.insert(88);
    cout << "Size:" << simpleSet.size() << endl;

    /* Cannot add the same value 2 times*/
    simpleSet.insert(88);
    cout << "Size:" << simpleSet.size() << endl;

    /* Vector static initializer */
    set<int> initializedSet = {1, 2, 3, 4};
    cout << "Size:" << initializedSet.size() << endl;

    /* Delete operation */
    cout << "Size:" << initializedSet.size() << endl;
    initializedSet.erase(2);
    cout << "Size:" << initializedSet.size() << endl;

    /* Test if value in set */
    cout << "Count:" << initializedSet.count(4) << endl;

    /* For loop */
    for (auto i: simpleSet)
        cout << i << endl;
    return 0;
}
