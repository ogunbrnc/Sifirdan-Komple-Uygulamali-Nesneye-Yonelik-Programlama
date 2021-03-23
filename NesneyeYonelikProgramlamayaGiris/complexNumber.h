#include <iostream>

using namespace std;
class complexNumber {
private:
	int real, imag;
public:
	complexNumber(int r = 0, int i = 0);
	~complexNumber();
	complexNumber(const complexNumber& oth);
	int getReal() const  { return real; };
	int getImag() const  { return imag; };
	void setValue(int r, int i) { real = r; imag = i; };
	complexNumber addComplex(const complexNumber & oth);
	complexNumber multiplyComplex(const complexNumber & oth);
	complexNumber subtractComplex(complexNumber & oth);
	complexNumber multiplyConstant(int constant);
	void multiplyMinus();
	void displayComplex();
};
complexNumber::complexNumber(int r,int i) {
	cout << "Complex Number created." << endl;
	real = r;
	imag = i;
}

complexNumber::~complexNumber() {
	cout << "Complex Number destroyed." << endl;
}
complexNumber::complexNumber(const complexNumber& oth) {
	real = oth.real;
	imag = oth.imag;
	cout << "Complex Number copied to target." << endl;
}

complexNumber complexNumber::addComplex(const complexNumber & oth) {
	complexNumber result;
	result.real = real + oth.real;
	result.imag = imag + oth.imag;
	return result;
}
complexNumber complexNumber::subtractComplex(complexNumber & oth) {
	complexNumber result;
	oth.multiplyMinus();
	result = addComplex(oth);
	return result;
}
void complexNumber::multiplyMinus() {
	real *= -1;
	imag *= -1;	
}
complexNumber complexNumber::multiplyConstant(int constant) {
	complexNumber result;
	result.real = real*constant;
	result.imag = imag*constant;
	return result;
}
complexNumber complexNumber::multiplyComplex(complexNumber const& oth) {
	complexNumber result;
	result.real = real * oth.real - imag * oth.imag;
	result.imag = real * oth.imag + imag * oth.real;
	return result;
}
void complexNumber::displayComplex() {
	imag>=0 ? cout << real << "+" <<imag << "i" << endl: cout << real << imag << "i" << endl ;
}