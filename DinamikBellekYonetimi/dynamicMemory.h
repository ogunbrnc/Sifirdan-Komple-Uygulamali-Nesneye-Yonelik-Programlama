#include <iostream>
using  namespace std;

class Example {
public:
	Example() {
		cout << "Constructor work." << endl;
	}
	~Example() {
		cout << "Destructor work." << endl;
	}
	int x, y;
	void print();
};
void Example::print() {
	cout << "X value:" << x << " Y value:" << y << endl;
}