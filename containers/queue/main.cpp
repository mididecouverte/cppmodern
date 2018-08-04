#include <string>
#include <iostream>
#include <queue>

using namespace std;

int main (int argc, char *argv[])
{
    /* Simple int list */
    queue<int> simpleQueue;
    cout << "Size:" << simpleQueue.size() << endl;

    /* Insertion */
    simpleQueue.push(88);
    cout << "Size:" << simpleQueue.size() << endl;

    /* Access */
    cout << "Value:" << simpleQueue.front() << endl;
    simpleQueue.pop();
    cout << "Size:" << simpleQueue.size() << endl;

    return 0;
}
