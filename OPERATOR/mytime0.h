#ifndef mytime0_H_
#define mytime0_H_

#include <iostream>

class Time{
    public:
        Time();
        Time(int h, int m = 0);
        void addMin(int m);
        void addHour(int h);
        void reset(int h = 0, int m = 0);
        Time sum(const Time &t) const;
        void show() const;
        Time operator+(const Time &t) const;
        Time operator-(const Time &t) const;
        friend Time operator*(int i, const Time &t);
        friend std::ostream& operator<<(std::ostream &os, const Time &t);
    private:
        int hours;
        int minutes;
};

#endif