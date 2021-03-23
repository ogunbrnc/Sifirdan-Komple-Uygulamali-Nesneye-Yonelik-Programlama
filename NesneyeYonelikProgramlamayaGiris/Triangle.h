#include <iostream>
#include <string>
using namespace std;


class Triangle {
public:
    Triangle(float a, float b, float c);
    ~Triangle();
    Triangle(const Triangle& oth);
    float getSideA() const { return sideA; };
    float getSideB() const { return sideB; };
    float getSideC() const { return sideC; };
    void setValue(float a, float b, float c) { 
        while (!isTriangle(a, b, c)) {
            cout << "Please enter the sides(A-B-C):" << endl;
            cin >> a >> b >> c;
        }
        sideA = a;
        sideB = b;
        sideC = c;
    };
    bool isTriangle(float a,float b,float c);
    bool isEquilateral();
    bool isScalene();
    bool isIsosceles();
    float calculateArea();
    void triangleType();
private:
    float sideA, sideB, sideC;
};

Triangle::Triangle(float a=0, float b=0, float c=0) {
    while(!isTriangle(a,b,c)) {
        cout << "Please enter the sides(A-B-C):" << endl;
        cin >> a >> b >> c;
    }
    sideA = a;
    sideB = b;
    sideC = c;
    cout << "Triangle created." << endl;
}
Triangle::~Triangle() {
    cout << "Triangle destroyed." << endl;
}

Triangle::Triangle(const Triangle& oth) {
    sideA = oth.sideA;
    sideB = oth.sideB;
    sideC = oth.sideC;
    cout << "Triangle copied to target" << endl;
}

bool Triangle::isTriangle(float a,float b,float c)
{
    if (!((abs(b - c) < a) && (a < b + c))) {
        cout << "Invalid A." << endl;
        return false;
    }
    if (!((abs(a - c) < b) && (b < a + c))){
        cout << "Invalid B." << endl;
        return false;
    }
    if (!((abs(a - b) < c) && (c < a + b))){
        cout << "Invalid C." << endl;
        return false;
    }
    return true;   
}
bool Triangle::isEquilateral()
{
    return sideA == sideB && sideB == sideC;
}
bool Triangle::isIsosceles()
{
    if (isEquilateral())
        return true;
    else
        return sideA == sideB || sideB == sideC || sideA == sideC;
}
bool Triangle::isScalene()
{
    return !isIsosceles();
}
float Triangle::calculateArea() {
    float area;
    if (isEquilateral()) {
        area = (pow(sideA, 2) * sqrt(3)) / 4;
        return area;
    }
    float perimeter = (sideA + sideB + sideC) / 2;
    area = sqrt(perimeter * (perimeter - sideA) * (perimeter - sideB) * (perimeter - sideC));
    return area;
}
void Triangle::triangleType() {
    if (isEquilateral()) {
        cout << "Equilateral Triangle" << endl;
    }
    else if (isIsosceles()) {
        cout << "Isosceles Triangle" << endl;
    }
    else {
        cout << "Scalene Triangle" << endl;
    }
}
