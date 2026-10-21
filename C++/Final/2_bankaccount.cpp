//2. Define a class named `BankAccount` with private attributes `accountNumber`, `balance`, and `ownerName`.
// Encapsulate these attributes using appropriate access specifiers. Implement public member functions to 
 //credit, debit, and display the balance. Demonstrate encapsulation by interacting with the class through its member functions.


#include <iostream>
#include <string>

using namespace std;

class BankAccount
{
private:
    int accountNumber;
    double balance;
    string ownerName;

public:
    // Constructor
    BankAccount(int no, double bal, string name)
    {
        accountNumber = no;
        balance = bal;
        ownerName = name;
    }

    // Credit amount
    void credit(double amount)
    {
        if (amount > 0)
        {
            balance = balance + amount;
            cout << "Amount credited successfully." << endl;
        }
        else
        {
            cout << "Invalid amount!" << endl;
        }
    }

    // Debit amount
    void debit(double amount)
    {
        if (amount > 0 && amount <= balance)
        {
            balance = balance - amount;
            cout << "Amount debited successfully." << endl;
        }
        else
        {
            cout << "Insufficient balance or invalid amount!" << endl;
        }
    }

    // Display account details
    void displayBalance()
    {
        cout << "\nAccount Number: " << accountNumber << endl;
        cout << "Owner Name: " << ownerName << endl;
        cout << "Balance: " << balance << endl;
    }
};

int main()
{
    BankAccount b1(101, 5000, "Madhuri");

    b1.displayBalance();

    b1.credit(1000);
    b1.debit(1000);

    b1.displayBalance();

    return 0;
}

