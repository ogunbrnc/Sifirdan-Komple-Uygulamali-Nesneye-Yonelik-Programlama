#include <iostream>

using namespace std;
/*
syntax:
	class derivedClassName:access-level baseClassName
	access-level: used to specify how base class members are accessible to derived class 
		private:(default)->none of the members of base class is accessible by the derived class
		public:->the derived class follow the same access permission as in the base class 
		protected:-> the public and the protected members inherited from the base class can be accessed in the derived class as protected members 

	In principle, a publicly derived class inherits access to every member of a base class except:
		its constructors and its destructor 
		its assignment operator members (operator=) 
		its friends 
		its private members
*/

//for the single inheritance:
class baseClass{
private:
	int x;
public:
	void setXValue(int mainX);
	int getXValue();
	void print();//for the function override.
	baseClass();
	~baseClass();
	baseClass(const baseClass&);
};
baseClass::baseClass() {
	cout << "Base class constructor worked." << endl;
}
baseClass::~baseClass() {
	cout << "Base class destructor worked." << endl;
}
baseClass::baseClass(const baseClass &baseEx) {
	cout << "Base class copy constructor worked." << endl;
	x = baseEx.x;
}
void baseClass::setXValue(int mainX) {
	x = mainX;
}
int baseClass::getXValue() {
	return x;
}
void baseClass::print() {
	cout << "From base class" << endl;
}


class derivedClass:public baseClass{//Derived class can include additional members 
private:							//Derived class can redefine public member functions of the base class 
	int y;
public:
	void setYValue(int mainY);
	int getYValue();
	void print();//same type, same numbers.Otherwise this will be function overloading.
	derivedClass();
	~derivedClass();
	derivedClass(const derivedClass&);
};
derivedClass::derivedClass() {
	cout << "Derived class constructor worked." << endl;
}
derivedClass::~derivedClass() {
	cout << "Derived class destructor worked." << endl;
}
derivedClass::derivedClass(const derivedClass& baseEx) {
	cout << "Derived class copy constructor worked." << endl;
	y = baseEx.y;
}
void derivedClass::setYValue(int mainY) {
	y = mainY;
}
int derivedClass::getYValue() {
	return y;
}
void derivedClass::print() {
	baseClass::print();//also this can be without declare any variable.
	cout << "From derived class" << endl;
}

//for the multiple inheritance

class Point {
private:
	int x, y;
public:
	Point();
	Point(int, int);
	~Point();
	Point(const Point& pointEx);
	
};
Point::Point() {
	cout << "Point class constructor worked" << endl;
}
Point::Point(int mainX,int mainY) {
	cout << "Point class constructor worked" << endl;
	x = mainX;
	y = mainY;
}
Point::~Point() {
	cout << "Point class destructor worked" << endl;
}
Point::Point(const Point& pointEx) {
	cout << "Point class copy constructor worked" << endl;
}
class OutputScreen{
public:
	OutputScreen();
	~OutputScreen();
	void print(int , int );
};
OutputScreen::OutputScreen() {
	cout << "OutputScreen class constructor worked" << endl;
}
OutputScreen::~OutputScreen() {
	cout << "OutputScreen class destructor worked" << endl;
}

void OutputScreen::print(int mainX,int mainY) {
	cout << "X value:" << mainX << " Y value:" << mainY << endl;
}

class outputPoint :public Point, public OutputScreen {//if we don't write public for both of them, it will understand default private!
public:
	outputPoint();
	~outputPoint();
};

outputPoint::outputPoint() {
	cout << "outputPoint class constructor worked" << endl;
}
outputPoint::~outputPoint() {
	cout << "outputPoint class destructor worked" << endl;
}
