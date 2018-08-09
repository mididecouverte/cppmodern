#include <string>
#include <iostream>
#include <tuple>

using namespace std;

int main (int argc, char *argv[])
{
    /* Simple int string float tuple */
    std::tuple<int, std::string, float> myTuple (10, "test", 3.14);

    /* Access element of the tuple*/
    std::get<0>(myTuple) = 100;
    cout << "Value of first element: " << std::get<0>(myTuple) << endl;

    /* Using the std::make_tuple function */
    auto mkTuple = std::make_tuple ("test", 3.14, 10, 'y');

    /* Unpack the tuple */
    std::string mystring;
    float myfloat;
    int myint;
    char mychar;
    std::tie (mystring, myfloat, myint, mychar) = mkTuple;
    std::tie (std::ignore, std::ignore, myint, mychar) = mkTuple;

    /* Pair are nearly like tuple */
    std::pair <int,float> myPair (10, 3.14);

    /* Access element of the tuple*/
    std::get<0>(myPair) = 88;
    cout << "Value of first element: " << std::get<0>(myPair) << endl;
    cout << "Value of the second element: " << myPair.second << endl;

    /* Using the std::make_pair function */
    auto mkPair = std::make_pair (10,20);

    return 0;
}
