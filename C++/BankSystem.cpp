


#include <iostream>
#include <string>
using namespace std;

class BankAccount {
private:
    string ownerName;
    double balance;

public:
    // Constructor to initialize account details
    BankAccount(string name, double initialBalance) {
        ownerName = name;
        balance = initialBalance;
    }

    // Function to display current balance
    void checkBalance() {
        cout << "Current Balance: $" << balance << endl;
    }

    // Function to deposit money
    void deposit(double amount) {
        if (amount > 0) {
            balance += amount;
            cout << "Successfully deposited $" << amount << endl;
        } else {
            cout << "Invalid deposit amount!" << endl;
        }
    }

    // Function to withdraw money
    void withdraw(double amount) {
        if (amount > 0 && amount <= balance) {
            balance -= amount;
            cout << "Successfully withdrew $" << amount << endl;
        } else {
            cout << "Insufficient balance or invalid amount!" << endl;
        }
    }

    // Function to display account owner information
    void displayInfo() {
        cout << "Account Owner: " << ownerName << endl;
        checkBalance();
    }
};

int main() {
    // Create a bank account with initial details
    string name;
    double initialBalance;

    cout << "Enter your name: ";
    getline(cin, name);

    cout << "Enter initial balance: $";
    cin >> initialBalance;

    BankAccount myAccount(name, initialBalance);

    int choice;
    double amount;

    // Simple menu-driven program
    do {
        cout << "\n--- Bank Management System ---\n";
        cout << "1. Check Balance\n";
        cout << "2. Deposit Money\n";
        cout << "3. Withdraw Money\n";
        cout << "4. Display Account Info\n";
        cout << "5. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                myAccount.checkBalance();
                break;
            case 2:
                cout << "Enter amount to deposit: $";
                cin >> amount;
                myAccount.deposit(amount);
                break;
            case 3:
                cout << "Enter amount to withdraw: $";
                cin >> amount;
                myAccount.withdraw(amount);
                break;
            case 4:
                myAccount.displayInfo();
                break;
            case 5:
                cout << "Thank you for using the Bank Management System. Goodbye!" << endl;
                break;
            default:
                cout << "Invalid choice! Please try again." << endl;
        }
    } while (choice != 5);

    return 0;
}
