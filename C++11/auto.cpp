#include <iostream>
#include <list>
#include <math.h>

void Test(){
    std::list<int> mylist;
    mylist.push_back(1);
    mylist.push_back(2);
    mylist.push_back(3);

    for(auto it = mylist.begin(); it != mylist.end(); it++){
        std::cout << *it << std::endl;
    }
}

template<typename T, typename U>
void Pri(T a, U b){
    decltype (a*b) c;
    std::cout << "sizeof(c) is " << sizeof(c) << std::endl;
}

void Test1(){
    double x;
    int n;
    decltype (x*n) q; //q same type as x*n double
    decltype (&x) pd; //pd same as &x, double *

    int a = 10, b = 20;
    double c = 20.0;
    Pri(a, c);
}

void Test2(){
    int *ptr = nullptr; //c++11 recommand using nullptr instead NULL
    std::cout << ptr << std::endl;
}

void Test3(){
    double myArray[] = {1.1, 1.2, 1.3, 1.4, 1.5};
    for(double x:myArray){
        std::cout << x << std::endl;
    }

    //using auto for safe

    std::cout << "*********************" << std::endl;

    for(auto x:myArray){
        std::cout << x << std::endl;
    }
    //using reference to modify the value

    for(auto &x:myArray){
        x = 6.6;
    }

    std::cout << "*********************" << std::endl;

    for(auto x:myArray){
        std::cout << x << std::endl;
    }
    std::cout << "*********************" << std::endl;
    std::list<int> mylist;
    mylist.push_back(1);
    mylist.push_back(2);
    mylist.push_back(3);
    mylist.push_back(4);

    for(auto x:mylist){
        std::cout << x << std::endl;
    }

}
//right reference
void Test4(){
    int x = 10;
    int y = 20;
    int &&r1 = 30;
    r1 = 20;
    std::cout << r1 << std::endl;
    int &&r2 = x + y;
    std::cout << "r2 is " << r2 << std::endl;
    double &&r3 = std::sqrt(2.0);
    std::cout << "r3 is " << r3 << std::endl;
}

inline double f(double tf) {return 5.0*(tf - 32)/ 9.0;};

void Test5(){
    double tc = 21.5;
    double &&rd1 = 7.07;
    double &&rd2 = 1.8 * tc + 32.0;
    double &&rd3 = f(rd2);
    std::cout << "tc value is " << tc << " " << "tc address is " << &tc << std::endl;
    std::cout << "rd1 value is " << rd1 << " " << "rd1 address is " << &rd1 << std::endl;
    std::cout << "rd2 value is " << rd2 << " " << "rd2 address is " << &rd2 << std::endl;
    std::cout << "rd3 value is " << rd3 << " " << "rd3 address is " << &rd3 << std::endl; 
}

int main(){
//    Test();
//    Test1();
//    Test2();
//    Test3();
//    Test4();
    Test5();
    return 0;
}