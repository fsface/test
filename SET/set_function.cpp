#include <iostream>
#include <set>

void Set_Key_Comp()
{
    std::set<int> s1;
    s1.insert(10);
    s1.insert(12);
    s1.insert(13);
    s1.insert(9);

    std::cout << s1.key_comp()(1, 2) << std::endl; //default is less object
}

int main()
{
    Set_Key_Comp();
    return 0;
}