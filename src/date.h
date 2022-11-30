#pragma once

#include <string>
#include <ctime>
#include <ostream>

class Date {

public:
    Date();
    Date(int day, int month, int year);



    int getDay() const;
    int getMonth() const;
    int getYear() const;

    void setDay(int day);
    void setMonth(int month);
    void setYear(int year);

    // Operators

    bool operator == (const Date& d) const; // d1 == d2
    bool operator != (const Date& d) const; // d1 != d2
    bool operator < (const Date& d) const;  // d1 <  d2
    bool operator > (const Date& d) const;  // d1 >  d2
    bool operator <= (const Date& d) const; // d1 <= d2
    bool operator >= (const Date& d) const; // d1 <= d2
    Date operator + (const int days) const; // d1 + integer
    Date operator - (const int days) const; // d1 - integer
    Date operator ++ (); // prefix increment: ++date
    Date operator -- (); // prefix decrement: --date
    Date operator ++ (int); // use int paramater for postfix increment: date++
    Date operator -- (int); // use int paramater for postfix decrement: date--

private:
    //Variables
    int _day;
    int _month;
    int _year;
};

bool isDate(int year,int month, int day);
int getDaysInMonth(int month);
int dayOfYear(Date d);

std::string to_string(const Date& d);
std::ostream& operator<<(std::ostream& os, const Date& date);
