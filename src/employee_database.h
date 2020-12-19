#ifndef EMPLOYEE_DATABASE_H
#define EMPLOYEE_DATABASE_H

#include <string>
#include <vector>
#include "./arduino_code/employee.h"

using namespace std;

class EmployeeDatabase {
    private:
        vector<Employee> list_of_employees;
    public:
        EmployeeDatabase();

        vector<Employee> getEmployeeDatabase();
        vector<Employee> getEmployeeDatabaseByCP();

        void addEmployee(Employee employee_to_add);
        Employee* removeEmployeeByID(int id_to_remove);
        Employee* removeEmployeeByName(string first_name_to_remove, string last_name_to_remove);
};

#endif