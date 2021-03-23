#include <iostream>
using namespace std;
/*

THERE NEED TO IMPLEMENT A NEW CONCEPT TO IMPLEMENT SOME ACTIONS IN THE VARIABLES/STRUCTS WITH ADDITIONAL ABILITIES
SOLUTION IS CLASSES/OBJECTS

class: a mechanism in C++ that allows you to combine data and the operations on that data in a single unit


Classes are an expanded concept of data structures; they can contain data members, but they can also contain functions as members.
A class would be the type, and an object would be the variable.

 Class member can be a variable or a function
	-If a member of a class is a variable:It is declared like any other variables.
										 :You cannot initialize a variable when you declare it
	-If a member of a class is a function:Function members can (directly) access any member of the class

	Differences between class and object:
	CLASS:It is a user defined data type.
		 :is a container which collection of variables and methods.
		 :no memory is allocated at the time of the declaration
		 :one class definition should exists only once in a program.
	OBJECT:object is an instance of a class.
		  :sufficient memory space will be allocated for all the variables of the class at the time of the declaration.
		  :for one class multiple objects can be created.

*/

/*
except that they can also include functions and have these new things called access specifiers.
->private members of a class are accessible only from within other members of the same class (or from their "friends").
->protected members are accessible from other members of the same class (or from their "friends"), but also from members of their derived classes.
->Finally, public members are accessible from anywhere where the object is visible.

By default: all members of a class declared with the class keyword have private access for all its members.
*/

class Student {
	string stdName, stdSurname, stdNumber;//thus only accessible from other members of the class

public:
	//class can have more than one constructor
	//A constructor is automatically executed when a class variable is declared.They cannot be called like other functions.
	Student(string name, string surname, string id);// If a class has no constructor(s), C++ provides the default constructor
	Student();//If a class includes constructor(s) with parameter(s), but not the default constructor
	//C++ does not provide the default constructor.Actually this is an function overloading.
	~Student();//Destructors are functions without any type 
	Student(const Student&cpyStudent);//This copy constructor simply performs a copy of its own members

	void printInformation();
	void setStudentInformation(string name, string surname, string number);
	void setName(string name);
	void setSurname(string surname);
	void setNumber(string number);
	string getName() const;
	string getSurname() const;
	string getNumber() const;
};

Student::Student(string name, string surname, string id) {
	cout << "Constructor with parameters." << endl;
	stdName = name;
	stdSurname = stdSurname = surname;
	stdNumber = id;
}
Student::Student() {
	cout << "Constructor with no parameters." << endl;
}
Student::~Student() {
	cout << "Destructor." << endl;
}
Student::Student(const Student& cpyStudent) {
	stdName = cpyStudent.stdName;
	stdSurname = cpyStudent.stdSurname;
	stdNumber = cpyStudent.stdNumber;
}
//like the std::cout 
void Student::printInformation() {
	cout << "Student: " << stdName << " " << stdSurname << endl;
	cout << "Student ID Number: " << stdNumber << endl;
}
void Student::setStudentInformation(string name, string surname, string number) {
	stdName = name;
	stdSurname = surname;
	stdNumber = number;
}
void Student::setName(string name) {
	stdName = name;
}
void Student::setSurname(string surname) {
	stdSurname = surname;
}
void Student::setNumber(string number) {
	stdNumber = number;
}
string Student::getName() const {
	return stdName;
}
string Student::getSurname() const {
	return stdSurname;
}
string Student::getNumber() const {
	return stdNumber;
}