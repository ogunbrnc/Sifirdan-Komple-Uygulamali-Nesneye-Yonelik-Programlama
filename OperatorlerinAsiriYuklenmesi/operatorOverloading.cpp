#include "operatorOverloading.h"
/*
Assignment (=) and member selection (.) are the only built-in operations on classes 
• Other operators cannot be applied directly to class objects
C++ allows you to extend the definitions of most of the operators to work with classes:
     • relational operators, (>, <, >=, ==, etc) 
     • arithmetic operators, (+, -, *, / etc) 
     • the insertion operator (<<), the extraction operator (>>), 

*/

int main()
{   
    Person person1("Ogun","Birinci",21);
    Person person2("Ogun", "Birinci", 22);
    Person person3("Duygu", "Keydal", 22);
    person1.displayPerson();
    person1++;//postfix.
    person1.displayPerson();
    ++person1;//prefix
    person1.displayPerson();

    cout << "\nMEMBER FUNCTION ==" << endl;

    person1 == person2 ? cout << "Same person"<<endl : cout << "Not same person."<<endl;
    person1 == person3 ? cout << "Same person"<<endl : cout << "Not same person."<<endl;

    cout << "\nNON-MEMBER FUNCTION !=" << endl;
    person1 != person2 ? cout << "Not Same person"<<endl : cout << "Same person."<<endl;
    person1 != person3 ? cout << "Not Same person"<<endl : cout << "Same person."<<endl;


   


    
}


