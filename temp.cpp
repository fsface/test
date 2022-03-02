#include <iostream>
#include <fstream>

int main(){
    std::fstream fs;
    fs.open("mytest.txt", std::fstream::out);
    if(fs.is_open()){
        std::cout << "open sucessfuly " << std::endl;
    }
    else{
        std::cout << "open failed" << std::endl;
    }
    fs.close();
    return 0;
}