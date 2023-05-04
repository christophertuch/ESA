#include "Employee.hpp"

Employee::Employee(std::string name, std::string prename, std::string birthday, double disability, int vacationDaysTaken)
{
    m_name = name;
    m_prename = prename;
    Date b_temp(birthday);
    m_birthday = b_temp;
    m_disability = disability;
    m_vacationDaysTaken = vacationDaysTaken;
    m_vacationDays = Employee::calculateVacationDays(this);
}

std::string Employee::getName()
{
    return m_name;
}

std::string Employee::getPrename()
{
    return m_prename;
}

Date Employee::getBirthday()
{
    return m_birthday;
}

double Employee::getDisability()
{
    return m_disability;
}

int Employee::getVacationDaysTaken()
{
    return m_vacationDaysTaken;
}

void Employee::setVacationDaysTaken(int days)
{
    m_vacationDaysTaken = days;
}

int Employee::getVacationDays()
{
    return m_vacationDays;
}

void Employee::setVacationDays(int days)
{
    m_vacationDays = days;
}

int Employee::calculateVacationDays(Employee *employee)
{
    int vacationDays = 30;
    int age = employee->getBirthday().getYear() - Date::getCurrentDate().getYear();
    if (age > 50)
    {
        vacationDays = vacationDays + 2;
    }
    if (employee->getDisability() >= 0.5)
    {
        vacationDays = vacationDays + 5;
    }
    vacationDays = vacationDays - employee->getVacationDaysTaken();
    return vacationDays;
}