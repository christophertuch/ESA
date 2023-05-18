#pragma once

#include <iostream>
#include "Employee.hpp"

class VacationPlanner
{
private:
    std::vector<Employee> m_employees;

public:
    /// @brief Constructor of the class VacationPlanner.
    VacationPlanner();

    /// @brief This function runs the application.
    int run();

    /// @brief This function prints, to press enter to continue, to the console.
    void pressEnterToContinue();

    /// @brief this is main menu, for selecting the different functions of the program.
    /// @return application run status
    bool menu();

    /// @brief This function prints a line break to the console.
    void lineBreak();

    /// @brief This function generates test data for the program by adding 5 employees with different names, birthdays (under 52 years old and over 52 years old), different disablity grades and vacation days taken to the vector of employees.
    void generateTestData();

    /// @brief This function generates test data for the program by adding 499 employees
    void generateMaxTestData();

    /// @brief This function adds an employee to the vector of employees. I will query the user for the data.
    void addEmployee();

    /// @brief This function deletes an employee from the vector of employees.
    void deleteEmployee();

    /// @brief This function prints the data of all employees in the vector of employees.
    void printEmployees();

    /// @brief This function prints the data of a specific employee in the vector of employees.
    void printEmployee();

    /// @brief This function takes vacation for a specific employee in the vector of employees.
    void takeVacation();
};