#include <iostream>
#include <string>
using namespace std;

class Person {
	string name;
public:
	Person(string pName) {
		name = pName;
	}
	const string getName() const { return name; }
	virtual string getNation() const { return " ";}
	virtual void sayHiTo(const Person& person) {cout << name << " says: Hi " << person.name << "\n";}
};

class DeutschePerson : public Person {
public:
	DeutschePerson(string pName) : Person(pName) {}
	string getNation() const {
		return "Deutsche";
	}
	void sayHiTo(const Person& person) {
		if (getNation() == person.getNation())
			cout << getName() << " says: Hallo " << person.getName() << "\n";
		else Person::sayHiTo(person);
	}
};

class TurkishPerson : public Person {
public:
	TurkishPerson(string name) : Person(name) {}

	string getNation() const {
		return "Turkish";
	}
	void sayHiTo(const Person& person) {
		if (getNation() == person.getNation())
			cout << getName() << " says: Merhaba " << person.getName() << "\n";
		else Person::sayHiTo(person);
	}
};