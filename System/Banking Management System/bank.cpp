#include <iostream>
#include <list>
#include <vector>

#include "account.cpp"

class Bank{
    private:
        vector<Account> accounts;

    public:
        // Creating a new Account
        void create_account(int acc_number, string holder_name, double amount) {
            Account newAcc(acc_number, holder_name, amount);
            accounts.push_back(newAcc);
        }

        // Find account by account number
        Account* findAccount(int accNum) {
            for (auto& account : accounts) {
                if (account.account_info().account_number == accNum) {
                    return &account;
                }
            }
            return nullptr;
        }

        void deposit(int money, int account_number) {
            Account* acc = findAccount(account_number);
            acc->deposit_funds(money);
        }

        void withdraw(int money, int account_number) {
            Account* acc = findAccount(account_number);
            acc->withdraw_funds(money);
        }

        void account_info(int account_number) {
            Info acc = findAccount(account_number)->account_info();
            cout << "\t\t\t\t\t   Account Information  \n";
            cout << "\t\t\t\t\t   Account Number: " << acc.account_number << endl;
            cout << "\t\t\t\t\t   Account Holder name: " << acc.account_holder << endl;
            cout << "\t\t\t\t\t   Account Balance " << acc.account_balance << endl;
        }

        void trans_history(int account_number) {
            vector<Transaction> trans = findAccount(account_number)->transaction_history();

            int num = 0;
            cout << "\n\t\t\t\t\t   Transaction Information  \n";
            for (const Transaction& item : trans) {
                cout << "\t\t" << ++num << " | " << item.type << " | " << item.amount << " | " << item.timestamp  << endl;
            }
        }

        bool doesExist(int account_number) {
            Account* acc = findAccount(account_number);
            if (acc == nullptr) {
                return false;
            } 
            return true;
        }
};