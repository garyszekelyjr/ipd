#include <iostream>
#include <string>
#include <vector>
#include "./../employee_database.h"
#include "./../arduino_code/employee.h"

using namespace std;

int main() {
    string option;
    int next_id = 0;
    EmployeeDatabase employees;
    while (true) {
        cout << "\nSetup:\n";
        cout << "(1) Demo\n";
        cout << "(2) Normal Setup\n";
        cin >> option;
        system("clear");
        if (option.compare("1") == 0) {
            employees = EmployeeDatabase();
            break;
        } else if (option.compare("2") == 0) {
            break;
        } else {
            std::cout << "\nUnrecgonized option, try again.\n\n";
        }
    }
    while (true) {
        cout << "\nOptions:\n";
        cout << "(1) View all employees\n";
        cout << "(2) View all employees in order of contamination percentage\n";
        cout << "(2) Add Employee\n";
        cout << "(3) Remove Employee by ID\n";
        cout << "(4) Remove employee by Name\n";

        cin >> option;
        system("clear");
        if (option.compare("1") == 0) {
            system("clear");
            vector<Employee> list_of_employees = employees.getEmployeeDatabase();
            if (list_of_employees.size() == 0) {
                cout << "ERROR: Database of employees empty.\n";
            } else {
                for (int i = 0; i < list_of_employees.size(); ++i) {
                    string first_name = list_of_employees[i].getFirstName();
                    string last_name = list_of_employees[i].getLastName();
                    int id = list_of_employees[i].getID();
                    cout << "First name: " << first_name << ", Last name: " << last_name << ", ID #: " << id << "\n";
                }
                cout << "\n";
            }
        } else if (option.compare("2") == 0) {
            string first_name;
            string last_name;
            cout << "Enter new employee's first name: ";
            cin >> first_name;
            cout << "Enter new employee's last name: ";
            cin >> last_name;
            system("clear");
            employees.addEmployee(Employee(next_id, first_name, last_name));
            cout << "\nAdded employee " << first_name << " " << last_name << " with ID #" << next_id << "\n";
            next_id++;
        } else if (option.compare("3") == 0) {
            int id_to_remove;
            cout << "Enter ID of employee to remove: ";
            cin >> id_to_remove;
            system("clear");
            Employee* removed_employee = employees.removeEmployeeByID(id_to_remove);
            if (removed_employee != nullptr) {
                cout << "Removed employee " << removed_employee->getFirstName() << " " << removed_employee->getLastName() << " with ID #" << removed_employee->getID() << "\n";
            } else {
                cout << "ERROR: Employee with ID #" << id_to_remove << " was not found in the database.\n";
            }
        } else if (option.compare("4") == 0) {
            string first_name_to_remove;
            string last_name_to_remove;
            cout << "Enter first name of employee to remove: ";
            cin >> first_name_to_remove;
            cout << "Enter last name of employee to remove: ";
            cin >> last_name_to_remove;
            system("clear");
            Employee* removed_employee = employees.removeEmployeeByName(first_name_to_remove, last_name_to_remove);
            if (removed_employee != nullptr) {
                cout << "Removed employee " << removed_employee->getFirstName() << " " << removed_employee->getLastName() << " with ID #" << removed_employee->getID() << "\n";
            } else {
                cout << "ERROR: Employee " << first_name_to_remove << " " << last_name_to_remove << " was not found in the database.\n";
            }
        }
    }

}