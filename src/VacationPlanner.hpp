#pragma once

#include <iostream>
#include "Employee.hpp"

class VacationPlanner
{
private:
    std::vector<Employee> m_employees;

public:
    VacationPlanner();
    int run();
    void addEmployee();
    void deleteEmployee();
    void printEmployees();
};