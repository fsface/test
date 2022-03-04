#include <functional>
#include <numeric>
#include <algorithm>
#include <stdlib.h>
#include <iostream>
#include <assert.h>
#include <exception>

int main(){
    std::function<int(int)> f(nullptr); //explicit construct a null std::function ptr
    try{
        f(10);
    }catch(const std::bad_function_call& e){
        std::cout << e.what() << "\n";
    }
    return 0;
}