#include <iostream>
#include <string>

using namespace std;


const int MAX_PRODUCTS = 100;


struct Product {
    int id;
    string name;
    int quantity;
    double price;
};


Product store[MAX_PRODUCTS];
int productCount = 0;
void addProduct(int id, const string& name, int quantity, double price) {
    if (productCount < MAX_PRODUCTS)
    {
        store[productCount].id = id;
        store[productCount].name = name;
        store[productCount].quantity = quantity;
        store[productCount].price = price;
        productCount++;
    } else
    {
        cout << "store full! Cannot add more products." << endl;
    }
}


void updateQuantity(int id, int quantity)
 {
    for (int i = 0; i < productCount; i++)
    {
        if (store[i].id == id)
        {
            store[i].quantity += quantity;
            return;
        }
    }
    cout << "Product not found!" << endl;
}


double calculateTotalValue()
 {
    double totalValue = 0;
    for (int i = 0; i < productCount; i++)
        {
        totalValue += store[i].quantity * store[i].price;
        }
    return totalValue;
}


int main()
 {
    addProduct(1, "Laptop", 10, 1000);
    addProduct(2, "Phone", 5, 500);
    addProduct(3,"charger",2,200);
    updateQuantity(1, 5);

    cout << "Total value of inventory in order : " << calculateTotalValue() << endl;

    return 0;
}