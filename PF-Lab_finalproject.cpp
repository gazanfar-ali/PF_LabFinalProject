#include <iostream>
#include <string>
using namespace std;

const int MAX_ACCOUNTS = 100;

struct Account {
    string accountNumber;
    string accountHolderName;
    double balance;
};

void createAccount(Account accounts[], int &numAccounts) {
    if (numAccounts >= MAX_ACCOUNTS) {
        cout << "Maximum number of accounts reached.\n";
        return;
    }
    
    Account newAccount;
    cout << "Enter Account Number: ";
    cin >> newAccount.accountNumber;
    cout << "Enter Account Holder Name: ";
    cin.ignore(); // To ignore the newline character left by previous input
    getline(cin, newAccount.accountHolderName);
    cout << "Enter Initial Balance: ";
    cin >> newAccount.balance;
    
    accounts[numAccounts] = newAccount;
    numAccounts++;
    
    cout << "Account created successfully!\n";
}

void depositMoney(Account accounts[], int numAccounts) {
    string accNum;
    double amount;
    cout << "Enter Account Number: ";
    cin >> accNum;
    cout << "Enter Amount to Deposit: ";
    cin >> amount;
    
    for (int i = 0; i < numAccounts; i++) {
        if (accounts[i].accountNumber == accNum) {
            accounts[i].balance += amount;
            cout << "Deposited " << amount << ". New balance: " << accounts[i].balance << endl;
            return;
        }
    }
    cout << "Account not found!\n";
}

void withdrawMoney(Account accounts[], int numAccounts) {
    string accNum;
    double amount;
    cout << "Enter Account Number: ";
    cin >> accNum;
    cout << "Enter Amount to Withdraw: ";
    cin >> amount;
    
    for (int i = 0; i < numAccounts; i++) {
        if (accounts[i].accountNumber == accNum) {
            if (amount > accounts[i].balance) {
                cout << "Insufficient balance!\n";
            } else {
                accounts[i].balance -= amount;
                cout << "Withdrawn " << amount << ". New balance: " << accounts[i].balance << endl;
            }
            return;
        }
    }
    cout << "Account not found!\n";
}

void displayAccountInfo(Account accounts[], int numAccounts) {
    string accNum;
    cout << "Enter Account Number: ";
    cin >> accNum;
    
    for (int i = 0; i < numAccounts; i++) {
        if (accounts[i].accountNumber == accNum) {
            cout << "Account Number: " << accounts[i].accountNumber << endl;
            cout << "Account Holder: " << accounts[i].accountHolderName << endl;
            cout << "Balance: " << accounts[i].balance << endl;
            return;
        }
    }
    cout << "Account not found!\n";
}

void showMenu() {
    cout << "\n--- Banking System Menu ---\n";
    cout << "1. Create Account\n";
    cout << "2. Deposit Money\n";
    cout << "3. Withdraw Money\n";
    cout << "4. Display Account Information\n";
    cout << "5. Exit\n";
    cout << "Enter your choice: ";
}

int main() {
    Account accounts[MAX_ACCOUNTS];
    int numAccounts = 0;
    int choice;
    
    do {
        showMenu();
        cin >> choice;
        
        switch (choice) {
            case 1:
                createAccount(accounts, numAccounts);
                break;
            case 2:
                depositMoney(accounts, numAccounts);
                break;
            case 3:
                withdrawMoney(accounts, numAccounts);
                break;
            case 4:
                displayAccountInfo(accounts, numAccounts);
                break;
            case 5:
                cout << "Exiting the system...\n";
                break;
            default:
                cout << "Invalid choice! Please try again.\n";
                break;
        }
    } while (choice != 5);
    
    return 0;
}

