#include <iostream>
#include <vector>
using namespace std;

class Fuel {
protected:
    string fuelType;
public:
    Fuel(string fuel) : fuelType(fuel) {}
    void displayFuel() const {
        cout << "Fuel Type: " << fuelType << endl;
    }
};

class Brand {
protected:
    string brandName;
public:
    Brand(string brand) : brandName(brand) {}
    void displayBrand() const {
        cout << "Brand Name: " << brandName << endl;
    }
};

class Car : public Fuel, public Brand {
public:
    Car() : Fuel("Unknown"), Brand("Unknown") {} // Default constructor
    Car(string fuel, string brand) : Fuel(fuel), Brand(brand) {}
    void displayCar() const {
        displayBrand();
        displayFuel();
    }
};

void staticApproach(int n) {
    Car cars[100];
    string fuel, brand;

    cout << "\nStatic Approach: Enter details for " << n << " cars:\n";
    for (int i = 0; i < n; i++) {
        cout << "Enter fuel type and brand name for Car " << i + 1 << ": ";
        cin >> fuel >> brand;
        cars[i] = Car(fuel, brand);
    }

    cout << "\nCar Details:\n";
    for (int i = 0; i < n; i++) {
        cout << "Car " << i + 1 << ":\n";
        cars[i].displayCar();
        cout << endl;
    }
}

void dynamicApproach(int n) {
    vector<Car> carList;
    string fuel, brand;

    cout << "\nDynamic Approach: Enter details for " << n << " cars:\n";
    for (int i = 0; i < n; i++) {
        cout << "Enter fuel type and brand name for Car " << i + 1 << ": ";
        cin >> fuel >> brand;
        carList.push_back(Car(fuel, brand));
    }

    cout << "\nCar Details:\n";
    for (int i = 0; i < n; i++) {
        cout << "Car " << i + 1 << ":\n";
        carList[i].displayCar();
        cout << endl;
    }
}

int main() {
    int n, choice;

    cout << "Enter the number of cars: ";
    cin >> n;

    if (n <= 0) {
        cout << "Number of cars must be greater than 0!" << endl;
        return 1;
    }

    cout << "Choose approach:\n1. Static (Fixed-size Array)\n2. Dynamic (Vector)\n";
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
