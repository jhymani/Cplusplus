Name: Jhymani Joseph
Date: 03 Dec 2024
Class: 2143 OOP

Definitions

1.  Encapsulation - Encapsulation is one of the fundamental concepts of Object-Oriented Programming (OOP) that refers to the bundling of data (variables) and methods (functions) that operate on the data into a single unit or class. It also restricts direct access to some of an object's components, which is a means of preventing unintended interference and misuse of data. This is often achieved through access modifiers such as private, protected, and public, which define the level of access to the data.
   
![Your-paragraph-text--59-](https://github.com/user-attachments/assets/c9e96748-dfa7-42b0-b7b9-94e577e3ebc6)

e.g.
```class BankAccount {
private:
    double balance;  // Private variable to store the balance

public:
    // Constructor to initialize balance
    BankAccount(double initialBalance) {
        balance = initialBalance;
    }

    // Public method to deposit money
    void deposit(double amount) {
        if (amount > 0) {
            balance += amount;
            cout << "Deposit successful. New balance: $" << balance << endl;
        } else {
            cout << "Invalid deposit amount." << endl;
        }
    }

    // Public method to withdraw money
    void withdraw(double amount) {
        if (amount > 0 && amount <= balance) {
            balance -= amount;
            cout << "Withdrawal successful. New balance: $" << balance << endl;
        } else {
            cout << "Invalid withdrawal amount or insufficient balance." << endl;
        }
    }

    // Public method to check balance (read-only access)
    double getBalance() const {
        return balance;
    }
};

int main() {
    // Create an instance of BankAccount with an initial balance of $500
    BankAccount account(500.0);

    // Perform some operations
    account.deposit(150.0);
    account.withdraw(50.0);

    // Access balance
    cout << "Final balance: $" << account.getBalance() << endl;

    return 0;
}

2. Abstract Classes and Interfaces 

