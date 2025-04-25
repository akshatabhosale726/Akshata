#include<iostream>
using namespace std;

class BankAccount {
	private:
		string accountHolder;
		double accountBalance;
		
	public:
		BankAccount(string holder = "\0", double initialBalance = 0)
			: accountHolder(holder), accountBalance(initialBalance) {
			cout << "Creating Account for " << accountHolder << " with Initial Deposit: " << accountBalance << endl << endl;
		}
		
		void deposit(double amount) {
			if(amount > 0) {
				this->accountBalance += amount;
				cout << "Depositing " << amount << " into " << this->accountHolder << " Account" << endl << endl;
			}
		}
		
		void withdraw(double amount) {
			try {
				if (amount > this->accountBalance)
					throw this->accountBalance;
				this->accountBalance -= amount;
				cout << "Withdrawing " << amount << " from " << this->accountHolder << " Account" << endl << endl;
			}
			catch(double currentBalance) {
				cout << "Error : Insufficient Funds Exception" << endl << "Balance :" << currentBalance << endl << endl;
			}
		}
		
		void transfer(BankAccount &to, double amount) {
			try {
				if (amount > this->accountBalance)
					throw this->accountBalance;
				this->accountBalance -= amount;
				to.accountBalance += amount;
				cout << "Transferring " << amount << " from " << this->accountHolder << " to " << to.accountHolder << " Account" << endl << endl;
				cout << "New Balance of " << this->accountHolder << ": " << this->accountBalance << endl;
				cout << "New Balance of " << to.accountHolder << ": " << to.accountBalance << endl << endl;
			}
			catch(double currentBalance) {
				cout << "Error : Insufficient Funds Exception" << endl << "Balance :" << currentBalance << endl << endl;
			}
		}
		
		void divideBalance(double divisor) {
			try {
				if(divisor == 0)
					throw divisor;
				this->accountBalance /= divisor;
			}
			catch(double divisor) {
				cout << "Error : Divide By Zero Exception" << endl << "Divisor :" << divisor << endl << endl;
			}
		}
		
		void display() {
			cout << "Account Details" << endl;
			cout << "Holder Name: " << this->accountHolder << endl;
			cout << "Balance    : " << this->accountBalance << endl << endl;
		}
};

int main() {
	BankAccount account1("Prasanjit Kamble", 3000);
	BankAccount account2("Shriyash Jadhav", 2000);
	
	account1.deposit(5000);
	account1.withdraw(2000);
	account1.transfer(account2, 2000);
	account1.divideBalance(0);
	
	account1.display();
	account2.display();
}
