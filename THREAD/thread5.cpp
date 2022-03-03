#include <iostream>
#include <thread>
#include <chrono>
#include <vector>

#define THREAD_NUM 80
#define PRI_NUM 20

void pri(int i){
    std::cout << "thread id is " << std::this_thread::get_id() << std::endl;
    // for(int count = 0; count < PRI_NUM; count++){
    //     std::cout << "thread of " << i << "start ===" << std::endl;
    // }
    // for(int count = 0; count < PRI_NUM; count++){
    //     std::cout << "thread of " << i << "stop ===" << std::endl;
    // }

    
}

int main(){
    std::vector<std::thread> thVector;
    for(int count = 0; count < THREAD_NUM; count++){
        thVector.push_back(std::thread(pri, count));
    }

    for(auto &x : thVector){
        x.join();
    }
    std::cout << "end of the main thread\n";
    return 0;
}