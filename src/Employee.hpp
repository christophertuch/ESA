#pragma once

#include <iostream>
#include "Date.hpp"

class Employee
{
private:
    std::string m_name;
    std::string m_prename;
    Date m_birthday;     // YYYY-MM-DD
    double m_disability; // 0.0 - 1.0
    int m_vacationDaysTaken;
    int m_vacationDays;

public:
    Employee(std::string name, std::string prename, std::string birthday, double disability, int vacationDaysTaken);
    std::string getName();
    std::string getPrename();
    Date getBirthday();
    double getDisability();
    int getVacationDaysTaken();
    void setVacationDaysTaken(int days);
    int getVacationDays();
    void setVacationDays(int days);
    static int calculateVacationDays(Employee *employee);
};