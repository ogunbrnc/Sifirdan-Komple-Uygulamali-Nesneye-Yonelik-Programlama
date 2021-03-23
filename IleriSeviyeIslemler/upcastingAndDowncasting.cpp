//#include "upcastingDowncasting.h"
#include "Vehicle.h"
#include "Person.h"
#include "Shape.h"

/*

!!UPCASTING!!
Upcasting is a process of treating a pointer or a reference of derived class object as a base class pointer.

	Employee* emp;
	Manager m1("Steve", "Kent", 3000, 0.2);
	emp = &m1;

when you upcast an object, you will be able to access only member functions and data members that are defined in the base class
	emp->FirstName;
	emp->salary;
!!DOWNCASTING!!
Downcasting is an opposite process for upcasting. It converts base class pointer to derived class pointer.
	Employee* emp;
	Manager m1("Steve", "Kent", 3000, 0.2);
	emp = &m1; 
	Manager* m2 = (Manager*)(emp);

*/
/*
EMPLOYEE      MANAGER  
name			name
surname			surname	
salary			salary
display			display
				department
				increaseSalary

*/

int main()
{/*
	Employee* emp;
	Manager mng1("Ogun", "Birinci", 3500,"CS");

	emp = &mng1;//upcasting process. We can access only the functions which declared in employee class.
	emp->displayInformation();
	//you will be able to access only member functionsand data members that are defined in the base class :









	// It converts base class pointer to derived class pointer.
	//For example, a Manager is always a Person; But a Person is not always a Manager.
	Manager* mng2 = (Manager*)(emp);

	mng2->increaseSalary();
	cout << emp->empName << endl;//downcasting process. 
	emp->displayInformation();
	cout << mng2->mngDepartment << endl;
	emp->displayInformation();






	cout << "REFERENCE PARAMETER\n----------------------------------------------------" << endl;
	Person person1("Ogun");
	Man man1("Ogun", "Birinci");
	person1.printInfo();
	man1.printInfo();
	cout << "----------------------------------------------------" << endl;
	print(person1);
	print(man1);
	cout << "POINTER\n----------------------------------------------------" << endl;
	Person* person2;
	Man* man2;
	person2 = new Person("Ogun");
	man2 = new Man("Ogun", "Birinci");
	person2->printInfo();
	man2->printInfo();
	cout << "----------------------------------------------------" << endl;
	print2(person2);
	print2(man2);

	cout << "VALUE PARAMETER\n----------------------------------------------------" << endl;
	person1.printInfo();
	man1.printInfo();
	cout << "----------------------------------------------------" << endl;
	print3(person1);
	print3(man1);

	
	Abstract class: a class with one or more pure virtual functions 
	Pure virtual functions: – Do not have definitions (bodies have no code)
	 Example:  virtual void draw() = 0;
	 – You cannot create objects of an abstract class 
	 – Can contain instance variables, constructors, and functions that are not pure virtual 
	 – Class must provide the definitions of constructor/functions that are not pure virtual
	
	

	firstClass *firstPointer;
	secondClass secondObject;

	secondObject.print();
	firstPointer = &secondObject;

	firstPointer->print();
	*/
	//VEHICLE
	/*
	Vehicle* vPtr[] = { new Car(125.850,"BMW"),new Motorcycle(37.500,"Honda") };
	int which_vehicle;
	char inputVehicle;
	do {
		fflush(stdin);
		cout << "Enter vehicle and input ";		
		cin >> which_vehicle>>inputVehicle;
		switch (inputVehicle) {
			case 'U':
				vPtr[which_vehicle]->increaseSpeed();
				vPtr[which_vehicle]->displayInformation();
				break;
			case 'D':
				vPtr[which_vehicle]->decreaseSpeed();
				vPtr[which_vehicle]->displayInformation();
				break;
			case 'C':
				vPtr[which_vehicle]->stopEngine();
				vPtr[which_vehicle]->displayInformation();
				break;
			case 'S':
				vPtr[which_vehicle]->startEngine();
				vPtr[which_vehicle]->displayInformation();
				break;
			default:
				cout << "Enter valid input" << endl;
				break;
		}
	} while (which_vehicle != -1);
	*/
	
	
	//Person.h
/*
	Person *pArr[] = { new TurkishPerson("Ogun"),new TurkishPerson("Duygu"),new DeutschePerson("Thomas"),new DeutschePerson("Carl")};
	int numberOfPerson = sizeof(pArr)/sizeof(pArr[0]);
	for (int i = 0; i < numberOfPerson; i++) {
		for (int j = 0; j < numberOfPerson; j++) {
			if (i != j) {
				pArr[i]->sayHiTo(*pArr[j]);
			}
		}
		cout << "\n";
	}
*/
	

Shape* sArr[] = { new Rectangle(4.0,5.0),new Rectangle(3.5,2.5),new Rectangle(8.5,4.3),new Circle(3.2),new Circle(3.8) };
int shapeNumber = sizeof(sArr) / sizeof(sArr[0]);
for (int i = 0; i < shapeNumber; i++) {
	sArr[i]->calculateArea();
	sArr[i]->calculatePerimeter();
	sArr[i]->display();
}

}


