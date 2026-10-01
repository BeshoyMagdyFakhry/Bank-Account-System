#include <iostream>
#include <string>
using namespace std;

class Account
{
protected:
    int accountNumber;
    string accountName;
    long long balance = 0;

public:
    Account() = default;

    Account(string nName, long long nBalance, int nAccountNumber) : accountNumber(nAccountNumber), accountName(nName), balance(nBalance) {}

    int getAccountNumber()
    {
        return accountNumber;
    }

    string getAccountName()
    {
        return accountName;
    }

    long long getBalance()
    {
        return balance;
    }

    void deposit(long nBalance)
    {
        balance = balance + nBalance;
    }

    bool withdraw(long nBalance)
    {
        if (nBalance > 0 && nBalance <= balance)
        {
            balance = balance - nBalance;
            return true;
        }

        return false;
    }

    void transfer(Account& tAccount, long tBalance)
    {
        if (tBalance > 0 && tBalance <= balance)
        {
            balance = balance - tBalance;
            tAccount.balance = tAccount.balance + tBalance;
        }
        else
        {
            cout << endl << "Transfer failed" << endl << endl;
        }
    }
};

class SavingsAccount : public Account
{
public:
    SavingsAccount() = default;

    SavingsAccount(string nName, long long nBalance, int nAccountNumber) : Account(nName, nBalance, nAccountNumber) {}

    void calculateInterest(bool type)
    {
        float interest = 0;

        cout << "Interest: 10%" << endl;

        if (type == true)
        {
            interest = balance * 0.1;
            cout << "yearly Interest: " << interest << endl << endl;
        }
        else if (type == false)
        {
            interest = (balance * 0.1) / 12;
            cout << "Monthly Interest: " << interest << endl << endl;
        }
    }
};

class CheckingAccount : public Account
{
public:
    CheckingAccount() = default;

    CheckingAccount(string nName, long long nBalance, int nAccountNumber) : Account(nName, nBalance, nAccountNumber) {}

    void limitCheck(bool type)
    {
        if (type == true)
        {
            cout << "your maximum transfer & withdrawal = 10,000" << endl << endl;
        }
        else if (type == false)
        {
            cout << "your maximum balance = 1,000,000" << endl << endl;
        }
    }
};


class Bank
{
    SavingsAccount savingsAccounts[100];
    int savingsAccountsCount = 0;

    CheckingAccount checkingAccounts[100];
    int checkingAccountsCount = 0;

    int nextAccountNumber = 19340;

public:
    void addAccount(SavingsAccount newAccount)
    {
        if (savingsAccountsCount < 100)
        {
            savingsAccounts[savingsAccountsCount] = newAccount;
            savingsAccountsCount++;
            nextAccountNumber++;
        }
        else
        {
            cout << "Bank is full" << endl << endl;
        }
    }

    void addAccount(CheckingAccount newAccount)
    {
        if (checkingAccountsCount < 100)
        {
            checkingAccounts[checkingAccountsCount] = newAccount;
            checkingAccountsCount++;
            nextAccountNumber++;
        }
        else
        {
            cout << "Bank is full" << endl << endl;
        }
    }

    int getNewAccountNumber()
    {
        return nextAccountNumber;
    }

    void showAccounts()
    {
        cout << "---------{Accounts Info}---------" << endl;

        for (int i = 0; i < savingsAccountsCount; i++)
        {
            cout << "Account number: " << savingsAccounts[i].getAccountNumber() << endl;
            cout << "Account name: " << savingsAccounts[i].getAccountName() << endl;
            cout << "balance: " << savingsAccounts[i].getBalance() << endl;
            cout << "Type: Savings Account" << endl;
            cout << "---------------------------------" << endl;
        }

        for (int i = 0; i < checkingAccountsCount; i++)
        {
            cout << "Account number: " << checkingAccounts[i].getAccountNumber() << endl;
            cout << "Account name: " << checkingAccounts[i].getAccountName() << endl;
            cout << "balance: " << checkingAccounts[i].getBalance() << endl;
            cout << "Type: Checking Account" << endl;
            cout << "---------------------------------" << endl;
        }
    }

    void searchAccounts(int nNumber)
    {
        bool found = false;

        for (int i = 0; i < savingsAccountsCount; i++)
        {
            if (savingsAccounts[i].getAccountNumber() == nNumber)
            {
                found = true;
                cout << savingsAccounts[i].getAccountName() << endl;
            }
        }

        for (int i = 0; i < checkingAccountsCount; i++)
        {
            if (checkingAccounts[i].getAccountNumber() == nNumber)
            {
                found = true;
                cout << checkingAccounts[i].getAccountName() << endl;
            }
        }

        if (found == false)
        {
            cout << "Account not found" << endl << endl;
        }
    }
};


int main()
{
    Bank bank;

    SavingsAccount savingsAccounts[100];
    int savingsAccountsCount = 0;

    CheckingAccount checkingAccounts[100];
    int checkingAccountsCount = 0;

    SavingsAccount savingsAccount1("Mina", 12600, bank.getNewAccountNumber());
    bank.addAccount(savingsAccount1);
    savingsAccounts[savingsAccountsCount] = savingsAccount1;
    savingsAccountsCount++;

    SavingsAccount savingsAccount2("Walid", 57000, bank.getNewAccountNumber());
    bank.addAccount(savingsAccount2);
    savingsAccounts[savingsAccountsCount] = savingsAccount2;
    savingsAccountsCount++;

    CheckingAccount checkingAccount1("Ahmed", 5900, bank.getNewAccountNumber());
    bank.addAccount(checkingAccount1);
    checkingAccounts[checkingAccountsCount] = checkingAccount1;
    checkingAccountsCount++;

    CheckingAccount checkingAccount2("Samy", 26700, bank.getNewAccountNumber());
    bank.addAccount(checkingAccount2);
    checkingAccounts[checkingAccountsCount] = checkingAccount2;
    checkingAccountsCount++;


    cout << "Welcome to the Bank Account System" << endl;
    while (true)
    {
        cout << "Please choose an option" << endl;
        cout << "-------------------------------" << endl;
        cout << "1. Create a new account" << endl;
        cout << "2. Show all accounts" << endl;
        cout << "3. Search for an account" << endl;
        cout << "4. Transfer money between accounts" << endl;
        cout << "5. Account Details" << endl;
        cout << "6. Exit" << endl << endl;

        int choice;
        cin >> choice;

        if (choice == 1)
        {
            string accountName;
            long long balance;
            int accountType;

            cout << "Enter account name: ";
            cin >> accountName;

            cout << "Enter initial balance: ";
            cin >> balance;

            cout << endl << "Choose account type:" << endl;
            cout << "1. Savings Account" << endl;
            cout << "2. Checking Account" << endl;
            cin >> accountType;

            if (accountType == 1)
            {
                SavingsAccount newAccount(accountName, balance, bank.getNewAccountNumber());

                bank.addAccount(newAccount);

                savingsAccounts[savingsAccountsCount] = newAccount;
                savingsAccountsCount++;

                cout << endl << "Savings account created successfully" << endl << endl;

                cout << "Account number: " << newAccount.getAccountNumber() << endl;
                cout << "Account name: " << newAccount.getAccountName() << endl;
                cout << "Balance: " << newAccount.getBalance() << endl << endl;

                cout << "Do you want to calculate interest? (yes or no): ";
                string interestChoice;
                cin >> interestChoice;

                if (interestChoice == "yes")
                {
                    cout << endl << "Do you want to calculate yearly or monthly interest?" << endl;
                    cout << "1. Yearly" << endl;
                    cout << "2. Monthly" << endl;
                    cout << "3. Both" << endl;

                    int interestType;
                    cin >> interestType;

                    cout << endl;

                    if (interestType == 1)
                    {
                        newAccount.calculateInterest(true);
                    }
                    else if (interestType == 2)
                    {
                        newAccount.calculateInterest(false);
                    }
                    else if (interestType == 3)
                    {
                        newAccount.calculateInterest(true);
                        newAccount.calculateInterest(false);
                    }
                    else
                    {
                        cout << "Invalid choice" << endl << endl;
                    }
                }
                else if (interestChoice == "no")
                {
                    cout << endl;
                }
                else
                {
                    cout << "Invalid choice" << endl << endl;
                }
            }
            else if (accountType == 2)
            {
                CheckingAccount newAccount(accountName, balance, bank.getNewAccountNumber());

                bank.addAccount(newAccount);

                checkingAccounts[checkingAccountsCount] = newAccount;
                checkingAccountsCount++;

                cout << endl << "Checking account created successfully" << endl << endl;

                cout << "Account number: " << newAccount.getAccountNumber() << endl;
                cout << "Account name: " << newAccount.getAccountName() << endl;
                cout << "Balance: " << newAccount.getBalance() << endl << endl;
            }
            else
            {
                cout << "Invalid account type" << endl << endl;
            }
        }

        else if (choice == 2)
        {
            bank.showAccounts();
            cout << endl;
        }

        else if (choice == 3)
        {
            cout << "search by:" << endl;
            cout << "1. Account number" << endl;
            cout << "2. Account name" << endl << endl;

            int searchChoice;
            cin >> searchChoice;

            if (searchChoice == 1)
            {
                int accountNumber;

                cout << "Enter account number: ";
                cin >> accountNumber;
                cout << endl;

                bool found = false;

                for (int i = 0; i < savingsAccountsCount; i++)
                {
                    if (savingsAccounts[i].getAccountNumber() == accountNumber)
                    {
                        found = true;

                        cout << "---------------------------------" << endl;
                        cout << "Account number: " << savingsAccounts[i].getAccountNumber() << endl;
                        cout << "Account name: " << savingsAccounts[i].getAccountName() << endl;
                        cout << "Balance: " << savingsAccounts[i].getBalance() << endl;
                        cout << "---------------------------------" << endl;
                    }
                }

                for (int i = 0; i < checkingAccountsCount; i++)
                {
                    if (checkingAccounts[i].getAccountNumber() == accountNumber)
                    {
                        found = true;

                        cout << "---------------------------------" << endl;
                        cout << "Account number: " << checkingAccounts[i].getAccountNumber() << endl;
                        cout << "Account name: " << checkingAccounts[i].getAccountName() << endl;
                        cout << "Balance: " << checkingAccounts[i].getBalance() << endl;
                        cout << "---------------------------------" << endl;
                    }
                }

                if (!found)
                {
                    cout << "Account not found" << endl << endl;
                }
            }

            else if (searchChoice == 2)
            {
                string accountName;

                cout << "Enter account name: ";
                cin >> accountName;
                cout << endl;

                bool found = false;

                for (int i = 0; i < savingsAccountsCount; i++)
                {
                    if (savingsAccounts[i].getAccountName() == accountName)
                    {
                        found = true;

                        cout << "---------------------------------" << endl;
                        cout << "Account number: " << savingsAccounts[i].getAccountNumber() << endl;
                        cout << "Account name: " << savingsAccounts[i].getAccountName() << endl;
                        cout << "Balance: " << savingsAccounts[i].getBalance() << endl;
                        cout << "---------------------------------" << endl;
                    }
                }

                for (int i = 0; i < checkingAccountsCount; i++)
                {
                    if (checkingAccounts[i].getAccountName() == accountName)
                    {
                        found = true;

                        cout << "---------------------------------" << endl;
                        cout << "Account number: " << checkingAccounts[i].getAccountNumber() << endl;
                        cout << "Account name: " << checkingAccounts[i].getAccountName() << endl;
                        cout << "Balance: " << checkingAccounts[i].getBalance() << endl;
                        cout << "---------------------------------" << endl;
                    }
                }

                if (!found)
                {
                    cout << "Account not found" << endl << endl;
                }
            }

            else
            {
                cout << "Invalid choice" << endl << endl;
            }
        }

        else if (choice == 4)
        {
            int senderNumber, receiverNumber;
            long long transferBalance;

            cout << "Enter Sender account number: ";
            cin >> senderNumber;

            cout << "Enter Receiver account number: ";
            cin >> receiverNumber;

            cout << "Enter the amount to transfer: ";
            cin >> transferBalance;

            bool senderFound = false;
            bool receiverFound = false;

            int senderType = 0;
            int receiverType = 0;

            int senderIndex = -1;
            int receiverIndex = -1;

            for (int i = 0; i < savingsAccountsCount; i++)
            {
                if (savingsAccounts[i].getAccountNumber() == senderNumber)
                {
                    senderFound = true;
                    senderType = 1;
                    senderIndex = i;
                }

                if (savingsAccounts[i].getAccountNumber() == receiverNumber)
                {
                    receiverFound = true;
                    receiverType = 1;
                    receiverIndex = i;
                }
            }

            for (int i = 0; i < checkingAccountsCount; i++)
            {
                if (checkingAccounts[i].getAccountNumber() == senderNumber)
                {
                    senderFound = true;
                    senderType = 2;
                    senderIndex = i;
                }

                if (checkingAccounts[i].getAccountNumber() == receiverNumber)
                {
                    receiverFound = true;
                    receiverType = 2;
                    receiverIndex = i;
                }
            }

            if (senderFound && receiverFound)
            {
                bool transferSuccessful = false;

                if (senderType == 1 && receiverType == 1)
                {
                    if (transferBalance > 0 && transferBalance <= savingsAccounts[senderIndex].getBalance())
                    {
                        savingsAccounts[senderIndex].transfer(savingsAccounts[receiverIndex], transferBalance);
                        transferSuccessful = true;
                    }
                }

                else if (senderType == 1 && receiverType == 2)
                {
                    if (transferBalance > 0 && transferBalance <= savingsAccounts[senderIndex].getBalance())
                    {
                        savingsAccounts[senderIndex].transfer(checkingAccounts[receiverIndex], transferBalance);
                        transferSuccessful = true;
                    }
                }

                else if (senderType == 2 && receiverType == 1)
                {
                    if (transferBalance > 0 && transferBalance <= checkingAccounts[senderIndex].getBalance())
                    {
                        checkingAccounts[senderIndex].transfer(savingsAccounts[receiverIndex], transferBalance);

                        transferSuccessful = true;
                    }
                }

                else if (senderType == 2 && receiverType == 2)
                {
                    if (transferBalance > 0 && transferBalance <= checkingAccounts[senderIndex].getBalance())
                    {
                        checkingAccounts[senderIndex].transfer(checkingAccounts[receiverIndex], transferBalance);

                        transferSuccessful = true;
                    }
                }


                if (transferSuccessful)
                {
                    bank = Bank();

                    for (int i = 0; i < savingsAccountsCount; i++)
                    {
                        bank.addAccount(savingsAccounts[i]);
                    }

                    for (int i = 0; i < checkingAccountsCount; i++)
                    {
                        bank.addAccount(checkingAccounts[i]);
                    }
                    cout << endl << "Transfer completed successfully" << endl << endl;

                    cout << "Sender new account info" << endl;
                    cout << "---------------------------------" << endl;

                    if (senderType == 1)
                    {
                        cout << "Account number: " << savingsAccounts[senderIndex].getAccountNumber() << endl;
                        cout << "Account name: " << savingsAccounts[senderIndex].getAccountName() << endl;
                        cout << "Balance: " << savingsAccounts[senderIndex].getBalance() << endl;
                    }
                    else
                    {
                        cout << "Account number: " << checkingAccounts[senderIndex].getAccountNumber() << endl;
                        cout << "Account name: " << checkingAccounts[senderIndex].getAccountName() << endl;
                        cout << "Balance: " << checkingAccounts[senderIndex].getBalance() << endl;
                    }
                    cout << "---------------------------------" << endl;
                    cout << "Receiver new account info" << endl;
                    cout << "---------------------------------" << endl;
                    if (receiverType == 1)
                    {
                        cout << "Account number: " << savingsAccounts[receiverIndex].getAccountNumber() << endl;
                        cout << "Account name: " << savingsAccounts[receiverIndex].getAccountName() << endl;
                        cout << "Balance: " << savingsAccounts[receiverIndex].getBalance() << endl;
                    }
                    else
                    {
                        cout << "Account number: " << checkingAccounts[receiverIndex].getAccountNumber() << endl;
                        cout << "Account name: " << checkingAccounts[receiverIndex].getAccountName() << endl;
                        cout << "Balance: " << checkingAccounts[receiverIndex].getBalance() << endl;
                    }
                    cout << "---------------------------------" << endl;
                }
                else
                {
                    cout << endl << "Transfer failed" << endl << endl;
                }
            }

            else
            {
                cout << endl << "Account not found" << endl << endl;
            }
        }

        else if (choice == 5)
        {
            int accountNumber;

            cout << "Enter account number: ";
            cin >> accountNumber;
            cout << endl;

            bool accountFound = false;
            int accountType = 0;
            int accountIndex = -1;

            for (int i = 0; i < savingsAccountsCount; i++)
            {
                if (savingsAccounts[i].getAccountNumber() == accountNumber)
                {
                    accountFound = true;
                    accountType = 1;
                    accountIndex = i;
                    break;
                }
            }

            if (!accountFound)
            {
                for (int i = 0; i < checkingAccountsCount; i++)
                {
                    if (checkingAccounts[i].getAccountNumber() == accountNumber)
                    {
                        accountFound = true;
                        accountType = 2;
                        accountIndex = i;
                        break;
                    }
                }
            }

            if (accountFound)
            {
                if (accountType == 1)
                {
                    SavingsAccount& savingsAccount = savingsAccounts[accountIndex];

                    cout << "Account number: " << savingsAccount.getAccountNumber() << endl;
                    cout << "Account name: " << savingsAccount.getAccountName() << endl;
                    cout << "Balance: " << savingsAccount.getBalance() << endl;
                    cout << "Interest: 10%" << endl << endl;

                    int choice;

                    cout << "Do you want to do any of the following?" << endl;
                    cout << "1. Deposit" << endl;
                    cout << "2. Withdraw" << endl;
                    cout << "3. Calculate Interest" << endl << endl;

                    cin >> choice;

                    if (choice == 1)
                    {
                        long long depositAmount;

                        cout << "Enter deposit amount: ";
                        cin >> depositAmount;

                        savingsAccount.deposit(depositAmount);

                        bank = Bank();

                        for (int i = 0; i < savingsAccountsCount; i++)
                        {
                            bank.addAccount(savingsAccounts[i]);
                        }

                        for (int i = 0; i < checkingAccountsCount; i++)
                        {
                            bank.addAccount(checkingAccounts[i]);
                        }

                        cout << endl << "Deposit successful" << endl;
                        cout << "New balance: " << savingsAccount.getBalance() << endl << endl;
                    }

                    else if (choice == 2)
                    {
                        long long withdrawAmount;

                        cout << "Enter withdraw amount: ";
                        cin >> withdrawAmount;

                        if (savingsAccount.withdraw(withdrawAmount))
                        {
                            bank = Bank();

                            for (int i = 0; i < savingsAccountsCount; i++)
                            {
                                bank.addAccount(savingsAccounts[i]);
                            }

                            for (int i = 0; i < checkingAccountsCount; i++)
                            {
                                bank.addAccount(checkingAccounts[i]);
                            }

                            cout << endl << "Withdraw successful" << endl;
                            cout << "New balance: " << savingsAccount.getBalance() << endl << endl;
                        }
                        else
                        {
                            cout << endl << "Withdraw failed" << endl << endl;
                        }
                    }

                    else if (choice == 3)
                    {
                        cout << "Do you want to calculate yearly or monthly interest?" << endl;
                        cout << "1. Yearly" << endl;
                        cout << "2. Monthly" << endl;
                        cout << "3. Both" << endl << endl;

                        int interestType;
                        cin >> interestType;

                        if (interestType == 1)
                        {
                            savingsAccount.calculateInterest(true);
                        }

                        else if (interestType == 2)
                        {
                            savingsAccount.calculateInterest(false);
                        }

                        else if (interestType == 3)
                        {
                            savingsAccount.calculateInterest(true);
                            savingsAccount.calculateInterest(false);
                        }

                        else
                        {
                            cout << "Invalid choice" << endl << endl;
                        }
                    }
                }

                else if (accountType == 2)
                {
                    CheckingAccount& checkingAccount = checkingAccounts[accountIndex];

                    cout << "Account number: " << checkingAccount.getAccountNumber() << endl;
                    cout << "Account name: " << checkingAccount.getAccountName() << endl;
                    cout << "Balance: " << checkingAccount.getBalance() << endl;

                    int choice;

                    cout << "Do you want to do any of the following?" << endl;
                    cout << "1. Deposit" << endl;
                    cout << "2. Withdraw" << endl;
                    cout << "3. Check limits" << endl << endl;

                    cin >> choice;


                    if (choice == 1)
                    {
                        long long depositAmount;

                        cout << "Enter deposit amount: ";
                        cin >> depositAmount;

                        checkingAccount.deposit(depositAmount);

                        bank = Bank();

                        for (int i = 0; i < savingsAccountsCount; i++)
                        {
                            bank.addAccount(savingsAccounts[i]);
                        }

                        for (int i = 0; i < checkingAccountsCount; i++)
                        {
                            bank.addAccount(checkingAccounts[i]);
                        }

                        cout << endl << "Deposit successful" << endl;
                        cout << "New balance: " << checkingAccount.getBalance() << endl << endl;
                    }

                    else if (choice == 2)
                    {
                        long long withdrawAmount;

                        cout << "Enter withdraw amount: ";
                        cin >> withdrawAmount;

                        if (checkingAccount.withdraw(withdrawAmount))
                        {
                            bank = Bank();

                            for (int i = 0; i < savingsAccountsCount; i++)
                            {
                                bank.addAccount(savingsAccounts[i]);
                            }

                            for (int i = 0; i < checkingAccountsCount; i++)
                            {
                                bank.addAccount(checkingAccounts[i]);
                            }

                            cout << endl << "Withdraw successful" << endl;
                            cout << "New balance: " << checkingAccount.getBalance() << endl << endl;
                        }
                        else
                        {
                            cout << endl << "Withdraw failed" << endl << endl;
                        }
                    }

                    else if (choice == 3)
                    {
                        checkingAccount.limitCheck(true);
                        checkingAccount.limitCheck(false);
                    }
                }
            }

            else
            {
                cout << "Account not found" << endl << endl;
            }
        }

        else if (choice == 6)
        {
            break;
        }

        else
        {
            cout << "Invalid choice" << endl << endl;
        }
    }

    return 0;
}
