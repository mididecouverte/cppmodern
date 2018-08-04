#include <string>
#include <iostream>
#include <string>
#include <map>
#include <unordered_map>

using namespace std;

int main (int argc, char *argv[])
{
    /* Simple string int map */
    std::map<std::string, int> simpleMap;
    cout << "Size:" << simpleMap.size() << endl;

    /* Add a new element*/
    simpleMap["test"] = 88;

    /* iterator */
    for (auto i: simpleMap)
        cout << "Key:" << i.first << " Value:" << i.second << endl;

    /* Test if exist */
    cout << "Exist:" << simpleMap.count("test") << endl;
    cout << "Exist not:" << simpleMap.count("test2") << endl;

    /* Initializer */
    std::map<std::string, int> initMap = {{"test", 1}, {"test2", 2}};
    
    /* Simple string int unordered_map */
    std::unordered_map<std::string, int> unorderedMap;
    cout << "Size:" << unorderedMap.size() << endl;

    /* Add a new element*/
    unorderedMap["test"] = 88;
    return 0;
}
