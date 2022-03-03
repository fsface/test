/*
version : gcc version 7.5.0 (Ubuntu 7.5.0-3ubuntu1~18.04)
command : g++ thread3.cpp -lpthread
*/

#include <iostream>
#include <thread>
#include <chrono>

void func(int &num){
    std::cout << "enter func thread \n"; 
    num = 20;
    std::cout << "exit func thread \n";
}

int main(){
    std::cout << "enter main thread \n";
    int num = 10;
//    std::thread sonthread(func, num);  //error;
    std::thread sonthread(func, std::ref(num));
    sonthread.join();
    std::cout << "num: " << num << "\n";
    std::cout << "exit main thread \n";
    return 0;
}