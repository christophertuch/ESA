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
    m_year = std::stoi(date.substr(0, 4));
    m_month = std::stoi(date.substr(5, 2));
    m_day = std::stoi(date.substr(8, 2));
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
    time_t now = time(0);
    tm *ltm = localtime(&now);
    Date currentDate(ltm->tm_year + 1900, ltm->tm_mon + 1, ltm->tm_mday);
    return currentDate;
}