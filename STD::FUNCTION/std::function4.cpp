#include <functional>
#include <numeric>
#include <algorithm>
#include <stdlib.h>
#include <iostream>
#include <assert.h>
#include <exception>

class CAdd{
    public:
        CAdd():m_nSum(0){}
        int operator() (int i){
            m_nSum += i;
            return m_nSum;
        }

        int Sum() const{
            return m_nSum;
        }
    private:
        int m_nSum;
};

int main(){
    CAdd add;
//    std::function<int(int)> f1 = add;  //value
//    std::function<int(int)> f2 = add;  //value
    std::function<int(int)> f1 = std::ref(add); //reference
    std::function<int(int)> f2 = std::ref(add); //reference
    std::cout << f1(10) << "," << f2(10) << "," << add.Sum() << std::endl;
    return 0;
}