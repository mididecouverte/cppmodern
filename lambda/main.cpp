#include <string>
#include <algorithm>
#include <iostream>
#include <memory>
#include <vector>

using namespace std;

int main (int argc, char *argv[])
{
    /* Simple lambda function */
    std::string myString = "test";
    auto glambda = [=](auto a, auto&& b) mutable { myString = "toto";cout<< myString <<endl; return a < b; };
    bool b = glambda(3, 3.14);
    cout << "lambda return:" << b << endl;
    cout<< myString <<endl;

    /* c++ 14 capture */
    vector<int> nums = {1, 2, 3, 4, 5};
    auto pNums = make_unique<vector<int>>(nums);

    auto a = [ptr = move(pNums)] {
        for (auto b: *ptr)
            cout << b << endl;
    };
    a();

    /* Real example */
    int scale = 12;
    vector<int> numsVector = {1, 2, 3, 4, 5};
    for_each(numsVector.begin(), numsVector.end(),
      [=](int n) { cout << n * scale << endl; });

    return 0;
}
