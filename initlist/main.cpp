#include <string>
#include <vector>
#include <initializer_list>
#include <iostream>
#include <iterator>

using namespace std;

class DemoClass {
public:
    DemoClass(std::initializer_list<std::string> l) : _data(l) {
         std::cout << "constructed with a " << l.size() << "-element list\n";
    }
    void append(std::initializer_list<std::string> l) {
        _data.insert(_data.end(), l.begin(), l.end());
    }
    vector<std::string>::iterator begin() { return _data.begin(); }
    vector<std::string>::iterator end() { return _data.end(); }
private:
    std::vector<std::string> _data;
};

int main (int argc, char *argv[])
{
    DemoClass myClass = {"test", "test2"};
    myClass.append({"more test", "test 5" , "test 7"});

    for (auto v : myClass)
        cout << v << endl;
    return 0;
}
