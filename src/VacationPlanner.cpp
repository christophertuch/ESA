#include "VacationPlanner.hpp"
#include "Employee.hpp"

VacationPlanner::VacationPlanner()
{
}

void VacationPlanner::addEmployee()
{
    std::string name;
    std::string prename;
    std::string birthday;
    double disability;
    int vacationDaysTaken;

    std::cout << "Name: ";
    std::cin >> name;
    std::cout << "Prename: ";
    std::cin >> prename;
    std::cout << "Birthday (YYYY-MM-DD): ";
    std::cin >> birthday;
    std::cout << "Disability (0.0 - 1.0): ";
    std::cin >> disability;
    std::cout << "Vacation days taken: ";
    std::cin >> vacationDaysTaken;
    Employee employee(name, prename, birthday, disability, vacationDaysTaken);
    m_employees.push_back(employee);
}

void VacationPlanner::deleteEmployee()
{
    this->printEmployees();
    std::string name;
    std::string prename;

    std::cout << "Name: ";
    std::cin >> name;
    std::cout << "Prename: ";
    std::cin >> prename;
    Employee employee(name, prename, "", 0.0, 0);
    for (int i = 0; i < (int)m_employees.size(); i++)
    {
        if (m_employees[i].getName() == employee.getName() && m_employees[i].getPrename() == employee.getPrename())
        {
            m_employees.erase(m_employees.begin() + i);
        }
    }
}

void VacationPlanner::printEmployees()
{
    for (int i = 0; i < (int)m_employees.size(); i++)
    {
        std::cout << m_employees[i].getName() << " " << m_employees[i].getPrename() << std::endl;
    }
}

int VacationPlanner::run()
{
    std::cout << "Warm welcome to VacationPlanner!" << std::endl;

    return 0;
}

int main()
{
    VacationPlanner *planner = new VacationPlanner();

    planner->run();
    return 0;
}