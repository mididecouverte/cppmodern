#include <string>
#include <iostream>
#include <stack>

using namespace std;

int main (int argc, char *argv[])
{
    /* Simple int list */
    stack<int> simpleStack;
    cout << "Size:" << simpleStack.size() << endl;

    /* Insertion */
    simpleStack.push(1);
    simpleStack.push(2);
    cout << "Size:" << simpleStack.size() << endl;

    /* Access */
    cout << "Value:" << simpleStack.top() << endl;
    simpleStack.pop();
    cout << "Size:" << simpleStack.size() << endl;

    return 0;
}
