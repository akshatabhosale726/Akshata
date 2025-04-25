#include<iostream>
using namespace std;

int main() {
    int balance = 1000;
    int choice, amount;
    
    do {
        cout << "\nBank Menu" << endl;
        cout << "1. Check Balance" << endl;
        cout << "2. Deposit" << endl;
        cout << "3. Withdraw" << endl;
        cout << "4. Exit" << endl;
        cout << "Enter your Choice: ";
        cin >> choice;
        
        if(choice == 1) {
            cout << "Balance: $" << balance << endl;
        }
        else if(choice == 2) {
            cout << "Enter Deposit Amount: $";
            cin >> amount;
            balance += amount;
            cout << "Amount Deposited successfully! New balance: $" << balance << endl;
        }
        else if(choice == 3) {
            cout << "Enter Withdrawal Amount: $";
            cin >> amount;
            if(balance >= amount) {
                balance -= amount;
                cout << "Withdrawal successful! New balance: $" << balance << endl;
            }
            else {
                cout << "Insufficient balance!" << endl;
            }
        }
        else if(choice == 4) {
            cout << "Exiting..." << endl;
        }
        else {
            cout << "Invalid Choice. Please try again." << endl;
        }
    } while(choice != 4);
    
    return 0;
}

