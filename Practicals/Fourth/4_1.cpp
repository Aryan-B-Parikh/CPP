#include <iostream>
#include <vector>
using namespace std;

class Shape {
protected:
    double radius;
public:
    Shape(double r) : radius(r) {}
    double getRadius() const {
        return radius;
    }
};

class Circle : public Shape {
    public:
        Circle() : Shape(0) {}  
        Circle(double r) : Shape(r) {}
        double calculateArea() const {
            return 3.14159 * radius * radius;
        }
    };
    

void staticApproach(int n) {
    Circle* circles = new Circle[n];
    double radius;

    cout << "\nStatic Approach: Enter radii of " << n << " circles:\n";
    for (int i = 0; i < n; i++) {
        cin >> radius;
        circles[i] = Circle(radius);
    }

    cout << "Areas of circles:\n";
    for (int i = 0; i < n; i++) {
        cout << "Circle " << i + 1 << " Area: " << circles[i].calculateArea() << endl;
    }

    delete[] circles; 
}
void dynamicApproach(int n) {
    vector<Circle> circles;
    double radius;

    cout << "\nDynamic Approach: Enter radii of " << n << " circles:\n";
    for (int i = 0; i < n; i++) {
        cin >> radius;
        circles.push_back(Circle(radius));
    }

    cout << "Areas of circles:\n";
    for (int i = 0; i < n; i++) {
        cout << "Circle " << i + 1 << " Area: " << circles[i].calculateArea() << endl;
    }
}

int main() {
    int n, choice;

    cout << "Enter number of circles: ";
    cin >> n;

    if (n <= 0) {
        cout << "Number of circles must be greater than 0!" << endl;
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
