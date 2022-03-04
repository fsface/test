#include <functional>
#include <numeric>
#include <algorithm>
#include <stdlib.h>
#include <iostream>
#include <assert.h>

int add(int a, int b){
    return a + b;
}

struct Sub{
    int operator() (int a, int b){
        return a - b;
    }
};

class Div{
    public:
        static int div(const int a, const int b){
            assert(b);
            return a/b;
        }
};

auto Lam = [](int a, int b){return a * b;};

int main(){
    int a = 4, b = 2;
    std::function<int(int, int)> f1 = add;
    std::cout << "add: " << f1(a, b) << "\n";
    f1 = Sub();
    std::cout << "sub: " << f1(a, b) << "\n";
    f1 = Lam;
    std::cout << "Lam: " << f1(a, b) << "\n";
    f1 = Div::div;
    std::cout << "div: " << f1(a, b) << "\n";
    return 0;
}