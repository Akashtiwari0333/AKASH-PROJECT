
#include <iostream>
#include <fstream>
#include <vector>
#include <iomanip>
using namespace std;

// Bank Account Class
class BankAccount {
private:
    int accountNumber;
    string name;
    double balance;

public:
    BankAccount() {}

    BankAccount(int accNo, string n, double bal) {
        accountNumber = accNo;
        name = n;
        balance = bal;
    }

    void display() const {
        cout << "Account No.: " << accountNumber
             << " | Name: " << name
             << " | Balance: " << balance << endl;
    }

    int getAccountNumber() const { return accountNumber; }
    string getName() const { return name; }
    double getBalance() const { return balance; }

    void deposit(double amt) {
        balance += amt;
    }

    bool withdraw(double amt) {
        if (amt <= balance) {
            balance -= amt;
            return true;
        }
        return false;
    }

    void saveToFile(ofstream &file) {
        file << accountNumber << " " << name << " " << balance << endl;
    }

    void loadFromFile(ifstream &file) {
        file >> accountNumber >> name >> balance;
    }
};

// Global Vector to Store Accounts
vector<BankAccount> accounts;

// Load accounts from file
void loadAccounts() {
    accounts.clear();
    ifstream infile("accounts.txt");
    if (infile.is_open()) {
        BankAccount acc;
        while (!infile.eof()) {
            acc.loadFromFile(infile);
            if (infile) accounts.push_back(acc);
        }
        infile.close();
    }
}

// Save accounts to file
void saveAccounts() {
    ofstream outfile("accounts.txt");
    for (auto &acc : accounts) {
        acc.saveToFile(outfile);
    }
    outfile.close();
}

// Find account index
int findAccount(int accNo) {
    for (size_t i = 0; i < accounts.size(); i++) {
        if (accounts[i].getAccountNumber() == accNo)
            return i;
    }
    return -1;
}

// Menu Functions
void createAccount() {
    int accNo;
    string name;
    double bal;

    cout << "Enter Account Number: ";
    cin >> accNo;
    if (findAccount(accNo) != -1) {
        cout << "Account already exists!\n";
        return;
    }

    cout << "Enter Name: ";
    cin >> name;
    cout << "Enter Initial Balance: ";
    cin >> bal;

    accounts.emplace_back(accNo, name, bal);
    saveAccounts();
    cout << "Account Created Successfully!\n";
}

void displayAccount() {
    int accNo;
    cout << "Enter Account Number: ";
    cin >> accNo;
    int idx = findAccount(accNo);
    if (idx != -1) {
        accounts[idx].display();
    } else {
        cout << "Account not found!\n";
    }
}

void depositMoney() {
    int accNo;
    double amt;
    cout << "Enter Account Number: ";
    cin >> accNo;
    int idx = findAccount(accNo);
    if (idx != -1) {
        cout << "Enter Amount to Deposit: ";
        cin >> amt;
        accounts[idx].deposit(amt);
        saveAccounts();
        cout << "Amount Deposited Successfully!\n";
    } else {
        cout << "Account not found!\n";
    }
}

void withdrawMoney() {
    int accNo;
    double amt;
    cout << "Enter Account Number: ";
    cin >> accNo;
    int idx = findAccount(accNo);
    if (idx != -1) {
        cout << "Enter Amount to Withdraw: ";
        cin >> amt;
        if (accounts[idx].withdraw(amt)) {
            saveAccounts();
            cout << "Amount Withdrawn Successfully!\n";
        } else {
            cout << "Insufficient Balance!\n";
        }
    } else {
        cout << "Account not found!\n";
    }
}

void deleteAccount() {
    int accNo;
    cout << "Enter Account Number to Delete: ";
    cin >> accNo;
    int idx = findAccount(accNo);
    if (idx != -1) {
        accounts.erase(accounts.begin() + idx);
        saveAccounts();
        cout << "Account Deleted Successfully!\n";
    } else {
        cout << "Account not found!\n";
    }
}

void displayAllAccounts() {
    cout << "\n----- All Accounts -----\n";
    for (auto &acc : accounts) {
        acc.display();
    }
    cout << "------------------------\n";
}

// Main Function
int main() {
    int choice;
    loadAccounts();

    do {
        cout << "\n==== Bank Management System ====\n";
        cout << "1. Create New Account\n";
        cout << "2. View Account Details\n";
        cout << "3. Deposit Money\n";
        cout << "4. Withdraw Money\n";
        cout << "5. Delete Account\n";
        cout << "6. Display All Accounts\n";
        cout << "7. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
        case 1: createAccount(); break;
        case 2: displayAccount(); break;
        case 3: depositMoney(); break;
        case 4: withdrawMoney(); break;
        case 5: deleteAccount(); break;
        case 6: displayAllAccounts(); break;
        case 7: cout << "Thank you for using BMS!\n"; break;
        default: cout << "Invalid choice!\n";
        }
    } while (choice != 7);

    return 0;
}
