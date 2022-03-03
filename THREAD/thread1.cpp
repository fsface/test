#include <iostream>
#include <thread>
#include <chrono>

void pri(){
    std::cout << "i am son thread " << std::endl;
    std::this_thread::sleep_for(std::chrono::milliseconds(1000));
    std::cout << "i am son thread " << std::endl;
    std::this_thread::sleep_for(std::chrono::milliseconds(1000));
}

class cPri{
    public:
        void operator() (){
            std::cout << "cPri i am son thread" << std::endl;
            std::this_thread::sleep_for(std::chrono::milliseconds(1000));
            std::cout << "cPri i am son thread" << std::endl;
            std::this_thread::sleep_for(std::chrono::milliseconds(1000));
        }
};
//use function create thread
void test(){
    std::cout << "i am main thread " << std::endl;
    std::thread son(pri); // run son thread
//    son.join(); //block main thread until son thread completed;
    if(son.joinable()){
        std::cout << "son is joinable " << std::endl;
    }
    else{
        std::cout << "son is not joinable " << std::endl;
    }

    son.detach();

    if(son.joinable()){
        std::cout << "son is joinable " << std::endl;
    }
    else{
        std::cout << "son is not joinable " << std::endl;
    }

    //son.join(); you can't call join() after call detach()  
}
//use class create thread
void test1(){
    cPri cpri;
    std::cout << "i am main thread " << std::endl;
    std::thread son(cpri);
    son.join();
}
// use lambda expression create thread
void test2(){
    auto lPri = [](){
        std::cout << "lPri i am son thread" << std::endl;
        std::this_thread::sleep_for(std::chrono::milliseconds(1000));
        std::cout << "lPri i am son thread" << std::endl;
        std::this_thread::sleep_for(std::chrono::milliseconds(1000));
    };
    std::cout << "i am main thread " << std::endl;
    std::thread son(lPri);
    son.join();
}

int main(){
//    test();
//    test1();
    test2();
    return 0;
}