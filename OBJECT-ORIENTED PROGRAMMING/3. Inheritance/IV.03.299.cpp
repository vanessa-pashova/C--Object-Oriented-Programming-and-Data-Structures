//Да се напише програма, която изгражда йерархия, където класът Дата определя коректна дата чрез цели числа, задаващи ден, месец и година. Класът Време определя коректно 
//време чрез цели числа, определящи час, минути и секунди, а класът ДатаВреме обединява Дата и Време като ги представи чрез символен низ във вида: чч/мм/гг и чч:мм:сс

#include <iostream>

class Date
{
    private:
        int day, month, year;

        void copyFrom(const Date &other)
        {
            this->day = other.day;
            this->month = other.month;
            this->year = other.year;
        }

    public:
        Date(int = 1, int = 1, int = 1999);
        // Date(const Date &);
        Date &operator=(const Date &);

        int getDay() const;
        int getMonth() const;
        int getYear() const;

        void print() const;
};

Date::Date(int d, int m, int y)
{
    if (0 < d && d < 32)
        this->day = d;

    else 
    {
        // std::cout << "[ invalid day chosen - day set to 1 by default ]\n";
        this->day = 1;
    }

    if (0 < m && m < 13)
        this->month = m;

    else 
    {
        // std::cout << "[ invalid month chosen - month set to 1 by default ]\n";
        this->month = 1;
    }

    if (1998 < y && y < 2051)
        this->year = y;

    else
    {
        // std::cout << "[ invalid year chosen - year set to 1999 by default ]\n";
        this->year = 1999;
    }
}

// Date::Date(const Date &other) {
//     this->copyFrom(other);
// }

Date &Date::operator=(const Date &other)
{
    if (this != &other)
        this->copyFrom(other);

    return *this;
}

int Date::getDay() const {
    return this->day;
}

int Date::getMonth() const {
    return this->month;
}

int Date::getYear() const {
    return this->year;
}

void Date::print() const 
{
    if (0 < this->day && this->day < 10)
        std::cout << '0' << this->day << '.';

    else std::cout << this->day << '.';

    if (0 < this->month && this->month < 10)
        std::cout << '0' << this->month << '.';

    else std::cout << this->month << '.';

    std::cout << this->year << '\n';
}

class Time
{
    private:
        int hours, minutes, seconds;

        void copyFrom(const Time &other)
        {
            this->hours = other.hours;
            this->minutes = other.minutes;
            this->seconds = other.seconds;
        }

    public:
        Time(int = 0, int = 0, int = 0);
        Time &operator=(const Time &);

        int getHours() const;
        int getMinutes() const;
        int getSeconds() const;

        void print();
};

Time::Time(int h, int m, int s)
{
    if (-1 < h && h < 24)
        this->hours = h;

    else 
        this->hours = 0;

    if (-1 < m && m < 60)
        this->minutes = m;

    else 
        this->minutes = 0;

    if (-1 < s && s < 60)
        this->seconds = s;

    else
        this->seconds = 0;
}

Time &Time::operator=(const Time &other)
{
    if (this != &other)
        this->copyFrom(other);

    return *this;
}

int Time::getHours() const {
    return this->hours;
}

int Time::getMinutes() const {
    return this->minutes;
}

int Time::getSeconds() const {
    return this->seconds;
}

void Time::print() 
{
    if (-1 < this->hours && this->hours < 10)
        std::cout << '0' << this->hours << ':';

    else std::cout << this->hours << ':';

    if (-1 < this->minutes && this->minutes < 10)
        std::cout << '0' << this->minutes << ':';

    else std::cout << this->minutes << ':';

    if (-1 < this->seconds && this->seconds < 10)
        std::cout << '0' << this->seconds << '\n';

    else std::cout << this->seconds << '\n';
}

class DateTime : public Date, Time
{
    private:
        char dateTimeString[20];

    public: 
        DateTime(int, int, int, int, int, int);
        char *getDateTime();
};

DateTime::DateTime(int d, int m, int y, int h, int min, int s) : Date(d, m, y), Time(h, min, s) {}

int main ()
{
    std::cout << '\n';
    std::cout << "---------------------------" << '\n';

    Date d, d2(18, 45, 2003);
    d.print();
    d2.print();

    Time t, t2(24, 25, 50);
    t.print();
    t2.print();
}
//недовършена
