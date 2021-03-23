#include "dynamicMemory.h"

int main()
{
    Example exObj, * exPtr;//one of them is object and second is pointer.
    exPtr = &exObj;//exPtr points to exObj.
                    //exPtr store the address  of exObj.
    exObj.x = 5;
    exObj.y = 15;
    exObj.print();

    (*exPtr).x = 12;// ( ) used because dot operator has higher precedence than dereferencing operator 
    exPtr->y = 13;//use member access operator arrow (->)
    exPtr->print();

    //to create dynamic variables using pointer, we can use new and delete operators.
    //we can allocate two types;single variable or array of variables.
    //for the integer type.
    int *ptr = new int;//creates a variable during program execution somewhere in memory, and stores address of allocated memory in ptr.
    Example* ptrEx = new Example;
    ptrEx->x = 2;
    ptrEx->y = 10;
    ptrEx->print();
    delete ptrEx;






    //Single-Dim.
    int* ptrArray = new int[5];
    Example* ptrExArray = new Example[5];
    for (int i = 0; i < 5; i++) {
        ptrExArray[i].x = i;
        ptrExArray[i].y = i * i;
        ptrExArray[i].print();
    }
    delete[] ptrExArray;







    
    //Multi-Dim.
    int** Array2D = new int* [5];
    Example** ExampleArray2D = new Example* [5];

    for (int i = 0; i < 5; i++) {
        ExampleArray2D[i] = new Example[5];
    }
    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 5; j++) {
            ExampleArray2D[i][j].x = i;
            ExampleArray2D[i][j].y = j;
            ExampleArray2D[i][j].print();
        }
    }
    
    for (int i = 0; i < 5; i++) {
        delete[] ExampleArray2D[i];
    }
    delete[] ExampleArray2D;
}
