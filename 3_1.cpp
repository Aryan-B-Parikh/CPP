#include <iostream>
#include <string>

using namespace std;

class Employee {
private:
    string name;
    double basicSalary;
    double bonus;

    inline double calculateTotalSalary() const {
        return basicSalary + bonus;
    }

public:
    Employee(string n, double salary, double b = 1000.0) : name(n), basicSalary(salary), bonus(b) {}

    string getEmployeeName() const {
        return name;
    }

    void displayDetails() const {
        cout << "\n--- Employee Details ---" << endl;
        cout << "Name: " << name << endl;
        cout << "Basic Salary: $" << basicSalary << endl;
        cout << "Bonus: $" << bonus << endl;
        cout << "Total Salary: $" << calculateTotalSalary() << endl;
        cout << "------------------------" << endl;
    }

    void setBonus(double newBonus) {
        bonus = newBonus;
    }
};

int main() {
    const int MAX_EMPLOYEES = 50; // Define a maximum number of employees
    Employee employees[MAX_EMPLOYEES];
    int employeeCount = 0;

    int choice;
    do {
        cout << "\n--- Payroll Management System ---" << endl;
        cout << "1. Add New Employee" << endl;
        cout << "2. Display Employee Details" << endl;
        cout << "3. Set Custom Bonus" << endl;
        cout << "0. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;
        cin.ignore();

        switch (choice) {
            case 1:
                if (employeeCount < MAX_EMPLOYEES) {
                    string name;
                    double basicSalary;
                    double bonus;
                    char customBonusChoice;

                    cout << "\nEnter Employee Name: ";
                    getline(cin, name);
                    cout << "Enter Basic Salary: $";
                    cin >> basicSalary;
                    cout << "Apply default bonus of $1000? (y/n): ";
                    cin >> customBonusChoice;

                    if (tolower(customBonusChoice) == 'n') {
                        cout << "Enter Custom Bonus Amount: $";
                        cin >> bonus;
                        employees[employeeCount] = Employee(name, basicSalary, bonus);
                    } else {
                        employees[employeeCount] = Employee(name, basicSalary);
                    }
                    employeeCount++;
                    cout << "Employee added successfully." << endl;
                } else {
                    cout << "Employee database is full." << endl;
                }
                break;

            case 2: {
                if (employeeCount == 0) {
                    cout << "No employee records available." << endl;
                    break;
                }
                cout << "\n--- All Employee Details ---" << endl;
                for (int i = 0; i < employeeCount; ++i) {
                    employees[i].displayDetails();
                }
                break;
            }

            case 3: {
                if (employeeCount == 0) {
                    cout << "No employee records available." << endl;
                    break;
                }
                string nameToUpdate;
                double newBonus;
                cout << "Enter the name of the employee to update bonus: ";
                getline(cin, nameToUpdate);
                bool found = false;
                for (int i = 0; i < employeeCount; ++i) {
                    if (employees[i].getEmployeeName() == nameToUpdate) {
                        cout << "Enter the new bonus amount for " << nameToUpdate << ": $";
                        cin >> newBonus;
                        employees[i].setBonus(newBonus);
                        cout << "Bonus updated successfully for " << nameToUpdate << "." << endl;
                        found = true;
                        break;
                    }
                }
                if (!found) {
                    cout << "Employee with name '" << nameToUpdate << "' not found." << endl;
                }
                break;
            }

            case 0:
                cout << "Exiting Payroll Management System. Goodbye!" << endl;
                break;

            default:
                cout << "Invalid choice. Please try again." << endl;
        }
    } while (choice != 0);

    return 0;
}