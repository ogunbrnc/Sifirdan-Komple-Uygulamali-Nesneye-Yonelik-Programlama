#include <iostream>
using namespace std;

class Employee {
public:
	string empName, empSurname;
	double empSalary;
	Employee(string name, string surname, double salary);
	void displayInformation() {
		cout << "Name:" << empName << endl;
		cout << "Surname:" << empSurname << endl;
		cout << "Salary:" << empSalary << endl;
	}
};
Employee::Employee(string name, string surname, double salary) {
	empName = name;
	empSurname = surname;
	empSalary = salary;
}


class Manager :public Employee {
public:
	string mngDepartment;
	Manager(string name, string surname, double salary,string department) :Employee(name, surname, salary) {
		mngDepartment = department;
	};
	void displayInformation() {
		Employee::displayInformation();
		cout << "Department:" << mngDepartment << endl;
	}
	void increaseSalary() {
		empSalary += 200;
	}
};



class Person{
public:
	virtual void printInfo() {
		cout << "Name:" << personName << endl;
	}
	Person(string name) {
		personName = name;
	}
private:
	string personName;
};

class Man :public Person {
public:
	void printInfo() {
		Person::printInfo();
		cout << "Surname:" << personSurname << endl;
	}
	Man(string name = "", string surname = "") :Person(name) {
		personSurname = surname;
	}
private:
	string personSurname;
};

void print(Person &personType) {
	personType.printInfo();
}
void print2(Person* personType) {
	personType->printInfo();
}
void print3(Person personType) {
	personType.printInfo();
}


class firstClass {
public:
	virtual void print() = 0;
};

class secondClass:public firstClass {
public:
	void print() {
		cout << "Second class print function worked." << endl;
	}
};