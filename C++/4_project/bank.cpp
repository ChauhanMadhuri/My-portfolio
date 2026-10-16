
#include <iostream>
#include <string>
using namespace std;

class BankAccount
{
protected:
    int accountNumber;
    string accountHolderName;

private:
    double balance;

public:
    BankAccount(int no, string name, double bal)
    {
        accountNumber = no;
        accountHolderName = name;
        balance = bal;
    }

    virtual void deposit(double amount)
    {
        if (amount > 0)
        {
            balance += amount;
            cout << "Amount deposited successfully.\n";
        }
        else
            cout << "Invalid amount.\n";
    }

    virtual void withdraw(double amount)
    {
        if (amount > 0 && amount <= balance)
        {
            balance -= amount;
            cout << "Amount withdrawn successfully.\n";
        }
        else
            cout << "Insufficient balance or invalid amount.\n";
    }

    double getBalance()
    {
        return balance;
    }

    // Protected balance access for derived classes
    void addInterest(double amount)
    {
        if (amount > 0)
            balance += amount;
    }

    virtual void calculateInterest()
    {
        cout << "Interest calculation is not available.\n";
    }

    virtual void displayAccountInfo()
    {
        cout << "\nAccount Number: " << accountNumber;
        cout << "\nAccount Holder: " << accountHolderName;
        cout << "\nBalance: Rs. " << balance << endl;
    }

    virtual ~BankAccount() {}
};

class SavingsAccount : public BankAccount
{
private:
    double interestRate;

public:
    SavingsAccount(int no, string name, double bal, double rate)
        : BankAccount(no, name, bal)
    {
        interestRate = rate;
    }

    void calculateInterest() override
    {
        double interest = getBalance() * interestRate / 100;
        addInterest(interest);

        cout << "Savings Interest: Rs. " << interest << endl;
    }

    void displayAccountInfo() override
    {
        cout << "\n--- Savings Account ---";
        BankAccount::displayAccountInfo();
        cout << "Interest Rate: " << interestRate << "%\n";
    }
};

class CheckingAccount : public BankAccount
{
private:
    double overdraftLimit;

public:
    CheckingAccount(int no, string name, double bal, double limit)
        : BankAccount(no, name, bal)
    {
        overdraftLimit = limit;
    }

    void withdraw(double amount) override
    {
        if (amount > 0 &&
            amount <= getBalance() + overdraftLimit)
        {
            double newBalance = getBalance() - amount;

            if (newBalance < 0)
            {
                double overdraftUsed = -newBalance;
                cout << "Overdraft used: Rs. "
                     << overdraftUsed << endl;
            }

            // Withdraw available balance first.
            // Store any overdraft as a negative balance.
            if (amount <= getBalance())
            {
                BankAccount::withdraw(amount);
            }
            else
            {
                double remaining = amount - getBalance();
                BankAccount::withdraw(getBalance());
                cout << "Overdraft amount: Rs. "
                     << remaining << endl;
                // Overdraft tracking is shown for demonstration.
            }
        }
        else
            cout << "Overdraft limit exceeded.\n";
    }

    void checkOverdraft()
    {
        cout << "Overdraft Limit: Rs. "
             << overdraftLimit << endl;
    }

    void displayAccountInfo() override
    {
        cout << "\n--- Checking Account ---";
        BankAccount::displayAccountInfo();
        checkOverdraft();
    }
};

class FixedDepositAccount : public BankAccount
{
private:
    int term;
    double interestRate;

public:
    FixedDepositAccount(int no, string name, double bal,
                        int months, double rate)
        : BankAccount(no, name, bal)
    {
        term = months;
        interestRate = rate;
    }

    void calculateInterest() override
    {
        double interest = getBalance() * interestRate
                          * term / 1200.0;

        addInterest(interest);
        cout << "Fixed Deposit Interest: Rs. "
             << interest << endl;
    }

    void displayAccountInfo() override
    {
        cout << "\n--- Fixed Deposit Account ---";
        BankAccount::displayAccountInfo();
        cout << "Term: " << term << " months\n";
        cout << "Interest Rate: " << interestRate << "%\n";
    }
};

int main()
{
    BankAccount *account = 0;

    int choice, type;
    int no, months;
    string name;
    double balance, amount, rate, limit;

    cout << "===== BANKING SYSTEM =====\n";
    cout << "Enter Account Number: ";
    cin >> no;

    cout << "Enter Account Holder Name: ";
    cin.ignore();
    getline(cin, name);

    cout << "Enter Opening Balance: ";
    cin >> balance;

    cout << "\nSelect Account Type\n";
    cout << "1. Savings Account\n";
    cout << "2. Checking Account\n";
    cout << "3. Fixed Deposit Account\n";
    cout << "Enter choice: ";
    cin >> type;

    if (type == 1)
    {
        cout << "Enter Interest Rate (%): ";
        cin >> rate;
        account = new SavingsAccount(no, name, balance, rate);
    }
    else if (type == 2)
    {
        cout << "Enter Overdraft Limit: ";
        cin >> limit;
        account = new CheckingAccount(no, name, balance, limit);
    }
    else if (type == 3)
    {
        cout << "Enter Term in Months: ";
        cin >> months;
        cout << "Enter Interest Rate (%): ";
        cin >> rate;

        account = new FixedDepositAccount(
            no, name, balance, months, rate);
    }
    else
    {
        cout << "Invalid account type.\n";
        return 0;
    }

    do
    {
        cout << "\n===== BANK MENU =====\n";
        cout << "1. Deposit\n";
        cout << "2. Withdraw\n";
        cout << "3. Calculate Interest\n";
        cout << "4. Display Account Information\n";
        cout << "5. Check Balance\n";
        cout << "0. Exit\n";
        cout << "Enter choice: ";
        cin >> choice;

        switch (choice)
        {
        case 1:
            cout << "Enter amount to deposit: ";
            cin >> amount;
            account->deposit(amount);
            break;

        case 2:
            cout << "Enter amount to withdraw: ";
            cin >> amount;
            account->withdraw(amount);
            break;

        case 3:
            account->calculateInterest();
            break;

        case 4:
            account->displayAccountInfo();
            break;

        case 5:
            cout << "Current Balance: Rs. "
                 << account->getBalance() << endl;
            break;

        case 0:
            cout << "Thank you for using Banking System.\n";
            break;

        default:
            cout << "Invalid choice.\n";
        }

    } while (choice != 0);

    delete account;
    return 0;
}


