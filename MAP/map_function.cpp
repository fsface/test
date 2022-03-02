#include <iostream>
#include <map>

void Pri_Map(std::map<char, int> myMap)
{
    for(auto it = myMap.begin(); it != myMap.end(); it++)
    {
        std::cout << it->first << " : " << it->second << std::endl;
    }
}

void Map_Find()
{
    std::map<char, int> myMap;
    std::map<char, int>::iterator it;

    myMap['a']=50;
    myMap['b']=100;
    myMap['c']=150;
    myMap['d']=200;

    it = myMap.find('h');
    if(it != myMap.end())
    {
        std::cout << "contain" << "\n";
    }
    else
    {
        std::cout << "not contain" << "\n";
    }
}

void Map_Erase()
{
    std::map<char, int> myMap;
    std::map<char, int>::iterator it;
    //insert some values;
    myMap['a'] = 10;
    myMap['b'] = 20;
    myMap['c'] = 30;
    myMap['d'] = 40;
    myMap['e'] = 50;
    myMap['f'] = 60;
    it = myMap.find('c');
    myMap.erase(it); //erasing by iterator
    myMap.erase('c'); //erasing by key
    Pri_Map(myMap);
    it = myMap.find('e');
    myMap.erase(it, myMap.end()); //erase by range
    std::cout << "*****************" << "\n";
    Pri_Map(myMap);
}

void Map_At()
{
    std::map<std::string, int> myMap = {{"alpha", 0}, {"beta", 0}, {"gamma", 0}};
    myMap.at("alpha") = 10;
    myMap.at("beta") = 20;
    myMap.at("gamma") = 30;
    for(auto& x: myMap)
    {
        std::cout << x.first << ": " << x.second << "\n";
    }
}

void Map_Lower_Bound()
{
    std::map<char,int> mymap;
    std::map<char,int>::iterator itlow,itup;

    mymap['a']=20;
    mymap['b']=40;
    mymap['c']=60;
    mymap['d']=80;
    mymap['e']=100;

    itlow=mymap.lower_bound ('b');  // itlow points to b
    itup=mymap.upper_bound ('d');   // itup points to e (not d!)

    mymap.erase(itlow,itup);        // erases [itlow,itup)

    // print content:
    for (std::map<char,int>::iterator it=mymap.begin(); it!=mymap.end(); ++it)
        std::cout << it->first << " => " << it->second << '\n';
}

int main()
{
//    Map_Find();
//    Map_At();
//    Map_Erase();
    Map_Lower_Bound();
    return 0;
}