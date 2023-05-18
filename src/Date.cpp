#include "Date.hpp"

Date::Date()
{
    m_year = 0;
    m_month = 0;
    m_day = 0;
}

Date::Date(int year, int month, int day)
{
    m_year = year;
    m_month = month;
    m_day = day;
}

Date::Date(std::string date)
{
    m_year = std::stoi(date.substr(0, 4));  // asssign first 4 characters of string to m_year
    m_month = std::stoi(date.substr(5, 2)); // asssign 5th and 6th characters of string to m_month
    m_day = std::stoi(date.substr(8, 2));   // asssign 8th and 9th characters of string to m_day
}

int Date::getYear()
{
    return m_year;
}

int Date::getMonth()
{
    return m_month;
}

int Date::getDay()
{
    return m_day;
}

void Date::setYear(int year)
{
    m_year = year;
}

void Date::setMonth(int month)
{
    m_month = month;
}

void Date::setDay(int day)
{
    m_day = day;
}

void Date::print()
{
    std::cout << m_year << "-" << m_month << "-" << m_day << std::endl;
}

Date Date::getCurrentDate()
{
    time_t now = time(0);                                                 // get time now from time_t.h
    tm *ltm = localtime(&now);                                            // convert now to tm struct for local timezone
    Date currentDate(ltm->tm_year + 1900, ltm->tm_mon + 1, ltm->tm_mday); // create Date object from tm struct
    return currentDate;                                                   // return Date object
}

int Date::getAge()
{
    Date currentDate = Date::getCurrentDate();
    int age = currentDate.getYear() - m_year; // calculate age by subtracting birth year from current year
    if (currentDate.getMonth() < m_month)     // if current month is less than birth month
    {
        age--; // subtract 1 from age
    }
    else if (currentDate.getMonth() == m_month) // if current month is equal to birth month
    {
        if (currentDate.getDay() < m_day) // if current day is less than birth day
        {
            age--; // subtract 1 from age
        }
    }
    return age; // return age
}

std::string Date::toString()
{
    std::string year = std::to_string(m_year);   // convert yeae int to string
    std::string month = std::to_string(m_month); // convert month int to string
    std::string day = std::to_string(m_day);     // convert day int to string
    if (m_month < 10)                            // if month is less than 10
    {
        month = "0" + month; // add 0 to the front of month
    }
    if (m_day < 10) // if day is less than 10
    {
        day = "0" + day; // add 0 to the front of day
    }
    return year + "-" + month + "-" + day; // return date as string
}