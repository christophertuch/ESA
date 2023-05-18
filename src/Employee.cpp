#include "Employee.hpp"

Employee::Employee(std::string name, std::string prename, std::string birthday, double disability, int vacationDaysTaken)
{
    m_name = name;
    m_prename = prename;
    Date b_temp;
    try
    {
        Date b_temp(birthday);
    }
    catch (...)
    {
        std::cout << "Using default birthday: 1970-01-01" << std::endl;
        Date b_temp("1970-01-01");
        m_birthday = b_temp;
    }
    m_disability = disability;
    m_vacationDays = Employee::calculateVacationDays(this);
    if (vacationDaysTaken > m_vacationDays)
    {
        std::cout << "You can't take more vacation days than you have. Assuming all have been taken." << std::endl;
        m_vacationDaysTaken = m_vacationDays;
    }
    else
    {
        m_vacationDaysTaken = vacationDaysTaken;
    }
    m_vacationDays = Employee::calculateVacationDays(this);
    m_id = Employee::generateId();
}

int Employee::generateId()
{
    static int id = 1;
    return id++;
}

void Employee::printEmployee()
{
    std::cout << "ID: " << this->m_id << ", ";
    std::cout << "Name: " << this->getName() << ", ";
    std::cout << "Prename: " << this->getPrename() << ", ";
    std::cout << "Birthday: " << this->getBirthday().toString() << ", ";
    std::cout << "Disability: " << this->getDisability() << ", ";
    std::cout << "Vacation days taken: " << this->getVacationDaysTaken() << ", ";
    std::cout << "Vacation days left: " << this->getVacationDays() << std::endl;
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

void Employee::takeVacation(int days)
{
    m_vacationDaysTaken = m_vacationDaysTaken + days;
    m_vacationDays = m_vacationDays - days;
}

int Employee::calculateVacationDays(Employee *employee)
{
    int vacationDays = 30;
    int age = employee->getBirthday().getAge();
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