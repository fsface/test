//unordered_map begin/end example
#include <iostream>
#include <unordered_map>

int main()
{
    std::unordered_map<std::string, std::string> mymap;
    mymap = {{"Australia", "Canberra"}, {"US", "Washington"}, {"France", "Paris"}};
    std::cout << "mymap contains";
    for(auto it = mymap.begin(); it != mymap.end(); ++it)
    {
        std::cout << " " << it->first << ":" << it->second;
    }
    std::cout << std::endl;
}