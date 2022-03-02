#include <fstream>
#include <iostream>

void F_Open()
{
    std::fstream fs;
    fs.open("test.txt", std::fstream::in | std::fstream::out | std::fstream::app);
    fs << "more good news";
    fs.close();
}

void F_Isopen()
{
    std::fstream fs;
    fs.open("test.txt", std::fstream::in | std::fstream::out | std::fstream::trunc);
    if(fs.is_open())
    {
        fs << "fake news ";
        std::cout << "open file sucessfuly" << "\n";
        fs.close();
    }
    else
    {
        std::cout << "open file failed" << "\n";
    }
}

void F_Swap()
{
    std::fstream foo;
    std::fstream bar("test.txt");
    foo.swap(bar);
    foo << "good news";
    foo.close();
}

void Fi_Seek()
{
    std::ifstream infile ("test.txt", std::ifstream::binary);
    std::ofstream outfile ("new.txt", std::ifstream::binary);

    //get size of file
    infile.seekg(0, infile.end);
    long size = infile.tellg();
    infile.seekg(0);

    //allocate memory
    char *buffer = new char[size];

    //read content of infile
    infile.read(buffer, size);

    //write to outfile
    outfile.write(buffer, size);

    //release memory
    delete[] buffer;

    outfile.close();
    infile.close();

}

void Io_Getline()
{
    char name[256], title[256];
    std::cout << "Please , enter your name: ";
    std::cin.getline(name, 256);

    std::cout << "Please, enter your favourite movie: ";
    std::cin.getline(title, 256);

    std::cout << name << "'s favourite moive is " << title << "\n";
}

void F_Read_File()
{
    std::ifstream input("fake.txt");
    char text = 0;
    while(input.get(text))
    {
        if(text != EOF)
        {
            std::cout << text;
        }
        else
        {
            break;
        }
    }
    std::cout << "\n";
    std::cout << "The end of file" << std::endl;
    input.close();
}

void Fi_Getline(){
    std::ifstream fin("fake.txt");
    const int LIN_LEN = 100;
    char str[LIN_LEN];
    while(fin.getline(str, LIN_LEN))
    {
        std::cout << "read from file : " << str << std::endl;
    }
}

int main()
{
//    F_Open();
//    F_Isopen();
//    F_Swap();
//    Fi_Seek();
//    Io_Getline();
//    F_Read_File();
    Fi_Getline();
    return 0;
}