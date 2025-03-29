#include <iostream>
#include <vector>
#include <map>
using namespace std;

class Person {
protected:
    string name;
    int age;
public:
    Person(string n, int a) : name(n), age(a) {}
    void displayPerson() const {
        cout << "Name: " << name << ", Age: " << age << endl;
    }
};

class Employee : public Person {
protected:
    int empID;
public:
    Employee(string n, int a, int id) : Person(n, a), empID(id) {}
    void displayEmployee() const {
        displayPerson();
        cout << "Employee ID: " << empID << endl;
    }
    int getEmpID() const {
        return empID;
    }
};

class Manager : public Employee {
private:
    string department;
public:
    Manager() : Employee("", 0, 0), department("") {}
    Manager(string n, int a, int id, string dept)
        : Employee(n, a, id), department(dept) {}
    void displayManager() const {
        displayEmployee();
        cout << "Department: " << department << endl;
    }
};

void staticApproach(int n) {
    Manager managers[100];
    string name, dept;
    int age, empID;

    cout << "\nStatic Approach: Enter details for " << n << " managers:\n";
    for (int i = 0; i < n; i++) {
        cin >> name >> age >> empID >> dept;
        managers[i] = Manager(name, age, empID, dept);
    }

    cout << "\nManager Details:\n";
    for (int i = 0; i < n; i++) {
        managers[i].displayManager();
        cout << endl;
    }
}

void dynamicApproach(int n) {
    map<int, Manager> managerMap;
    string name, dept;
    int age, empID;

    cout << "\nDynamic Approach: Enter details for " << n << " managers:\n";
    for (int i = 0; i < n; i++) {
        cin >> name >> age >> empID >> dept;
        managerMap[empID] = Manager(name, age, empID, dept);
    }

    cout << "\nManager Details:\n";
    for (auto it : managerMap) {
        it.second.displayManager();
        cout << endl;
    }
}

int main() {
    int n, choice;

    cout << "Enter the number of managers: ";
    cin >> n;

    if (n <= 0) {
        cout << "Number of managers must be greater than 0!" << endl;
        return 1;
    }

    cout << "Choose approach:\n1. Static (Fixed-size Array)\n2. Dynamic (Map for Retrieval)\n";
    cin >> choice;

    if (choice == 1) {
        staticApproach(n);
    } else if (choice == 2) {
        dynamicApproach(n);
    } else {
        cout << "Invalid choice!" << endl;
    }

    return 0;
}
