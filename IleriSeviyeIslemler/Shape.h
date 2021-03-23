#include <iostream>
using namespace std;
#define pi 3.14159265358979

class Shape {
private:
	double shapeArea;
	double shapeCircumference;
public:
	double getArea()const { return shapeArea; };
	double getCircumF()const { return shapeCircumference; };
	void setArea(double shape_area) { shapeArea = shape_area; };
	void setCircumF(double c_fr) { shapeCircumference = c_fr; };
	virtual void calculateArea() = 0;
	virtual void calculatePerimeter() = 0;
	virtual void display() = 0;
};

class Circle:public Shape {
private:
	double radius;
public:
	Circle(double r) { radius = r; };
	void calculateArea() {
		double area = pi * pow(radius, 2);
		setArea(area);	
	}
	void calculatePerimeter() {
		double circum_fr = 2 * pi * radius;	
		setCircumF(circum_fr);
	}
	void display() {
		cout << "-----------Circle Information----------" << endl;
		cout << "Radius:" << radius << endl;
		cout << "Area:" << getArea() << endl;
		cout << "Circumference:" << getCircumF() << endl;
	}
};

class Rectangle :public Shape {
private:
	double width,height;
public:
	Rectangle(double w, double h) { width = w; height = h; };
	void calculateArea() {
		double area = width*height;
		setArea(area);
	}
	void calculatePerimeter() {
		double circum_fr = 2 * (width + height);
		setCircumF(circum_fr);
	}
	void display() {
		cout << "-----------Rectangle Information----------" << endl;
		cout << "Width:" << width << " Height: " << height << endl;
		cout << "Area:" << getArea() << endl;
		cout << "Circumference:" << getCircumF() << endl;
	}
};

