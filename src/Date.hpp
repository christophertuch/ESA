#pragma once

#include <iostream>

class Date
{
private:
    int m_year;
    int m_month;
    int m_day;

public:
    Date();
    Date(int year, int month, int day);
    Date(std::string date); // YYYY-MM-DD
    int getYear();
    int getMonth();
    int getDay();
    void setYear(int year);
    void setMonth(int month);
    void setDay(int day);
    void print();
    static Date getCurrentDate();
};