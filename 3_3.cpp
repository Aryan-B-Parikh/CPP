#include <iostream>
#include <string>

using namespace std;

class BankAccount {
private:
    string accountNumber;
    string accountHolder;
    double balance;

public:
    BankAccount(string number, string holder, double initialBalance = 0.0)
        : accountNumber(number), accountHolder(holder), balance(initialBalance) {}

    string getAccountNumber() const {
        return accountNumber;
    }

    string getAccountHolder() const {
        return accountHolder;
    }

    double getBalance() const {
        return balance;
    }

    void deposit(double amount) {
        if (amount > 0) {
            balance += amount;
            cout << "Deposit of $" << amount << " successful. New balance: $" << balance << endl;
        } else {
            cout << "Invalid deposit amount." << endl;
        }
    }

    void withdraw(double amount) {
        if (amount > 0) {
            if (balance >= amount) {
                balance -= amount;
                cout << "Withdrawal of $" << amount << " successful. New balance: $" << balance << endl;
            } else {
                cout << "Insufficient funds." << endl;
            }
        } else {
            cout << "Invalid withdrawal amount." << endl;
        }
    }

    void displayAccountInfo() const {
        cout << "Account Number: " << accountNumber << endl;
        cout << "Account Holder: " << accountHolder << endl;
        cout << "Balance: $" << balance << endl;
    }
};

class Bank {
private:
    static const int MAX_ACCOUNTS = 50;
    BankAccount accounts[MAX_ACCOUNTS];
    int totalAccounts;

public:
    Bank() : totalAccounts(0) {}

    void createAccount(string accountNumber, string accountHolder, double initialBalance = 0.0) {
        if (totalAccounts < MAX_ACCOUNTS) {
            for (int i = 0; i < totalAccounts; ++i) {
                if (accounts[i].getAccountNumber() == accountNumber) {
                    cout << "Account number already exists." << endl;
                    return;
                }
            }
            accounts[totalAccounts] = BankAccount(accountNumber, accountHolder, initialBalance);
            totalAccounts++;
            cout << "Account created successfully." << endl;
        } else {
            cout << "Maximum number of accounts reached." << endl;
        }
    }

    BankAccount* findAccount(string accountNumber) {
        for (int i = 0; i < totalAccounts; ++i) {
            if (accounts[i].getAccountNumber() == accountNumber) {
                return &accounts[i];
            }
        }
        return nullptr;
    }

    void transferMoney(string fromAccountNumber, string toAccountNumber, double amount) {
        if (amount <= 0) {
            cout << "Invalid transfer amount." << endl;
            return;
        }

        BankAccount* fromAccount = findAccount(fromAccountNumber);
        BankAccount* toAccount = findAccount(toAccountNumber);

        if (!fromAccount || !toAccount) {
            cout << "Invalid account number(s)." << endl;
            return;
        }

        if (fromAccount->getBalance() >= amount) {
            fromAccount->withdraw(amount);
            toAccount->deposit(amount);
            cout << "Transfer of $" << amount << " from account " << fromAccountNumber << " to " << toAccountNumber << " successful." << endl;
        } else {
            cout << "Insufficient funds in account " << fromAccountNumber << " for transfer." << endl;
        }
    }

    void displayAccountDetails(string accountNumber) {
        BankAccount* account = findAccount(accountNumber);
        if (account) {
            account->displayAccountInfo();
        } else {
            cout << "Account not found." << endl;
        }
    }

    int getTotalAccounts() const {
        return totalAccounts;
    }
};

int main() {
    Bank communityBank;
    int choice;

    do {
        cout << "\n--- Community Bank System ---" << endl;
        cout << "1. Create New Account" << endl;
        cout << "2. Deposit Money" << endl;
        cout << "3. Withdraw Money" << endl;
        cout << "4. Transfer Money" << endl;
        cout << "5. Display Account Details" << endl;
        cout << "6. Get Total Number of Accounts" << endl;
        cout << "0. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;
        cin.ignore();

        string accountNumber, accountHolder, fromAccount, toAccount;
        double amount, initialBalance;

        switch (choice) {
            case 1:
                cout << "Enter Account Number: ";
                getline(cin, accountNumber);
                cout << "Enter Account Holder Name: ";
                getline(cin, accountHolder);
                cout << "Enter Initial Balance (optional, default is 0): $";
                string balanceInput;
                getline(cin, balanceInput);
                if (!balanceInput.empty()) {
                    initialBalance = stod(balanceInput);
                } else {
                    initialBalance = 0.0;
                }
                communityBank.createAccount(accountNumber, accountHolder, initialBalance);
                break;

            case 2:
                cout << "Enter Account Number to Deposit: ";
                getline(cin, accountNumber);
                cout << "Enter Deposit Amount: $";
                cin >> amount;
                cin.ignore();
                if (BankAccount* acc = communityBank.findAccount(accountNumber)) {
                    acc->deposit(amount);
                } else {
                    cout << "Account not found." << endl;
                }
                break;

            case 3:
                cout << "Enter Account Number to Withdraw: ";
                getline(cin, accountNumber);
                cout << "Enter Withdrawal Amount: $";
                cin >> amount;
                cin.ignore();
                if (BankAccount* acc = communityBank.findAccount(accountNumber)) {
                    acc->withdraw(amount);
                } else {
                    cout << "Account not found." << endl;
                }
                break;

            case 4:
                cout << "Enter Account Number to Transfer From: ";
                getline(cin, fromAccount);
                cout << "Enter Account Number to Transfer To: ";
                getline(cin, toAccount);
                cout << "Enter Transfer Amount: $";
                cin >> amount;
                cin.ignore();
                communityBank.transferMoney(fromAccount, toAccount, amount);
                break;

            case 5:
                cout << "Enter Account Number to Display Details: ";
                getline(cin, accountNumber);
                communityBank.displayAccountDetails(accountNumber);
                break;

            case 6:
                cout << "Total Number of Accounts: " << communityBank.getTotalAccounts() << endl;
                break;

            case 0:
                cout << "Exiting Bank System. Goodbye!" << endl;
                break;

            default:
                cout << "Invalid choice. Please try again." << endl;
        }
    } while (choice != 0);

    return 0;
}