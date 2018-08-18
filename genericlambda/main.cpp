#include <string>
#include <iostream>

using namespace std;

int main (int argc, char *argv[])
{
    /* Generic lambda function */
    auto glambda = [=](auto a, auto&& b) mutable { return a < b; };
    bool b = glambda(std::string("test"), std::string("astring"));
    cout << "lambda string return:" << b << endl;
    b = glambda(5, 2);
    cout << "lambda int return:" << b << endl;

    return 0;
}
