#include <iostream>
#include <thread>
#include <chrono>

void pri(){
    while(1){
        std::cout << " son thread " << std::endl;
        std::this_thread::sleep_for(std::chrono::milliseconds(1000));
    }
}


int main(){
    std::cout << "main  thread start" << std::endl;
    std::thread sonthread(pri);
    std::this_thread::sleep_for(std::chrono::milliseconds(1000));
    sonthread.detach();
    std::cout << "main thread stop " << std::endl;
    return 0;
}