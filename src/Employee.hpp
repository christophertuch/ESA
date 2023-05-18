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
    int m_id; // unique id for each employee (auto increment)

public:
    /// @brief Contructor to create a new Employee
    /// @param name
    /// @param prename
    /// @param birthday
    /// @param disability
    /// @param vacationDaysTaken
    Employee(std::string name, std::string prename, std::string birthday, double disability, int vacationDaysTaken);

    /// @brief Generate ID for new Employee
    /// @return ID
    static int generateId();

    /// @brief get member variable m_name
    /// @return m_name
    std::string getName();

    /// @brief get member variable m_prename
    /// @return m_prename
    std::string getPrename();

    /// @brief get member variable m_birthday
    /// @return m_birthday
    void printEmployee();

    /// @brief get member variable m_birthday
    /// @return m_birthday
    Date getBirthday();

    /// @brief get member variable m_disability
    /// @return m_disability
    double getDisability();

    /// @brief get member variable m_vacationDaysTaken
    /// @return m_vacationDaysTaken
    int getVacationDaysTaken();

    /// @brief set member variable m_vacationDaysTaken
    /// @param days
    void setVacationDaysTaken(int days);

    /// @brief get member variable m_vacationDays
    /// @return m_vacationDays
    int getVacationDays();

    /// @brief set member variable m_vacationDays
    /// @param days
    void setVacationDays(int days);

    /// @brief calculate the vacation days for an employee, while creating the employee
    /// @param employee
    static int calculateVacationDays(Employee *employee);

    /// @brief take vacation days
    void takeVacation(int days);
};