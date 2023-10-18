#include<iostream>
#include<vector>
#include<ctime>

using namespace std;

struct Transaction {
    string type; 
    int amount;
    string timestamp;
};

struct Info {
    int account_number;
    string account_holder;
    double account_balance;
};

class Account {
    private:
        int account_number;
        string account_holder;
        double account_balance;
        vector<Transaction> transHistory;

    public: 
        Account(int acc_number, string acc_holder, double acc_balance) {
            this->account_number = acc_number;
            this->account_holder.assign(acc_holder);
            this->account_balance = acc_balance;
        }

        // Add Funds
        void deposit_funds(int money) {
            account_balance += money;
            record_Transaction("Deposit", money);
        }

        // Take money
        void withdraw_funds(int money) {
            if (money <= account_balance) {
                account_balance -= money;
                record_Transaction("Withdraw", money);

            } else {
                cout << "Insufficient Funds" << endl;
            }
        }

        // Return Account balance
        double check_balance() {
            return account_balance;
        }

        // Recording Transaction
        void record_Transaction(string type, int amount) {
            Transaction trans;
            trans.amount = amount;
            trans.type = type;

            time_t now = time(0);
            trans.timestamp = ctime(&now);

            transHistory.push_back(trans);
        }

        // Printing Account Info
        Info account_info() {
            // cout << "\t\t\t\t\t   Account Information  \n";
            // cout << "\t\t\t\t\t   Account Number: " << account_number << endl;
            // cout << "\t\t\t\t\t   Account Holder name: " << account_holder << endl;
            // cout << "\t\t\t\t\t   Account Balance " << account_balance << endl;
            Info acc_info;
            acc_info.account_balance = account_balance;
            acc_info.account_holder.assign(account_holder);
            acc_info.account_number = account_number;
            return acc_info;
        }

        vector<Transaction> transaction_history() {
            // int num = 1;
            // cout << "\n\t\t\t\t\t   Transaction Information  \n";
            // for (const Transaction& item : transHistory) {
            //     cout << "\t\t\t\t\t" << ++num << " " << item.timestamp << " " << item.type << " " << item.amount << endl;
            // }
            return transHistory;
        }
};

