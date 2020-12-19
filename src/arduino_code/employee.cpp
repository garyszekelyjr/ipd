#include <string>
#include "employee.h"

Employee::Employee(int id, std::string first_name, std::string last_name) {
    this->id = id;
    this->first_name = first_name;
    this->last_name = last_name;
    date = "";
    test_results = false;
    contamination_percentage = 0.0;
}

void Employee::setDate(std::string date) {
    this->date = date;
}

void Employee::setTestResults(bool test_results) {
    this->test_results = test_results;
}

void Employee::setContaminationPercentage(double contamination_percentage) {
    this->contamination_percentage = contamination_percentage;
}

int Employee::getID() {
    return id;
}

std::string Employee::getFirstName() {
    return first_name;
}

std::string Employee::getLastName() {
    return last_name;
}

std::string Employee::getDate() {
    return date;
}

bool Employee::getTestResults() {
    return test_results;
}

double Employee::getContaminationPercentage() {
    return contamination_percentage;
}