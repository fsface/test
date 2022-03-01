// fstream construction
#include <fstream>
#include <iostream>

int main()
{
    std::fstream fs("test.txt", std::fstream::in | std::fstream::out);
    // i/o operations here
    fs.close();
    return 0;
}