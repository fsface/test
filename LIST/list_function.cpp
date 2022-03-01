//list sort
#include <iostream>
#include <list>

void PriList(std::list<int> mylist)
{
    for(std::list<int >::iterator it = mylist.begin(); it != mylist.end(); ++it)
    {
        std::cout << *it << " ";
    }
    std::cout << "\n";
}

bool MyCompare(int first, int second)
{
    return (first < second);
}

void List_Sort()
{
    std::list<int> first = {3, 5, 1, 2 ,8};
    PriList(first);
//    first.sort();
    first.sort(MyCompare);
    PriList(first);
}

void List_Cbegin()
{
    //function begin return iterator can be used to change the value
    std::list<int> first = {5, 2, 1, 4, 5};
    PriList(first);
    std::list<int>::iterator it = first.begin();
    *it = 10;
    PriList(first);
    std::list<int>::const_iterator it1 = first.cbegin();
//    *it1 = 20; error the iterator points value can not be changed
    it1++; //iterator itself can be changed
    std::cout << "*it1 " << *it1 << " " << "\n";
}

void List_Assign()
{
    std::list<int> first;
    std::list<int> second;
    //fill function
    first.assign(3, 100);
    PriList(first);
    // range function
    second.assign(first.begin(), first.end());
    PriList(second);
    // note
    int myints[] = {1, 2, 3};
    second.assign(myints, myints + 3);
    PriList(second);
}

int main()
{
//    List_Sort();
//    List_Cbegin();
    List_Assign();
    return 0;
}