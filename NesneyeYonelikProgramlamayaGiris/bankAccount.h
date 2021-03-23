#include <iostream>
#include <string>
using namespace std;


class bankAccount {
public:
	bankAccount(string name,string surname, int balance=0,string phone_number="");
	bankAccount(const bankAccount& oth);
	~bankAccount();
	bool controlNameSurname(string nameOrSurname);
	bool controlPhoneNumber(string phoneNumber);
	void displayProfile();
	void credit(int);
	void debit(int);
	void sendMoney(bankAccount& othAccount, int amount);
	void setPersonName(string name) { personName = name; };
	void setPersonSurname(string surname) { personSurname = surname; };
	void setPersonPhone(string phone) { personPhone = phone; };
	void setPersonBalance(int balance = 0);
	int getPersonBalance() const { return accountBalance; };
	string getPersonName()const { return personName; };
	string getPersonSurname() const{ return personSurname; };
	string getPersonPhone() const { return personPhone; };

private:
	int accountBalance;
	string personName, personSurname, personPhone;
};

bankAccount::~bankAccount() {
	cout << "Bank Account destroyed." << endl;
}
bankAccount::bankAccount(const bankAccount& oth) {
	personName = oth.personName;
	personSurname = oth.personSurname;
	personPhone = oth.personPhone;
	accountBalance = oth.accountBalance;
	cout << "Bank Account copied to target." << endl;
}

bankAccount::bankAccount(string name, string surname, int balance, string phone_number) {
	while (!(controlNameSurname(name))) {
		cout << "Invalid name,please enter your name: ";
		getline(cin, name);
	}
	personName = name;
	while (!(controlNameSurname(name))) {
		cout << "Invalid surname,please enter your surname: ";
		getline(cin, surname);
	}
	personSurname = surname;
	while (!(controlPhoneNumber(phone_number))) {
		cout << "Invalid phone,please enter your phone: ";
		getline(cin, phone_number);
	}
	personPhone = phone_number;
	setPersonBalance(balance);
}

bool bankAccount::controlNameSurname(string nameOrSurname) {
	for (unsigned i = 0; i < nameOrSurname.length(); i++) {
		if (!((nameOrSurname.at(i) >= 'A' && nameOrSurname.at(i) <= 'Z') || (nameOrSurname.at(i) >= 'a' && nameOrSurname.at(i) <= 'z'))){
			return false;
		}
	}
	return true;
}
bool bankAccount::controlPhoneNumber(string phoneNumber) {
	if (phoneNumber.empty()) {
		return true;
	}
	if (phoneNumber.length() != 11) {
		return false;
	}
	for (unsigned i = 0; i < phoneNumber.length(); i++) {
		if (!(phoneNumber.at(i) >= '0' && phoneNumber.at(i) <= '9')){
			return false;
		}
	}
	return true;
}
void bankAccount::setPersonBalance(int balance) {
	if (balance < 0) {
		cout << "Balance cannot be negative number." << endl;
		accountBalance = 0;
	}
	else {
		accountBalance = balance;
	}
}
void bankAccount::displayProfile() {
	cout << "----------------------------" << endl;
	cout<<"Name: "<<personName << "\n" <<"Surname: "<<personSurname << endl;
	if (!personPhone.empty()) {
		cout << "Phone Number:" << personPhone << endl;
	}
	else {
		cout << "Phone Number: None" << endl;
	}
	cout << "Balance: " << accountBalance << endl;
}
void bankAccount::credit(int amount)
{
	accountBalance+=amount;
}
void bankAccount::debit(int amount)
{
	if (amount > accountBalance)
		cout << "Debit amount exceeded account balance.\n" << endl;
	else
		accountBalance-=amount;
}
void bankAccount::sendMoney(bankAccount& othAccount, int amount) {
	if (accountBalance < amount) {
		cout << "Debit amount exceeded account balance.\n" << endl;
	}
	else {
		othAccount.credit(amount);
		accountBalance -= amount;
	}
}