#include "VacationPlanner.hpp"
#include "Employee.hpp"

VacationPlanner::VacationPlanner()
{
}

void VacationPlanner::addEmployee()
{
    this->lineBreak();
    if (m_employees.size() >= 500)
    {
        std::cout << "You can't add more than 500 employees." << std::endl;
        this->pressEnterToContinue();
        this->lineBreak();
        return;
    }
    std::string name;
    std::string prename;
    std::string birthday;
    double disability;
    int vacationDaysTaken;

    // query user for input data
    // TODO: Add input validation
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
    this->lineBreak();
    std::cout << "Employee added." << std::endl;
    this->pressEnterToContinue();
}

void VacationPlanner::deleteEmployee()
{
    this->lineBreak();
    this->printEmployees();
    std::string name;
    std::string prename;

    // query user for input data
    std::cout << "Name: ";
    std::cin >> name;
    std::cout << "Prename: ";
    std::cin >> prename;
    std::vector<Employee *> result;
    for (int i = 0; i < (int)m_employees.size(); i++)
    {
        if (m_employees[i].getName() == name && m_employees[i].getPrename() == prename)
        {
            result.push_back(&m_employees[i]);
        }
    }
    std::cout << "Select the Employee." << std::endl;
    for (int i = 0; i < (int)result.size(); i++)
    {
        std::cout << i + 1 << ". ";
        result[i]->printEmployee();
    }
    int selection;
    while (true)
    {
        std::cin >> selection;
        if (selection < 1 || selection > (int)result.size())
        {
            std::cout << "Invalid selection." << std::endl;
            continue;
        }
        break;
    }
    for (int i = 0; i < (int)m_employees.size(); i++)
    {
        if (&m_employees[i] == result[selection - 1])
        {
            m_employees.erase(m_employees.begin() + i);
            break;
        }
    }
    this->lineBreak();
    std::cout << "Employee deleted!" << std::endl;
    this->pressEnterToContinue();
}

void VacationPlanner::lineBreak()
{
    std::cout << "----------------------------------------" << std::endl;
}

void VacationPlanner::printEmployee()
{
    this->lineBreak();
    // Create a new employee to filter for the name and prename
    std::string name;
    std::string prename;
    std::cin.clear();
    std::cout << "Name: ";
    std::cin >> name;
    std::cout << "Prename: ";
    std::cin >> prename;
    std::vector<Employee *> result;
    for (int i = 0; i < (int)m_employees.size(); i++)
    {
        if (m_employees[i].getName() == name && m_employees[i].getPrename() == prename)
        {
            result.push_back(&m_employees[i]);
        }
    }
    if (result.size() == 0)
    {
        std::cout << "No employee found with this name and prename." << std::endl;
        this->lineBreak();
        this->pressEnterToContinue();
        return;
    }
    std::cout << "Result: " << std::endl;
    for (int i = 0; i < (int)result.size(); i++)
    {
        std::cout << i + 1 << ". ";
        result[i]->printEmployee();
    }

    this->lineBreak();
    this->pressEnterToContinue();
}

void VacationPlanner::printEmployees()
{
    this->lineBreak();
    if (m_employees.size() == 0)
    {
        std::cout << "No employees found." << std::endl;
        this->lineBreak();
        std::cout << "Press any key to continue." << std::endl;
        std::cin.ignore();
        std::cin.get();
        return;
    }
    std::cout << "Employees:" << std::endl;
    for (int i = 0; i < (int)m_employees.size(); i++)
    {
        std::cout << i + 1 << ". ";
        m_employees[i].printEmployee();
    }
    this->lineBreak();
    this->pressEnterToContinue();
}
void VacationPlanner::generateTestData()
{
    if ((int)m_employees.size() > 499)
    {
        std::cout << "Can't add more then 500 employees." << std::endl;
        return;
    }
    else
    {
        std::vector<Employee> testData;
        Employee employee1("Mustermann", "Max", "1990-01-01", 0.0, 0);
        Employee employee2("Leiser", "Maxine", "1990-01-01", 0.0, 10);
        Employee employee3("Maier", "Mario", "1960-01-01", 0.0, 0);
        Employee employee4("Bauer", "Benjamin", "1960-01-01", 0.0, 5);
        Employee employee5("Lackner", "Leo", "1990-01-01", 0.3, 0);
        Employee employee6("Landmann", "Sören", "1990-01-01", 0.5, 0);
        Employee employee7("Raiser", "Roland", "1990-01-01", 0.5, 10);
        Employee employee8("Mustermann", "Max", "1960-01-01", 1, 0);
        Employee employee9("Müller", "Luis", "1960-01-01", 1, 15);

        testData.push_back(employee1);
        testData.push_back(employee2);
        testData.push_back(employee3);
        testData.push_back(employee4);
        testData.push_back(employee1);
        testData.push_back(employee5);
        testData.push_back(employee6);
        testData.push_back(employee7);
        testData.push_back(employee8);
        testData.push_back(employee9);
        for (int i = 0; i < (int)testData.size(); i++)
        {
            if ((int)m_employees.size() > 499)
            {
                std::cout << "Can't add more then 500 employees." << std::endl;
                this->pressEnterToContinue();
                return;
            }
            else
            {
                m_employees.push_back(testData[i]);
            }
        }
        this->lineBreak();
        std::cout << "Test data generated." << std::endl;
        this->pressEnterToContinue();
        this->printEmployees();
    }
}

void VacationPlanner::generateMaxTestData()
{
    if ((int)m_employees.size() > 499)
    {
        std::cout << "Can't add more then 500 employees." << std::endl;
        return;
    }
    else
    {
        for (int i = 0; i < 498; i++)
        {
            Employee employee("Mustermann", "Max", "1990-01-01", 0.0, 0);
            m_employees.push_back(employee);
        }
        std::cout << "499 Employees added." << std::endl;
        this->lineBreak();
        std::cout << "Test data generated." << std::endl;
        this->pressEnterToContinue();
    }
}

void VacationPlanner::takeVacation()
{
    this->lineBreak();
    std::string name;
    std::string prename;
    std::cin.clear();
    std::cout << "Name: ";
    std::cin >> name;
    std::cout << "Prename: ";
    std::cin >> prename;
    std::vector<Employee *> result;
    for (int i = 0; i < (int)m_employees.size(); i++)
    {
        if (m_employees[i].getName() == name && m_employees[i].getPrename() == prename)
        {
            result.push_back(&m_employees[i]);
        }
    }
    std::cout << "Select the Employee." << std::endl;
    for (int i = 0; i < (int)result.size(); i++)
    {
        std::cout << i + 1 << ". ";
        result[i]->printEmployee();
    }
    int selection;
    while (true)
    {
        std::cin >> selection;
        if (selection < 1 || selection > (int)result.size())
        {
            std::cout << "Invalid selection." << std::endl;
            continue;
        }
        break;
    }
    std::cout << "How many days do you want to take? ";
    int days;
    std::cin >> days;
    if (days < 0)
    {
        std::cout << "Invalid number of days." << std::endl;
        return;
    }
    else if (days > result[selection - 1]->getVacationDays())
    {
        std::cout << "Not enough vacation days." << std::endl;
        return;
    }
    result[selection - 1]->takeVacation(days);
    this->lineBreak();
    this->pressEnterToContinue();
}

void VacationPlanner::pressEnterToContinue()
{
    std::cout << "Press enter key to continue." << std::endl;
    std::cin.ignore();
    std::cin.get();
}

bool VacationPlanner::menu()
{
    std::cout << "What do you want to do?" << std::endl;
    this->lineBreak();
    std::cout << "1. Add employee" << std::endl;
    std::cout << "2. Delete employee" << std::endl;
    std::cout << "3. Print data of all employees" << std::endl;
    std::cout << "4. Print data of Employee" << std::endl;
    std::cout << "5. Take vacation" << std::endl;
    std::cout << "6. Generate test data (add 9 Employees covering all cases)" << std::endl;
    std::cout << "7. generate test data (add 499 to test max size)" << std::endl;
    std::cout << "9. Exit" << std::endl;
    this->lineBreak();
    int input;
    std::cout << "Input: ";
    std::cin.clear();
    std::cin >> input;
    switch (input)
    {
    case 1:
        this->addEmployee();
        break;
    case 2:
        this->deleteEmployee();
        break;
    case 3:
        this->printEmployees();
        break;
    case 4:
        this->printEmployee();
        break;
    case 5:
        this->takeVacation();
        break;
    case 6:
        this->generateTestData();
        break;
    case 7:
        this->generateMaxTestData();
        break;
    case 9:
        std::cout << "Goodbye!" << std::endl;
        return false;
    }
    return true;
}

int VacationPlanner::run()
{

    std::cout << "Warm welcome to VacationPlanner!" << std::endl;
    bool running = true;
    while (running)
    {
        running = this->menu();
    }
    return 0;
}

int main()
{
    VacationPlanner *planner = new VacationPlanner();

    planner->run();
    return 0;
}