#ifndef EMPLOYEE_H
#define EMPLOYEE_H

#include <string>

class Employee {
    private:
        int id;
        std::string first_name;
        std::string last_name;
        std::string date;
        bool test_results;
        double contamination_percentage;
    public:
        Employee(int id, std::string first_name, std::string last_name);

        void setDate(std::string date);
        void setTestResults(bool test_results);
        void setContaminationPercentage(double contamination_percentage);

        int getID();
        std::string getFirstName();
        std::string getLastName();
        std::string getDate();
        bool getTestResults();
        double getContaminationPercentage();
};

#endif