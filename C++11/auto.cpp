#include <iostream>
#include <list>
#include <cmath>
#include <algorithm>
#include <vector>
#include <ctime>

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

void PriVector(const std::vector<int> myVector){
    for(auto &x : myVector){
        std::cout << x << " ";
    }
    std::cout << std::endl;
}

bool f3(int x) {return (x % 3 == 0);}
bool f13(int x) {return (x % 13 == 0);}

class NumMod{
    public:
        NumMod(int x) : modNum(x){

        }
    bool operator() (int x){
        return (x % modNum == 0);
    }
    private:
        int modNum;
};
//Lambda expression
void Test6(){
    std::srand(unsigned(std::time(0)));
    std::vector<int> myVector(50, 0);
    std::generate(myVector.begin(), myVector.end(), std::rand);
    PriVector(myVector);

    int count3 = std::count_if(myVector.begin(), myVector.end(), f3);
    std::cout << "count of numbers divisible by 3 : " << count3 << std::endl;
    int count13 = std::count_if(myVector.begin(), myVector.end(), f13);
    std::cout <<  "count of numbers divisible by 13 : " << count13 << std::endl;

    count3 = std::count_if(myVector.begin(), myVector.end(), NumMod(3));
    std::cout << "count of numbers divisible by 3 : " << count3 << std::endl;
    count13 = std::count_if(myVector.begin(), myVector.end(), NumMod(13));
    std::cout <<  "count of numbers divisible by 13 : " << count13 << std::endl;

    //use Lambda expression
    count3 = std::count_if(myVector.begin(), myVector.end(), [](int x){return (x %3 == 0);});
    std::cout << "count of numbers divisible by 3 : " << count3 << std::endl;
    count13 = std::count_if(myVector.begin(), myVector.end(), [](int x){return (x %13 == 0);});
    std::cout <<  "count of numbers divisible by 13 : " << count13 << std::endl;
}

//Lambda expression
void Test7(){
    const int maxNum = 1000;
    std::srand(unsigned(std::time(0)));
    std::vector<int> myVector(maxNum, 0);
    std::generate(myVector.begin(), myVector.end(), std::rand);

    int count3 = 0;
    int count13 = 0;

    std::for_each(myVector.begin(), myVector.end(), [&](int x) {
        if(0 == (x % 3)){
            count3++;
        }
        else if(0 == (x % 13)){
            count13++;
        }
    });

    std::cout << "count of numbers divisible by 3 : " << count3 << std::endl;
    std::cout << "count of numbers divisible by 13 : " << count13 << std::endl;

}

//Lambda expression
void Test8(){
    int sumNum = 0;
    //function pointer
    auto lam = [](){
        std::cout << "good news" << std::endl;
    };
    std::cout << "sizeof(lam): " << sizeof(lam) << std::endl; 
    lam();
}

int main(){
//    Test();
//    Test1();
//    Test2();
//    Test3();
//    Test4();
//    Test5();
//    Test6();
//    Test7();
    Test8();
    return 0;
}