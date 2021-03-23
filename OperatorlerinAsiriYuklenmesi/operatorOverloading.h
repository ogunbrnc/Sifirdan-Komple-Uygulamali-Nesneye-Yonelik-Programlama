#include <iostream>
using namespace std;

/*OPERATOR OVERLOADING PART
Syntax:
	returnType operator operatorSymbol(formal parameterList)


 Cannot change number of parameters an operator takes
 Cannot create new operators

*/

/*FRIEND FUNCTION PART
	NONMEMBER-FUNCTION
	"friend" doesn’t appear in function definition
	it appears only in the function prototype in the class definition
	Its declaration can be placed within the private, protected or public part of the class. 
	• However, they are typically placed before any member function declaration


	 To overload (), [], ->, or = for a class, the function must be a member of the class
	 If the leftmost operand of op is an object of a different type, the overloading function must be a nonmember (friend) of the class
	 Functions that overload the insertion operator (<<) and the extraction operator (>>) for a class must be nonmembers, that is,  friend of the class
*/





class Person {
	friend void PersonFriend(Person personObject);
	friend bool operator !=(const Person& firstObj, const Person& secondObj);
	friend ostream& operator<<(ostream&, const Person&);
	friend istream& operator>>(istream&, Person&);
private:
	string personName, personSurname;
	int personAge;
public:
	Person() {
		personName = "";
		personSurname = "";
		personAge = 0;
	}
	Person(string name,string surname,int age);
	void displayPerson();
	void operator ++();
	void operator ++(int);
	bool operator ==(const Person& oth);
};

Person::Person(string name,string surname,int age) {
	personName = name;
	personSurname = surname;
	personAge = age;
}
void Person::displayPerson() {
	cout << "Name:" <<personName<< endl;
	cout << "Surname:" <<personSurname<< endl;
	cout << "Age:" <<personAge<< endl;
}
void Person::operator ++() {
	personAge+=1;
}
void Person::operator ++(int) {
	personAge+=1;
}
bool Person::operator ==(const Person &oth) {
	return (personName == oth.personName && personSurname == oth.personSurname);
}

void PersonFriend(const Person personObject) {
	cout << "Name:" << personObject.personName << endl;
	cout << "Surname:" << personObject.personSurname << endl;
	cout << "Age:" << personObject.personAge << endl;
}

bool operator !=(const Person& firstObj, const Person& secondObj) {
	return !(firstObj.personName == secondObj.personName && firstObj.personSurname == secondObj.personSurname);
}

ostream& operator<<(ostream& osObject, const Person& personObject) {
	osObject << "Name:" << personObject.personName << endl
		<< "Surname:" << personObject.personSurname << endl
		<< "Age:" << personObject.personAge << endl;
	return osObject;
}
istream& operator>>(istream& isObject, Person& personObject) {
	isObject >> personObject.personName >> personObject.personSurname >> personObject.personAge;
	return isObject;
}