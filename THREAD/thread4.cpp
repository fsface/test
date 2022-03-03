#include <iostream>
#include <thread>
#include <chrono>

class Func{
    public:
        Func():them(0){
            std::cout << "no argument constructor " << std::endl;
        }

        Func(int m):them(m){
            std::cout << "argument constructor\n";
        }

        Func(const Func& other):them(other.them){
            std::cout << "copy constructor\n";
        }

        ~Func(){
            std::cout << "deconstructor\n";
        }

        void show() const{
            std::cout << "them is: " << them << "\n";
        }
    private:
        int them;
};

void myfunc(Func &func){
    func.show();
}

int main(){
    std::cout << "enter main thread \n";
    Func func1(100);
    std::thread sonthread(myfunc, func1);
    sonthread.join();
    std::cout << "exit main thread \n";
}