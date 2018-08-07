#include <string>
#include <iostream>
#include <vector>

using namespace std;

int main (int argc, char *argv[])
{
    /* Simple int vector */
    vector<int> simpleVector;
    cout << "Size:" << simpleVector.size() << endl;

    /* Insertion */
    simpleVector.push_back(88);
    cout << "Size:" << simpleVector.size() << endl;

    /* Access value */
    cout << "Value:" << simpleVector[0] << endl;

    /* Pre allocated vector */
    vector<int> sizedVector(10, 88);
    cout << "Size:" << sizedVector.size() << endl;
    cout << "Value:" << sizedVector[0] << endl;

    /* Vector static initializer */
    vector<int> initializedVector = {1, 2, 3, 4};
    cout << "Size:" << initializedVector.size() << endl;
    cout << "Value:" << initializedVector[0] << endl;

    /* Delete operation */
    cout << "Size:" << initializedVector.size() << endl;
    cout << "Value:" << initializedVector[1] << endl;
    initializedVector.erase(initializedVector.begin()+1);
    cout << "Size:" << initializedVector.size() << endl;
    cout << "Value:" << initializedVector[1] << endl;

    /* For loop */
    for (auto i: initializedVector)
        cout << i << endl;
    return 0;
}
