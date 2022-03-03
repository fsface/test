#include <iostream>
#include <thread>
#include <chrono>
#include <vector>
#include <mutex>


#define ADD_NUM 1000000
#define THREAD_NUM 10

int number = 0;
std::mutex myMutex;
std::timed_mutex myTimeMutex;


void add(){
    for(int count = 0; count < ADD_NUM; count++){
        myMutex.lock();
//       myMutex.try_lock();  use try_lock() case problems
        number++;
        myMutex.unlock();
    }
}

void add1(){
    for(int count = 0; count < ADD_NUM; count++){
        myTimeMutex.try_lock_for(std::chrono::milliseconds(1));
        number++;
        myTimeMutex.unlock();
    }
}

int main(){
    std::vector<std::thread> myVector;
    for(int count = 0; count < THREAD_NUM; count++){
//        myVector.push_back(std::thread(add));
        myVector.push_back(std::thread(add1));
    }

    for(auto &x : myVector){
        x.join();
    }

    std::cout << "number: "<< number << "\n";
    return 0;
}