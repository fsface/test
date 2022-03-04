#include <iostream>
#include <assert.h>
#include <cstring>


// assert when run
int myDiv(int a, int b){
    assert(0 != b);
    return a / b;
}


//assert when compile
template<typename T, typename U> int bit_copy(T &a, U &b){
    static_assert(sizeof(T) == sizeof(U), "template parameter size no equall!");
    memccpy(&a, &b, 1,sizeof(T));
}

void test(){
    int a = 10;
    int b = 5;
    int c = myDiv(a, b);
    std::cout << "c: " << c << "\n";
}

void test1(){
    int a = 10;
    double b;
    bit_copy(a, b);
}

int main(){
//    test();
    test1();
}