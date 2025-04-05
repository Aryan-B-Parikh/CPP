#include <iostream>
#include <string>

using namespace std;

class InventoryItem {
private:
    string itemId;
    string itemName;
    double price;
    int quantityInStock;

public:
    InventoryItem(string id, string name, double p, int quantity)
        : itemId(id), itemName(name), price(p), quantityInStock(quantity) {}

    InventoryItem() : itemId("N/A"), itemName("N/A"), price(0.0), quantityInStock(0) {}

    string getItemId() const { return itemId; }
    string getItemName() const { return itemName; }
    double getPrice() const { return price; }
    int getQuantityInStock() const { return quantityInStock; }

    void setPrice(double p) { price = p; }

    void increaseStock(int quantity) {
        if (quantity > 0) {
            quantityInStock += quantity;
            cout << "Added " << quantity << " units of " << itemName << ". New stock: " << quantityInStock << endl;
        } else {
            cout << "Invalid quantity to add." << endl;
        }
    }

    void decreaseStock(int quantity) {
        if (quantity > 0) {
            if (quantityInStock >= quantity) {
                quantityInStock -= quantity;
                cout << "Sold " << quantity << " units of " << itemName << ". Remaining stock: " << quantityInStock << endl;
            } else {
                cout << "Insufficient stock for " << itemName << ". Available: " << quantityInStock << ", requested: " << quantity << endl;
            }
        } else {
            cout << "Invalid quantity to sell." << endl;
        }
    }

    void displayItemSummary() const {
        cout << "\n--- Item Summary ---" << endl;
        cout << "Item ID: " << itemId << endl;
        cout << "Name: " << itemName << endl;
        cout << "Price: $" << price << endl;
        cout << "Quantity in Stock: " << quantityInStock << endl;
        cout << "--------------------" << endl;
    }
};

int main() {
    const int MAX_ITEMS = 50;
    InventoryItem inventory[MAX_ITEMS];
    int itemCount = 0;

    int choice;
    do {
        cout << "\n--- Inventory Management System ---" << endl;
        cout << "1. Add New Item" << endl;
        cout << "2. Increase Stock" << endl;
        cout << "3. Sell Item (Decrease Stock)" << endl;
        cout << "4. Display Item Summary" << endl;
        cout << "5. Display All Items" << endl;
        cout << "0. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;
        cin.ignore();

        switch (choice) {
            case 1:
                if (itemCount < MAX_ITEMS) {
                    string id, name;
                    double price;
                    int quantity;

                    cout << "\nEnter details for the new item:" << endl;
                    cout << "Item ID: ";
                    getline(cin, id);
                    cout << "Item Name: ";
                    getline(cin, name);
                    cout << "Price: $";
                    cin >> price;
                    cout << "Quantity in Stock: ";
                    cin >> quantity;

                    inventory[itemCount] = InventoryItem(id, name, price, quantity);
                    itemCount++;
                    cout << "Item added successfully." << endl;
                } else {
                    cout << "Inventory is full. Cannot add more items." << endl;
                }
                break;

            case 2: {
                string idToIncrease;
                int quantityToIncrease;
                cout << "\nEnter Item ID to increase stock: ";
                getline(cin, idToIncrease);
                cout << "Enter quantity to add: ";
                cin >> quantityToIncrease;
                bool found = false;
                for (int i = 0; i < itemCount; ++i) {
                    if (inventory[i].getItemId() == idToIncrease) {
                        inventory[i].increaseStock(quantityToIncrease);
                        found = true;
                        break;
                    }
                }
                if (!found) {
                    cout << "Item with ID '" << idToIncrease << "' not found." << endl;
                }
                break;
            }

            case 3: {
                string idToSell;
                int quantityToSell;
                cout << "\nEnter Item ID to sell: ";
                getline(cin, idToSell);
                cout << "Enter quantity to sell: ";
                cin >> quantityToSell;
                bool found = false;
                for (int i = 0; i < itemCount; ++i) {
                    if (inventory[i].getItemId() == idToSell) {
                        inventory[i].decreaseStock(quantityToSell);
                        found = true;
                        break;
                    }
                }
                if (!found) {
                    cout << "Item with ID '" << idToSell << "' not found." << endl;
                }
                break;
            }

            case 4: {
                string idToDisplay;
                cout << "\nEnter Item ID to display summary: ";
                getline(cin, idToDisplay);
                bool found = false;
                for (int i = 0; i < itemCount; ++i) {
                    if (inventory[i].getItemId() == idToDisplay) {
                        inventory[i].displayItemSummary();
                        found = true;
                        break;
                    }
                }
                if (!found) {
                    cout << "Item with ID '" << idToDisplay << "' not found." << endl;
                }
                break;
            }

            case 5:
                cout << "\n--- Current Inventory ---" << endl;
                if (itemCount > 0) {
                    for (int i = 0; i < itemCount; ++i) {
                        inventory[i].displayItemSummary();
                    }
                } else {
                    cout << "Inventory is empty." << endl;
                }
                break;

            case 0:
                cout << "Exiting Inventory Management System. Goodbye!" << endl;
                break;

            default:
                cout << "Invalid choice. Please try again." << endl;
        }
    } while (choice != 0);

    return 0;
}