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

    /// @brief Contructor to create a new Date
    Date(int year, int month, int day);

    /// @brief Contructor to create a new Date by string input
    Date(std::string date); // YYYY-MM-DD

    /// @brief convert date to string
    /// @return date as string
    std::string toString();

    /// @brief validate date
    int dateValidation(Date date);

    /// @brief check if year is a leap year
    bool isLeapYear(int year);

    /// @brief get member variable m_year
    /// @return m_year
    int getYear();

    /// @brief get member variable m_month
    /// @return m_month
    int getMonth();

    /// @brief get member variable m_day
    /// @return m_day
    int getDay();

    /// @brief get age of date
    /// @return age
    int getAge();

    /// @brief set member variable m_year
    /// @param year
    void setYear(int year);

    /// @brief set member variable m_month
    /// @param month
    void setMonth(int month);

    /// @brief set member variable m_day
    /// @param day
    void setDay(int day);

    /// @brief print date
    void print();
    static Date getCurrentDate();
};