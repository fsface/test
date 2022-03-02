#include <iostream>
#include "mytime0.h"

Time::Time(){
    hours = 0;
    minutes = 0;
}

Time::Time(int h, int m){
    hours = h;
    minutes = m;
}

void Time::addMin(int m){
    minutes += m;
    hours += (minutes / 60);
    minutes %= 60;
}

void Time::addHour(int h){
    hours += h;
}

void Time::reset(int h , int m ){
    hours = h ;
    minutes = m % 60;
}

Time Time::sum(const Time &t) const{
    Time temp;
    temp.hours = this->hours + t.hours + ((this->minutes + t.minutes) / 60);
    temp.minutes = (this->minutes + t.minutes) % 60;
    return temp;
}

void Time::show() const{
    std::cout << "hour : " << this->hours << " " << "minutes : " << this->minutes << std::endl;
}

Time Time::operator+(const Time &t) const{
    Time temp;
    temp.hours = this->hours + t.hours + ((this->minutes + t.minutes) / 60);
    temp.minutes = (this->minutes + t.minutes) % 60;
    return temp;
}

Time Time::operator-(const Time &t) const{
    Time temp;
    int t1;
    int t2;
    t1 = (this->hours)*60 + this->minutes;
    t2 = t.hours * 60 + t.minutes;
    temp.hours = (t1 - t2) / 60;
    temp.minutes = (t1 - t2) % 60;
    return temp;
}

// nomember function overload operator
Time operator*(int i, const Time &t){
    Time result;
    int totalMinutes = t.hours * i * 60 + t.minutes * i;
    result.hours = totalMinutes / 60;
    result.minutes = totalMinutes % 60;
    return result;
}

std::ostream& operator<<(std::ostream &os, const Time &t){
    os << "hour : " << t.hours << " minutes : " << t.minutes << std::endl;
}