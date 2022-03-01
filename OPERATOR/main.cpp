#include "mytime0.h"
#include <iostream>

int main(){
    using std::cout;
    using std::endl;

    Time plan;
    Time codeing(2, 40);
    Time fixing(5, 55);
    Time total;
    Time sub;
    Time temp;

    cout << "plan time is ";
    plan.show();

    codeing.addMin(30);
    codeing.show();

    total = codeing.sum(fixing);
    total.show();

    total = codeing + fixing;
    total.show();

    total = codeing.operator+(fixing);
    total.show();

    sub = fixing - codeing;
    sub.show();

    temp = 2 * sub;
    temp.show();

    cout << temp;

    return 0;
}