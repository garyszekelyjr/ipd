#include <iostream>
#include <string>
#include <fstream>
#include <stdlib.h>
#include <string.h>

using namespace std;

void viewAllEmployees();
void viewEmployeesAboveCP(int threshold);
void viewEmployeesByTR(string test_result);
void addEmployee(string first_name, string last_name);
void removeByID(string id_to_remove);
void removeByName(string first_name_to_remove, string last_name_to_remove);

static int next_id = 0;

int main() {
    string option;
    system("clear");
    while (true) {
        cout << "Setup:\n";
        cout << "(1) Demo\n";
        cout << "(2) Normal Setup\n";
        cout << "Command: ";
        cin >> option;
        system("clear");
        if (option.compare("1") == 0) {
            fstream database("database.txt");
            database << "0 Gary Szekely negative 40%\n";
            database << "1 Paige Ruschke positive 0%\n";
            database << "2 Mary Shelley negative 80%\n";
            database << "3 Fernando Fernandez negative 20%\n";
            database << "4 Rick James positive 3%\n";
            database << "5 Michael Jackson negative 45%\n";
            database << "6 Bradley Cooper positive 54%\n";
            next_id = 7;
            database.close();
            break;
        } else if (option.compare("2") == 0) {
            break;
        } else {
            cout << "\nUnrecgonized option, please try again.\n\n";
        }
    }
    while (true) {
        cout << "Options:\n"
        << "(1) View All Employees\n"
        << "(2) View All Employees by Contamination Threshold\n"
        << "(3) View All Employees by COVID Test Result\n"
        << "(4) Add Employee\n"
        << "(5) Remove Employee by ID\n"
        << "(6) Remove employee by Name\n"
        << "(q) Quit\n"
        << "Command: ";
        cin >> option;
        system("clear");
        if (option.compare("1") == 0) {
            system("clear");
            viewAllEmployees();
        } else if (option.compare("2") == 0) {
            system("clear");
            int threshold;
            cout << "Enter contamination threshold: ";
            cin >> threshold;
            system("clear");
            viewEmployeesAboveCP(threshold);
        } else if (option.compare("3") == 0) {
            system("clear");
            string desired_test_result;
            while (true) {
                cout << "Enter p for postive test results or n for negative test results: ";
                cin >> desired_test_result;
                if (desired_test_result.compare("p") == 0 || desired_test_result.compare("P") == 0 || desired_test_result.compare("n") == 0 || desired_test_result.compare("N") == 0) {
                    break;
                } else {
                    cout << "Unrecognized option. Please try again.\n\n";
                }
            }
            system("clear");
            viewEmployeesByTR(desired_test_result);
        } else if (option.compare("4") == 0) {
            system("clear");
            string first_name;
            string last_name;
            cout << "Enter new employee's first name: ";
            cin >> first_name;
            cout << "Enter new employee's last name: ";
            cin >> last_name;
            system("clear");
            addEmployee(first_name, last_name);
        } else if (option.compare("5") == 0) {
            system("clear");
            string id_to_remove;
            cout << "Enter ID of employee to remove: ";
            cin >> id_to_remove;
            removeByID(id_to_remove);
        } else if (option.compare("6") == 0) {
            system("clear");
            string first_name_to_remove;
            string last_name_to_remove;
            cout << "Enter first name of employee to remove: ";
            cin >> first_name_to_remove;
            cout << "Enter last name of employee to remove: ";
            cin >> last_name_to_remove;
            system("clear");
            removeByName(first_name_to_remove, last_name_to_remove);
        } else if (option.compare("q") == 0 || option.compare("Q") == 0) {
            exit(EXIT_SUCCESS);
        } else {
            system("clear");
            cout << "Unrecognized option. Please try again.\n\n";
        }
    }

}

void viewAllEmployees() {
    fstream database("database.txt");
    string line;
    int num_employees = 0;
    getline(database, line);
    if (line.length() == 0) {
        cout << "ERROR: Database of employees empty.\n\n";
    } else {
        num_employees++;
        char* tok = strtok((char*)line.c_str(), " ");
        string id = (string)tok;
        tok = strtok(NULL, " ");
        string first_name = (string)tok;
        tok = strtok(NULL, " ");
        string last_name = (string)tok;
        tok = strtok(NULL, " ");
        string test_results = (string)tok;
        tok = strtok(NULL, " ");
        string contamination_level = (string)tok;
        cout << "ID #: " << id << "\n"
            << "First Name: " << first_name << "\n"
            << "Last Name: " << last_name << "\n"
            << "COVID Test Results: " << test_results << "\n"
            << "Contamination Percentage: " << contamination_level << "\n\n";
        while (getline(database, line)) {
            char* tok = strtok((char*)line.c_str(), " ");
            string id = (string)tok;
            tok = strtok(NULL, " ");
            string first_name = (string)tok;
            tok = strtok(NULL, " ");
            string last_name = (string)tok;
            tok = strtok(NULL, " ");
            string test_results = (string)tok;
            tok = strtok(NULL, " ");
            string contamination_level = (string)tok;
            cout << "ID #: " << id << "\n"
                << "First Name: " << first_name << "\n"
                << "Last Name: " << last_name << "\n"
                << "COVID Test Results: " << test_results << "\n"
                << "Contamination Percentage: " << contamination_level << "\n\n";
            num_employees++;
        }
    }
    cout << "Number of employees: " << num_employees << "\n\n";
    database.close();
}

void viewEmployeesAboveCP(int threshold) {
    fstream database("database.txt");
    string line;
    bool foundElement = false;
    int num_found = 0;
    while (getline(database, line)) {
        char* tok = strtok((char*)line.c_str(), " ");
        string id = (string)tok;
        tok = strtok(NULL, " ");
        string first_name = (string)tok;
        tok = strtok(NULL, " ");
        string last_name = (string)tok;
        tok = strtok(NULL, " ");
        string test_results = (string)tok;
        tok = strtok(NULL, " ");
        string contamination_level = (string)tok;
        contamination_level.pop_back();
        if (stoi(contamination_level) >= threshold) {
            foundElement = true;
            cout << "ID #: " << id << "\n"
            << "First Name: " << first_name << "\n"
            << "Last Name: " << last_name << "\n"
            << "COVID Test Results: " << test_results << "\n"
            << "Contamination Percentage: " << contamination_level << "%\n\n";
            num_found++;
        }
    }
    if (!foundElement) {
        cout << "ERROR: No employees match specifications.\n\n";
    } else {
        cout << "Number of matching employees: " << num_found << "\n\n";
    }
    database.close();
}

void viewEmployeesByTR(string desired_test_result) {
    fstream database("database.txt");
    string line;
    bool foundElement = false;
    int num_found = 0;
    if (desired_test_result.compare("p") == 0) {
        desired_test_result = "positive";
    } else {
        desired_test_result = "negative";
    }
    while (getline(database, line)) {
        char* tok = strtok((char*)line.c_str(), " ");
        string id = (string)tok;
        tok = strtok(NULL, " ");
        string first_name = (string)tok;
        tok = strtok(NULL, " ");
        string last_name = (string)tok;
        tok = strtok(NULL, " ");
        string test_results = (string)tok;
        tok = strtok(NULL, " ");
        string contamination_level = (string)tok;
        contamination_level.pop_back();
        if (test_results.compare(desired_test_result) == 0) {
            foundElement = true;
            cout << "ID #: " << id << "\n"
            << "First Name: " << first_name << "\n"
            << "Last Name: " << last_name << "\n"
            << "COVID Test Results: " << test_results << "\n"
            << "Contamination Percentage: " << contamination_level << "%\n\n";
            num_found++;
        }
    }
    if (!foundElement) {
        cout << "ERROR: No employees match specifications.\n\n";
    } else {
        cout << "Number of matching employees: " << num_found << "\n\n";
    }
    database.close();
}

void addEmployee(string first_name, string last_name) {
    fstream database("database.txt");
    database.seekp(0, ios::end);
    database << next_id << " " << first_name << " " << last_name << " negative 0%\n";
    cout << "Added the following employee:\n\n"
        << "ID #: " << next_id++ << "\n"
        << "First Name: " << first_name << "\n"
        << "Last Name: " << last_name << "\n\n";
    database.close();
}

void removeByID(string id_to_remove) {
    fstream database("database.txt");
    ofstream temp("temp.txt");
    bool foundElement = false;
    string line;
    string id;
    string first_name;
    string last_name;
    string removed_id;
    string removed_first_name;
    string removed_last_name;
    while (getline(database, line)) {
        string temp_line = line;
        char* tok = strtok((char*)temp_line.c_str(), " ");
        id = (string)tok;
        tok = strtok(NULL, " ");
        first_name = (string)tok;
        tok = strtok(NULL, " ");
        last_name = (string)tok;
        if (id.compare(id_to_remove) == 0) {
            foundElement = true;
            removed_id = id;
            removed_first_name = first_name;
            removed_last_name = last_name;
        } else {
            temp << line << "\n";
        }
    }
    remove("database.txt");
    database.close();
    rename("temp.txt", "database.txt");
    temp.close();
    system("clear");
    if (foundElement) {
        cout << "Removed the following employee:\n\n"
        << "ID #: " << removed_id << "\n"
        << "First Name: " << removed_first_name << "\n"
        << "Last Name: " << removed_last_name << "\n\n";
    } else {
        cout << "ERROR: Employee with ID #" << id_to_remove << " was not found in the database.\n\n";
    }
}

void removeByName(string first_name_to_remove, string last_name_to_remove) {
    fstream database("database.txt");
    ofstream temp("temp.txt");
    bool foundElement = false;
    string line;
    string id;
    string first_name;
    string last_name;
    string removed_id;
    string removed_first_name;
    string removed_last_name;
    while (getline(database, line)) {
        string temp_line = line;
        char* tok = strtok((char*)temp_line.c_str(), " ");
        id = (string)tok;
        tok = strtok(NULL, " ");
        first_name = (string)tok;
        tok = strtok(NULL, " ");
        last_name = (string)tok;
        if (first_name.compare(first_name_to_remove) == 0 && last_name.compare(last_name_to_remove) == 0) {
            foundElement = true;
            removed_id = id;
            removed_first_name = first_name;
            removed_last_name = last_name;
        } else {
            temp << line << "\n";
        }
    }
    remove("database.txt");
    database.close();
    rename("temp.txt", "database.txt");
    temp.close();
    if (foundElement) {
        cout << "Removed the following employee:\n\n"
        << "ID #: " << removed_id << "\n"
        << "First Name: " << removed_first_name << "\n"
        << "Last Name: " << removed_last_name << "\n\n";
    } else {
        cout << "ERROR: Employee with name " << first_name_to_remove << " " << last_name_to_remove << " was not found in the database.\n\n";
    }
}