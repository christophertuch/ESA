#include "Date.hpp"

Date::Date()
{
    m_year = 1900;
    m_month = 1;
    m_day = 1;
}
Date::Date(int year, int month, int day)
{
    try
    {
        m_year = year;
        m_month = month;
        m_day = day;
    }
    catch (const std::exception &e)
    {
        std::cerr << e.what() << '\n';
        while (dateValidation(*this) != 0)
        {
            std::cout << "Please enter a valid date in the format YYYY-MM-DD" << std::endl;
            std::string date;
            std::cin >> date;
            Date *validationDate = new Date(date);
            m_year = validationDate->getYear();
            m_month = validationDate->getMonth();
            m_day = validationDate->getDay();
        }
    }
}

Date::Date(std::string date)
{
    try
    {
        m_year = std::stoi(date.substr(0, 4));
        m_month = std::stoi(date.substr(5, 2));
        m_day = std::stoi(date.substr(8, 2));
    }
    catch (const std::exception &e)
    {

        while (dateValidation(*this) != 0)
        {
            std::cerr << "Please enter a valid date in the format YYYY-MM-DD" << '\n';
            std::string date;
            std::cin >> date;
            Date *validationDate = new Date(date);
            m_year = validationDate->getYear();
            m_month = validationDate->getMonth();
            m_day = validationDate->getDay();
        }
    }
}

int Date::dateValidation(Date date)
{
    if (date.getYear() < 1900 || date.getYear() > date.getCurrentDate().getYear()) // check if year is valid
    {
        return 1;
    }
    if (date.getMonth() < 1 || date.getMonth() > 12) // check if month is valid
    {
        return 2;
    }
    if (date.getDay() < 1 || date.getDay() > 31) // check if day is valid
    {
        return 3;
    }
    if (date.getMonth() == 2) // check if day is valid for february
    {
        if (date.getDay() > 28)
        {
            if (isLeapYear(date.getYear()))
            {
                return 0;
            }
            else
            {
                std::cerr << "Date is not valid!" << std::endl;
                return 4;
            }
        }
    }
    if (date.getMonth() == 4 || date.getMonth() == 6 || date.getMonth() == 9 || date.getMonth() == 11) // check if day is valid for april, june, september, november
    {
        if (date.getDay() > 30)
        {
            return 5;
        }
    }
    return 0;
}

bool Date::isLeapYear(int year)
{
    if ((year % 4 == 0 && year % 100 != 0) || (year % 4 == 0 && year % 400 == 0))
    {
        return true;
    }
    else
    {
        return false;
    }
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