#include<iostream>
#include<string>
using namespace std;
class BankAccount{
	private:
			string accountHolder;
			int accountNumber;
			string accountType;
			double balance;
	
	public:
			BankAccount(){
				accountHolder = "Riya patil";
				accountNumber = 123456;
				accountType = "Saving";
				balance = 2000;
			}
			
			BankAccount(string name, int number,  string type , double bal){
				accountNumber = number;
				accountType = type ;
				balance = bal;
			}
			void getAccountHolder(){
				cout<<"Holder: " << accountHolder <<endl;
			}
			void getAccountNumber(){
				cout << "Account number: " << accountNumber <<endl;
			}
			
			void getAccountType(){
				cout << "Account type: "<<accountType <<endl;
			}
		
			void getBalance(){
				cout << "Balance: " << balance <<endl<< endl;
			}
			void setAccountType(string type){
				accountType = type;
				cout << "Updated account type to  "<< accountType << endl<<endl;
			}
			
			void deposit(double amount){
				if(amount > 0){
					balance += amount;
					cout << amount << " rupees deposited successfully!!"<<endl;
					cout<<"New balance: "<< balance <<endl<<endl;
				}
				else{
					cout<<"Please enter valid amount."<<endl;
					cin >> amount ;
					if(amount > 0){
					balance += amount;
					cout << amount << " rupees deposited successfully!!"<<endl;
					cout<<"New balance: "<< balance <<endl<<endl;
				    }
				}
				
			}
			void withdraw(double amount){
				if(amount > balance){
					cout << "Insufficient balance."<<endl<<endl;
				}else{
					balance -= amount;
					cout << "Withdrawing "<<amount<<endl;
					cout<<"New balance: "<<balance<<endl<<endl;	
				}	
			}
			
			void displayAccountDetails(){
				cout << "Final account details:"<<endl;
				cout << "Holder:" << accountHolder << endl;
				cout << "Account number:" << accountNumber << endl;
				cout << "Type :" << accountType << endl;
				cout << "Balance: "<< balance << endl<<endl;
		    }
		
};
int main(){ 
	BankAccount b1;
	b1.getAccountHolder();
	b1.getAccountNumber();
	b1.getAccountType();
	b1.getBalance();
	int amt;
	cout<<"Enter amount to deposit: ";
	cin >> amt;
	b1.deposit(amt);
	
	cout << "Enter amount to withdraw: ";
	cin >> amt;
	b1.withdraw(amt);
	
	b1.displayAccountDetails();
	BankAccount b2("Akshata Bhosale", 4576376 , "Saving" , 3000);
	b2.getAccountHolder();
	b2.getAccountNumber();
	b2.getAccountType();
	b2.getBalance();
	int amount;
	cout<<"Enter amount to deposit: ";
	cin >> amount;
	b2.deposit(amount);
	
	cout << "Enter amount to withdraw: ";
	cin >> amount;
	b2.withdraw(amount);
	
	string type = "current";
	b2.setAccountType(type);
	b2.displayAccountDetails();
	
	return 0;
}
