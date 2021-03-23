#include "studentClass.h"
#include "Matrix.h"
#include "Date.h"
#include "bankAccount.h"
#include "Triangle.h"
#include "complexNumber.h"
#include "Array.h"

#define LIST_SIZE 5

/*
User-defined header files are enclosed in double quotes (" ")
System-provided header files are enclosed between angular brackets (< >)
*/



int main()
{
	
	//Student student1("Ogun","Birinci","1324");//Student is an class name, student1 is an object name
	//The most important property of a class is that it is a type, and as such, we can declare multiple objects of it

	//Student student2; //Each one of them has its own member variables and member functions.
	//This is because each object of class Student has its own name,surname and ID,
	/*FOR THE MEMORY:
	The C++ compiler generates
	only one physical copy of a member function of a class and each class object executes the same copy of the member function
	Memory is allocated only for the member variables of each class object
	
	*/

	/*
	student1.setStudentInformation("Ogun", "Birinci", "1234");//The dot (.) is the member access operator
	student1.printInformation();
	*/

	/*
	Arithmetic operators cannot be used on class objects unless the operators are overloaded
	Cannot use relational operators to compare two class objects for equality

	Built-in operations that are valid for class objects: –> Member access (.) &  Assignment (=)

	*/
	/*
	if (true) {//to show the local-global variables.
		Student studentForDestructor;
	}

	student2 = student1;
	student2.printInformation();

	Student student3 = { "Duygu","Keydal","1234" };//we can already do that.
	student3.printInformation();

	Student student4{ "Eda","Deniz","1234" };
	student4.printInformation();

	Student studentArray[5];//constructor works 5 times.
	*/


	
	//MATRIX CLASS 
	
	int row, col;
	cout << "Please enter the row and column number:";
	cin >> row >> col;
	
	Matrix mainMatrix(row, col);
	Matrix mainMatrix2(row, col);

	mainMatrix.randomSet();
	mainMatrix2.identityMatrixSet();

	mainMatrix.display();
	mainMatrix2.display();

	mainMatrix.setValue(0, 0, 5);
	mainMatrix2.setValue(2, 2, 2);

	mainMatrix.display();
	mainMatrix2.display();
	
	mainMatrix.addMatrix(mainMatrix2);
	Matrix mainMatrix3 = mainMatrix;
	mainMatrix3.display();
	
	
	/*
	//DATE CLASS 
	Date mainDate(19, 07, 1999);
	Date mainDate2;
	


	mainDate.displayDate();
	mainDate2.displayDate();

	for (int i = 0; i < 30; i++) {
		mainDate.increaseDay();
		mainDate.displayDate();
	}

	mainDate.compareDate(mainDate2);
	Date mainDate3 = mainDate2;
	*/

	
	//BANK ACCOUNT CLASS
	/*
	bankAccount acc1("Ogun", "Birinci");
	bankAccount acc2("Duygu", "Keydal", 1500, "05079140799");
	
	acc1.displayProfile();
	acc2.displayProfile();

	acc1.credit(1500);
	cout << "After credit function" << endl;
	acc1.displayProfile();
	cout << "After debit function" << endl;
	acc1.debit(1200);
	acc1.displayProfile();

	acc1.sendMoney(acc2, 200);
	cout << "After sendMoney function" << endl;
	acc1.displayProfile();
	acc2.displayProfile();

	acc2.debit(1500);
	acc2.displayProfile();
	acc2.credit(1200);
	acc2.displayProfile();
	bankAccount acc3 = acc2;
	*/

	/*
	//TRIANGLE CLASS
	float sideA, sideB, sideC;

	cout << "Please enter the sides(A-B-C):" << endl;
	cin >> sideA >> sideB >> sideC;
	Triangle triangle1(sideA, sideB, sideC);
	Triangle triangle2(triangle1);
	cout << "Area is: " << triangle1.calculateArea() << endl;



	triangle1.triangleType();
	triangle2.setValue(3, 5, 8);
	cout << triangle2.getSideA() << endl;
	*/

	/*
	//COMPLEX NUMBER CLASS
	complexNumber number1(2,-5);
	complexNumber number2(-4, 7);
	complexNumber additionResult;
	complexNumber multiplicationResult;
	complexNumber subtractionResult;
	complexNumber constantResult;

	cout << "First Complex:";
	number1.displayComplex();
	cout << "Second Complex:";
	number2.displayComplex();

	additionResult = number1.addComplex(number2);
	cout << "Addition Result:";
	additionResult.displayComplex();

	multiplicationResult = number1.multiplyComplex(number2);
	cout << "Multiplication Result:";
	multiplicationResult.displayComplex();
	
	subtractionResult = number1.subtractComplex(number2);
	cout << "Subtraction Result:";
	subtractionResult.displayComplex();

	constantResult = number1.multiplyConstant(3);
	cout << "Constant Result:";
	constantResult.displayComplex();
	*/

	
	//ARRAY CLASS
	/*
	Array mainArray(10);
	mainArray.AddItem(3);
	mainArray.AddItem(8);
	mainArray.AddItem(6);
	mainArray.AddItem(5);
	mainArray.AddItem(12);
	mainArray.AddItem(3);
	mainArray.printItems();
	mainArray.removeItem(3);
	mainArray.printItems();
	mainArray.AddItem(51);
	mainArray.AddItem(102);
	mainArray.AddItem(104);
	mainArray.AddItem(182);
	mainArray.printItems();
	mainArray.removeIndexItem(3);

	cout << "First Array" << endl;
	mainArray.printItems();

	Array mainArray2(mainArray);
	cout << "Second Array" << endl;
	mainArray2.printItems();

	Array mainArray3 = mainArray;
	cout << "Third Array" << endl;
	mainArray3.printItems();
	
	*/
	



	return 0;
}

