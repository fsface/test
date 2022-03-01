//vector emplace
#include <iostream>
#include <vector>

void Emplace_Feathure()
{
    struct Foo{
        Foo(int n, double x)
        {
            net = n;
            xValue = x;
        }
        int net;
        double xValue;
    };

    std::vector<Foo> fooVector;
    fooVector.emplace_back(2, 2.2); //
    fooVector.emplace_back(3, 3.3); //
    fooVector.insert(fooVector.end(),Foo(4, 4.4));
    for(std::vector<Foo>::iterator it = fooVector.begin(); it != fooVector.end(); ++it)
    {
        std::cout << (*it).net << " " << (*it).xValue << "\n";
    }
    std::cout << "\n";

}

void Test()
{
    std::vector<int> myvector = {10, 20, 30};
    auto it = myvector.emplace(myvector.begin() + 1, 100);
    myvector.emplace(it, 200);
    myvector.emplace(myvector.end(), 300);
    std::cout << "myvector contains ";
    for(auto& x:myvector)
    {
        std::cout << ' ' << x;
    }
    std::cout << "\n";
}

void Vector_Capacity()
{
    std::vector<int> myvector;
    for(int i = 0; i < 100; i++)
    {
        myvector.push_back(i);
    }
    std::cout << "size: " << (int)myvector.size() << "\n";
    std::cout << "capacity:" << (int)myvector.capacity() << "\n";
    std::cout << "max_size: " << (unsigned int)myvector.max_size() << "\n";
}

int main()
{
//    Emplace_Feathure();
    Vector_Capacity();
    return 0;
}