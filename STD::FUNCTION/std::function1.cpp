#include <functional>
#include <numeric>
#include <algorithm>
#include <stdlib.h>
#include <iostream>

typedef int(*fPtr) (int, int);

// int Func(const int a, const int b, fPtr f1){
//     if(nullptr == f1){
//         fprintf(stderr, "f1 is null.\n");
//     }
//     return f1(a, b);
// }

int Func(const int a, const int b, std::function<int(int, int)> f1){
    if(nullptr == f1){
        fprintf(stderr, "f1 is null.\n");
    }
    return f1(a, b);
}

int add(const int a, const int b){
    return a + b;
}

struct fStruct{
    int operator() (const int a, const int b){
        return a + b;
    }
};

int main(){
//    int sum = Func(1, 2, add);
//    int sum = Func(1, 2, fStruct());  //error no suitable conversion function from "fStruct" to "fPtr" existsC/C++(413)
//    std::function<int(int, int)> f1 = add;
    std::function<int(int, int)> f1 = fStruct();
    int sum = Func(1, 2, f1);
    std::cout << "sum is " << sum << std::endl;
}