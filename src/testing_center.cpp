#include <iostream>
#include <string>
#include <fstream>
#include <stdlib.h>
#include <string.h>

using namespace std;

int main() {
    while (true) {
        system("clear");
        string option;
        cout << "Options:\n"
        << "(1) Input Test Results for Employee\n"
        << "(q) Quit\n"
        << "Command: ";
        cin >> option;
        if (option.compare("1") == 0) {
            system("clear");
            while(true) {
                fstream database("database.txt");
                ofstream temp("temp.txt");
                string selected_id;
                cout << "Enter ID # of employee to input test results: ";
                cin >> selected_id;
                bool foundElement = false;
                string line;
                string id_to_change;
                string first_name_to_change;
                string last_name_to_change;
                string contamination_level_to_change;
                while (getline(database, line)) {
                    string temp_line = line;
                    char* tok = strtok((char*)temp_line.c_str(), " ");
                    string id = (string)tok;
                    tok = strtok(NULL, " ");
                    string first_name = (string)tok;
                    tok = strtok(NULL, " ");
                    string last_name = (string)tok;
                    tok = strtok(NULL, " ");
                    tok = strtok(NULL, " ");
                    string contamination_level = (string)tok;
                    if (id.compare(selected_id) == 0) {
                        foundElement = true;
                        id_to_change = id;
                        first_name_to_change = first_name;
                        last_name_to_change = last_name;
                        contamination_level_to_change = contamination_level;
                    } else {
                        temp << line << "\n";
                    }
                }
                if (foundElement) {
                    string test_results;
                    while (true) {
                        cout << "Enter test results for employee (positive/negative): ";
                        cin >> test_results;
                        if (test_results.compare("negative") == 0 || test_results.compare("positive") == 0) {
                            break;
                        } else {
                            cout << "Unrecognized test results. Please try again.\n";
                        }
                    }
                    temp << id_to_change << " " << first_name_to_change << " " << last_name_to_change << " " << test_results << " " << contamination_level_to_change << "\n";
                    database.close();
                    temp.close();
                    remove("database.txt");
                    rename("temp.txt", "database.txt");
                    break;
                } else {
                    system("clear");
                    database.close();
                    temp.close();
                    remove("temp.txt");
                    cout << "Employee with ID #" << selected_id << " was not found in the database. Please try again.\n\n";
                }
            }
        } else if (option.compare("q") == 0 || option.compare("Q") == 0) {
            exit(EXIT_SUCCESS);
        } else {
            system("clear");
            cout << "Unrecognized option. Please try again.\n\n";
        }

    }
}