#include "bank.cpp"

#include<iostream>
#include <cstdio>

using namespace std;

class Helper{
    public:
        void wait() {
            cout << "\n\nPress Enter to continue...";
            cin.ignore(); 
            getchar(); 
        }
};

int main() {
    Helper helper;
    int ans = -1;
    Bank bank;
    while (ans != 0) {
        cout << "\n\t\t\t\t\t\t Welcome to My Bank \n\n";
        cout << "\t\t\t Type the number beside the task to initiate the task \n";
        cout << "\t\t\t Create a new Account: 1" << endl;
        cout << "\t\t\t Use your bank Account: 2" << endl;
        cout << "\t\t\t Exit bank: 0" << endl;
        
        cout << "\n\t\t\tEnter your number: ";
        cin >> ans;

        int number;
        string name;
        double amount;

        switch (ans)
        {
            case 1:
                number = -1;
                amount = -1;
                cout << "\t\t\t\t\t\t Creating Account \n\n";
                cout << "\t\t\t Enter your new bank account Number: ";
                cin >> number;
                cout << "\t\t\t Enter your name: ";
                cin >> name;
                cout << "\t\t\t Enter your amount: ";
                cin >> amount;

                if (number == -1 || name.empty() || amount == -1) {
                    cout << "\t\t\t Invaild Details Entered";
                    break;
                }
                
                bank.create_account(number, name, amount);

                cout << "Bank Created Successfully";
                break;
            
            case 2:
                cout << "Enter your bank Account Number: ";
                cin >> number;

                if(bank.doesExist(number)){
                    ans = -1;
                    while(ans != 0) {
                        cout << "\n\t\t\t\t\t\t Welcome to Your Account \n\n";
                        cout << "\t\t\t Type the number beside the task to initiate the task \n";
                        cout << "\t\t\t Check bank info: 1" << endl;
                        cout << "\t\t\t Withdraw money: 2" << endl;
                        cout << "\t\t\t Deposit money: 3" << endl;
                        cout << "\t\t\t Transaction History: 4" << endl;
                        cout << "\t\t\t Exit your account: 0" << endl;
                        cout << "\n\t\t\t Enter your number: ";
                        cin >> ans;

                        switch (ans)
                        {
                        case 1:
                            bank.account_info(number);
                            helper.wait();
                            break;
                        
                        case 2:
                            cout << "Enter Amount you want to withdraw: ";
                            cin >> amount;
                            bank.withdraw(amount, number);
                            helper.wait();
                            break;

                        case 3:
                            cout << "Enter the amount you want to deposit: ";
                            cin >> amount;
                            bank.deposit(amount, number);
                            helper.wait();
                            break;

                        case 4:
                            bank.trans_history(number);
                            helper.wait();
                            break;

                        case 0:
                            break;

                        default:
                            cout << "Invaild Number Entered";
                            helper.wait();
                            break;
                        }
                    }

                } else {
                    cout << "Account Does not Exists";
                    helper.wait();
                }

                ans = -1;
                break;

            case 0:
                break;

            default:
                cout << "Invaild Number Entered";
                helper.wait();
                break;
            }
    }
}




