#include <iostream>
#include <queue>

int main()
{
    std::queue<int> myQueue;
    int myInt;
    std::cout << "Please enter som intergers (enter 0 to end):\n";
    do{
        std::cin >> myInt;
        myQueue.push(myInt);
    }while(myInt);

    std::cout << "myQueue size is " << myQueue.size() << "\n";
    std::cout << "myQueue last element is " << myQueue.back() << "\n";
    std::cout << "myQueue first element is " << myQueue.front() << "\n";

    std::cout << "myqueue contains:";
    while(!myQueue.empty())
    {
        std::cout << " " << myQueue.front();
        myQueue.pop();
    }
    std::cout << "\n";
    return 0;
}