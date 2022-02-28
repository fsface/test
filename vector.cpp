#include <iostream>
#include <vector>

int main()
{
    // default constructor; fill constructor; range constructor; copy constructor
    std::vector<int> first;
    std::vector<int> second(4, 100);
    std::vector<int> third(second.begin(), second.end());
    std::vector<int> fourth(third);
    //the iterator constructor can also be used to construct from arrays
    int myints[] = {16, 2, 77, 29};
    std::vector<int> fifth(myints, myints + sizeof(myints)/sizeof(int));
    for(std::vector<int>::iterator it = fifth.begin(); it != fifth.end(); ++it)
    {
        std::cout << " " << *it;
    }
    std::cout << "\n";
    return 0;
}