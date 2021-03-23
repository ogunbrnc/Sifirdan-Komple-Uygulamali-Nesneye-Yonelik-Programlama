#include "classInheritance.h"
//#include "Person.h"
#include "PersonToEmployee.h"
#include <time.h>
#include "Array.h"

int main()
{
    // Encapsulation: combines data and operations on data in a single unit 
    // Inheritance: creates new objects (classes) from existing objects (classes) 
    // Polymorphism: the ability to use the same expression to denote different operations

    //There are 2 types of inheritances, single inheritance & multiple inheritance
    /*
        Inheritance: allows creation of new classes from existing classes         
        *Derived classes: new classes created from the existing class
        *Base class: the original class 
        Derived class developed from base by adding or altering code
    */

    //derivedClass obj1;
    //derivedClass obj2 = obj1;

    //Constructors of a base class – not inherited in derived class
    /*
    – First, a constructor of the base class executes to initialize the data members inherited from the base class
    – Then, the constructor of the derived class executes to initialize data members declared by the derived class 
    */

    //obj2.print();
    //outputPoint obj3;



    
    /*PERSON CLASS
    srand(time(NULL));
    Teacher teacher1("Murat", "Yucedag", "Software");
    Student studentArray[4] = { {"Ogun","Birinci",1000},{"Duygu","Keydal",1001},{"Eda","Deniz",1002},{"Oguz","Birinci",1003} };
    for (int i = 0; i < 4; i++) {    
        studentArray[i].setStudentGrade(rand() % 100);
    }

    teacher1.passFailStatus(studentArray);
    teacher1.printStudentInformation(studentArray);


    */

    /*
    //PERSONTOEMPLOYEE CLASS
    srand(time(NULL));
    Employee employee1("Ogun", "Birinci", "Software", "Engineer", 4500,5);
    Employee employee2("Eda", "Deniz", "Software", "Engineer", 8500,5);
    Employee employee3("Burak", "Ikinci", "IT", "Programmer", 4500,5);
    Employee employee4("Oguz", "Birinci", "Accounting", "President", 4500,5);
    Manager manager1("Duygu", "Keydal", "Software", "Manager", 8500, 10);
    Manager manager2("Omer", "Selvi", "IT", "Manager", 15000, 25);

    Employee employeeList[] = { employee1,employee2,employee3,employee4 };
    
    manager1.extractEmployees(employeeList);
    manager2.extractEmployees(employeeList);

    manager2.print();
    */
    

    //Array.h
    /*
    sortedArray sArray;
    unsortedArray usArray;
    sArray.addItem(10);
    sArray.addItem(30);
    sArray.addItem(20);
    sArray.addItem(40);
    sArray.printItems();
    
    usArray.addItem(12);
    usArray.addItem(18);
    usArray.addItem(9);
    usArray.addItem(21);
    usArray.printItems();
    */

    return 0;
}

