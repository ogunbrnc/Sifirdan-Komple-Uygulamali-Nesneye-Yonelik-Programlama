#include <iostream>
using namespace std;

class Person {
protected:
	string personName, personSurname;
public:
	Person(string name = "", string surname = "") { personName = name; personSurname = surname;};
	string getPersonName() { return personName; };
	string getPersonSurname() { return personSurname;};
	void setPersonName(string name) { personName = name; };
	void setPersonSurname(string surname) { personSurname = surname; };
	void print() {
		cout << "Name:" << personName << endl;
		cout << "Surname:" << personSurname << endl;
	}
};

class Student :public Person {
private:
	int studentID, studentGrade;
	bool passOrFail;
public:
	Student();
	Student(string name, string surname, int ID) :Person(name, surname) {
		studentID = ID;
	}
	int getStudentID() { return studentID; };
	void setStudentID(int ID) { studentID = ID; };
	int getStudentGrade() { return studentGrade; };
	void setStudentGrade(int grade) { studentGrade = grade; };
	int getPassOrFail() { return passOrFail; };
	void setPassOrFail(bool passFail) { passOrFail = passFail; };
	void print() {
		Person::print();
		cout << "Student ID:" << studentID << endl;
		cout << "Student Grade:" << studentGrade << endl;
	}
};

class Teacher :public Person {
private:
	string department;
public:
	Teacher(string name, string surname, string dep) :Person(name, surname) {
		department = dep;
	}
	string getDepartment() { return department; };
	void setDepartment(string dep) { department = dep; };
	void print() {
		Person::print();
		cout << "Department:" << department << endl;
	}
	void passFailStatus(Student *studentArray);
	void printStudentInformation(Student *studentArray);
};
void Teacher::passFailStatus(Student *studentArray) {
	float average=0.0;
	for (int i = 0; i < sizeof(studentArray); i++) {
		average += studentArray[i].getStudentGrade();
	}
	average = (float)average / sizeof(studentArray);
	cout << "Class average:" << average << endl;
	cout << "------------------" << endl;
	for (int i = 0; i < sizeof(studentArray); i++) {
		if (studentArray[i].getStudentGrade() >= average) {
			studentArray[i].setPassOrFail(true);
		}
		else {
			studentArray[i].setPassOrFail(false);
		}
	}
}
void Teacher::printStudentInformation(Student *studentArray) {
	for (int i = 0; i < sizeof(studentArray); i++) {
		studentArray[i].print();
		if (studentArray[i].getPassOrFail() == true) {
			cout << "Status: Pass" << endl;
		}
		else {
			cout << "Status: Fail" << endl;
		}
		cout<<"------------------"<<endl;
	}
}