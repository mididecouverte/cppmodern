#include <string>
#include <iostream>
#include <deque>

using namespace std;

int main (int argc, char *argv[])
{
    /* Simple int vector */
    deque<int> simpleDeque;
    cout << "Size:" << simpleDeque.size() << endl;

    /* Insertion */
    simpleDeque.push_back(88);
    cout << "Size:" << simpleDeque.size() << endl;
    simpleDeque.push_front(21);
    cout << "Size:" << simpleDeque.size() << endl;

    /* Access value */
    cout << "Value:" << simpleDeque[0] << endl;

    /* Pre allocated vector */
    deque<int> sizedDeque(10, 88);
    cout << "Size:" << sizedDeque.size() << endl;
    cout << "Value:" << sizedDeque[0] << endl;

    /* Vector static initializer */
    deque<int> initializedDeque = {1, 2, 3, 4};
    cout << "Size:" << initializedDeque.size() << endl;
    cout << "Value:" << initializedDeque[0] << endl;

    /* Delete operation */
    cout << "Size:" << initializedDeque.size() << endl;
    cout << "Value:" << initializedDeque[1] << endl;
    initializedDeque.erase(initializedDeque.begin()+1);
    cout << "Size:" << initializedDeque.size() << endl;
    cout << "Value:" << initializedDeque[1] << endl;

    /* For loop */
    for (auto i: initializedDeque)
        cout << i << endl;
    return 0;
}
