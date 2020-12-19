#include "employee_database.h"

using namespace std;

EmployeeDatabase::EmployeeDatabase() {
}

vector<Employee> EmployeeDatabase::getEmployeeDatabase() {
    return list_of_employees;
}

vector<Employee> getEmployeeDatabaseByCP() {

}

bool sortContaminationPercentage(Employee e1, Employee e2) {
    return e1.getContaminationPercentage() < e2.getContaminationPercentage();
}

void EmployeeDatabase::addEmployee(Employee employee_to_add) {
    list_of_employees.push_back(employee_to_add);
}

Employee* EmployeeDatabase::removeEmployeeByID(int id_to_remove) {
    int indexToErase;
    bool foundElement = false;
    for (int i = 0; i < list_of_employees.size(); i++) {
        if (list_of_employees[i].getID() == id_to_remove) {
            foundElement = true;
            indexToErase = i;
            break;
        }
    }
    if (foundElement) {
        Employee* toReturn = &list_of_employees[indexToErase];
        list_of_employees.erase(list_of_employees.begin() + indexToErase);
        return toReturn;
    } else {
        return nullptr;
    }
}

Employee* EmployeeDatabase::removeEmployeeByName(string first_name_to_remove, string last_name_to_remove) {
    int indexToErase;
    bool foundElement = false;
    for (int i = 0; i < list_of_employees.size(); i++) {
        if (list_of_employees[i].getFirstName().compare(first_name_to_remove) == 0 && list_of_employees[i].getLastName().compare(last_name_to_remove) == 0) {
            foundElement = true;
            indexToErase = i;
        }
    }
    if (foundElement) {
        Employee* toReturn = &list_of_employees[indexToErase];
        list_of_employees.erase(list_of_employees.begin() + indexToErase);
        return toReturn;
    } else {
        return nullptr;
    }
}

