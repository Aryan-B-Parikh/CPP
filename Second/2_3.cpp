#include <iostream>
#include <string>

using namespace std;

class BankAccount {
private:
    string accountHolder;
    string accountNumber;
    double balance;

public:
    BankAccount(string holder, string number, double initialBalance)
        : accountHolder(holder), accountNumber(number), balance(initialBalance) {}

    BankAccount(string holder, string number)
        : accountHolder(holder), accountNumber(number), balance(0.0) {}

    string getAccountHolder() const {
        return accountHolder;
    }

    string getAccountNumber() const {
        return accountNumber;
    }

    double getBalance() const {
        return balance;
    }

    void deposit(double amount) {
        if (amount > 0) {
            balance += amount;
            cout << "Deposit of $" << amount << " successful. New balance: $" << balance << endl;
        } else {
            cout << "Invalid deposit amount. Please enter a positive value." << endl;
        }
    }

    void withdraw(double amount) {
        if (amount > 0) {
            if (balance >= amount) {
                balance -= amount;
                cout << "Withdrawal of $" << amount << " successful. New balance: $" << balance << endl;
            } else {
                cout << "Insufficient funds. Current balance: $" << balance << endl;
            }
        } else {
            cout << "Invalid withdrawal amount. Please enter a positive value." << endl;
        }
    }

    void displayAccountSummary() const {
        cout << "\n--- Account Summary ---" << endl;
        cout << "Account Holder: " << accountHolder << endl;
        cout << "Account Number: " << accountNumber << endl;
        cout << "Current Balance: $" << balance << endl;
        cout << "-----------------------" << endl;
    }
};

int main() {
    string holder, number;
    double initialBalance, depositAmount, withdrawAmount;

    cout << "--- Create Account 1 ---" << endl;
    cout << "Enter Account Holder Name: ";
    getline(cin >> ws, holder);
    cout << "Enter Account Number: ";
    getline(cin >> ws, number);
    cout << "Enter Initial Balance: $";
    cin >> initialBalance;
    BankAccount account1(holder, number, initialBalance);
    account1.displayAccountSummary();

    cout << "\n--- Create Account 2 (No Initial Balance) ---" << endl;
    cout << "Enter Account Holder Name: ";
    getline(cin >> ws, holder);
    cout << "Enter Account Number: ";
    getline(cin >> ws, number);
    BankAccount account2(holder, number);
    account2.displayAccountSummary();

    cout << "\n--- Deposit to Account 1 ---" << endl;
    cout << "Enter Deposit Amount: $";
    cin >> depositAmount;
    account1.deposit(depositAmount);
    account1.displayAccountSummary();

    cout << "\n--- Deposit to Account 2 ---" << endl;
    cout << "Enter Deposit Amount: $";
    cin >> depositAmount;
    account2.deposit(depositAmount);
    account2.displayAccountSummary();

    cout << "\n--- Withdraw from Account 1 ---" << endl;
    cout << "Enter Withdrawal Amount: $";
    cin >> withdrawAmount;
    account1.withdraw(withdrawAmount);
    account1.displayAccountSummary();

    cout << "\n--- Withdraw from Account 2 ---" << endl;
    cout << "Enter Withdrawal Amount: $";
    cin >> withdrawAmount;
    account2.withdraw(withdrawAmount);
    account2.displayAccountSummary();

    return 0;
}