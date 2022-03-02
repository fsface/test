//constructing maps
#include <iostream>
#include <map>

void Pri_Map(std::map<char, int> myMap)
{
    for(std::map<char, int>::iterator it = myMap.begin(); it != myMap.end(); it++)
    {
        std::cout << it->first << " " << it->second << "\n";
    }
}

struct classcomp{
    bool operator() (const char &lhs, const char &rhs) const
    {
        return (lhs > rhs);
    }
};

bool fncomp(char lhs, char rhs)
{
    return (lhs < rhs);
}

int main()
{
    std::map<char, int> first;
    first['a'] = 10;
    first['b'] = 30;
    first['c'] = 50;
    first['d'] = 70;

    std::map<char, int> second(first.begin(), first.end()); //range constructor
    Pri_Map(second);
    std::map<char, int> third(second); //copy constructor
    std::cout << "***************" << "\n";
    Pri_Map(third);
    std::cout << "***************" << "\n";
    std::map<char, int, classcomp> fourth;  //class as Compare
    fourth['a'] = 10;
    fourth['b'] = 80;
    fourth['c'] = 30;
    fourth['d'] = 40;
    for(auto it = fourth.begin(); it != fourth.end(); it++)
    {
        std::cout << it->first << " " << it->second << "\n";
    }
    std::cout << "***************" << "\n";
    bool (*fn_pt) (char, char) = fncomp;
    std::map<char, int, bool(*)(char, char)> fifth(fn_pt);
    fifth['a'] = 10;
    fifth['b'] = 80;
    fifth['c'] = 30;
    fifth['d'] = 40;
    for(auto it = fifth.begin(); it != fifth.end(); it++)
    {
        std::cout << it->first << " " << it->second << "\n";
    }
    return 0;
}