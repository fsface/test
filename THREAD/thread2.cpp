#include <iostream>
#include <thread>
#include <chrono>

class Ta{
    public:
        Ta():i(0){
            std::cout << "no argument constructor" << std::endl;
        }
        Ta(int m):i(m){
            std::cout << "argument constructor " << std::endl;
        }
        Ta(const Ta &tb):i(tb.i){
            std::cout << "copy constructor " << std::endl;
        }
        ~Ta(){
            std::cout << " deconstructor " << std::endl;
        }
        void operator() (){
            std::cout << "Ta son thread 1" << std::endl;
            std::cout << "Ta son thread 2" << std::endl;
            std::cout << "Ta son thread 3" << std::endl;
            std::cout << "Ta son thread 4" << std::endl;
            std::cout << "Ta son thread 5" << std::endl;
            std::cout << "Ta son thread 7" << std::endl;
            std::cout << "Ta son thread 8" << std::endl;
            std::cout << "Ta son thread 9" << std::endl;
            std::cout << "Ta son thread 10" << std::endl;
        }
    private:
        int i;
};


int main(){
    Ta ta;
    std::cout << "i am the main thread " << std::endl;
    std::thread sonthread(ta);  //note : call copy constructor 
    std::cout << "heihei" << "\n";
    sonthread.detach();
    std::cout << "end of main thread " << std::endl;
}