#include <iostream>
using namespace std;

class BankAccount {
protected:
    static int totalAC;
    int MIN_HIGH = 10000001110;
    long long acNo;
    double acBalance;

public:
    BankAccount() : acBalance(0) {
        totalAC++;
        acNo++;
    }
    
    BankAccount(long long a, double acBalance) : acBalance(acBalance) {
        totalAC++;
        acNo = a;
    }

    static int getTotalAC() {
        return totalAC;
    }

    double deposit(double money) {
        acBalance += money;
        return acBalance;
    }
    
    double withdraw(double money) {
        if (acBalance >= money) {
            acBalance -= money;
        } else {
            cout << "Insufficient balance!" << endl;
        }
        return acBalance;
    }

    void display() {
        cout << "Login count: " << getTotalAC() << endl;
        cout << "Account Number: " << acNo << endl;
        cout << "Current Balance: " << acBalance << endl;
    }

    bool isHighValueAccount() const {
        return acBalance > MIN_HIGH;
    }
};

int BankAccount::totalAC = 0;

class Bank {
    BankAccount arr[1000];
    int currentAccounts = 0;
    static long long accountNo;

public:
    void addAccount(double initialBalance) {
        if (currentAccounts < 100) {
            arr[currentAccounts] = BankAccount(accountNo, initialBalance);
            currentAccounts++;
            accountNo++; 
        } else {
            cout << "Maximum account limit reached." << endl;
        }
    }

    void displayAccounts() {
        for (int i = 0; i < currentAccounts; i++) {
            arr[i].display();
        }
    }
    
};

long long Bank::accountNo = 100110011;

int main() {
    Bank b1, b2, b3, b4, b5,b6;

    b1.addAccount(1538);
    b1.displayAccounts();

    b2.addAccount(326);
    b2.displayAccounts();

    b3.addAccount(93279);
    b3.displayAccounts();

    b4.addAccount(387);
    b4.displayAccounts();

    b5.addAccount(37482);
    b5.displayAccounts();

    b6.addAccount(37482);
    b6.displayAccounts();
    
    return 0;
}