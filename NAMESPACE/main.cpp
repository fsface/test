#include <iostream>
#include <string>
namespace jack{
    int money;
    void Pri(){
        std::cout << money << std::endl;
    }
    struct school{
        int age;
        std::string schoolStr;
    };
}

namespace libai{
    int money;
    double weigth;
    void Pri(){
        std::cout << "my name is libai " << std::endl;
    }
    void Drink(){
        std::cout << "libai likes drink " << std::endl;
    }
}

//add new members to namespace
namespace jack{
    std::string str = "nihao";
}

namespace elements{
    std::string water;
    namespace fire{
        double tempture;
        std::string flame;
    }
}

void Test(){
    jack::money = 10;
    jack::Pri();
    jack::school mySchool;
    mySchool.age = 100;
    mySchool.schoolStr = "good school";
    std::cout << jack::str << std::endl;
}

void Test1(){
    jack::money = 10;  //different namespace have same varible value is vaild
    libai::money = 20;
}
// use command "using" or "using namespace"
void Test2(){
    using namespace jack;
    money = 10;
    Pri();
    using libai::Drink;
    Drink();
}

void Test3(){
    elements::fire::tempture = 50.9;
    std::cout << elements::fire::tempture << std::endl;
}


int main(){
    // Test();
    //Test1();
    //Test2();
    Test3();
    return 0;
}