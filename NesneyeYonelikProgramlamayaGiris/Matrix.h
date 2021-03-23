#include <iostream>
#include <time.h>
#include <stdlib.h>


using namespace std;

class Matrix {
private:
	int row, col;
	int** matrix;
public:
	Matrix(int r=5, int c=5);
	~Matrix();
	Matrix(const Matrix& oth);
	int getRowNumber();
	int getColumnNumber();
	void setValue(int r, int c, int value);
	void randomSet();
	void identityMatrixSet();
	void display();
	void addMatrix(Matrix &othMatrix);
};


Matrix::Matrix(int r,int c) {
	row = r;
	col = c;
	matrix = new int* [row];
	for (int i = 0; i < row; i++)
		matrix[i] = new int[col];
	cout << "Matrix created." << endl;
}
Matrix::~Matrix() {
	for (int i = 0; i < row; ++i) {
		delete [] matrix[i];
	}
	delete[] matrix;
	cout << "Matrix destroyed." << endl;
}
Matrix::Matrix(const Matrix& oth) {
	row = oth.row;
	col = oth.col;
	matrix = new int* [row];
	for (int i = 0; i < row; i++)
		matrix[i] = new int[col];
	for (int i = 0; i < row; i++) {
		for (int j = 0; j < col; j++) {
			matrix[i][j] = oth.matrix[i][j];
		}
	}
	cout << "Array copied to target." << endl;
}
int Matrix::getColumnNumber() {
	return col;
}
int Matrix::getRowNumber() {
	return row;
}
void Matrix::setValue(int r, int c, int value) {
	matrix[r][c] = value;
}
void Matrix::randomSet() {
	srand(time(NULL));	
	for (int i = 0; i < row; i++) {
		for (int j = 0; j < col; j++) {
			matrix[i][j] = rand() % 10;
		}
	}
}
void Matrix::identityMatrixSet() {
	for (int i = 0; i < row; i++) {
		for (int j = 0; j < col; j++) {
			if (i == j) {
				matrix[i][j] = 1;
			}
			else {
				matrix[i][j] = 0;
			}
		}
	}
}
void Matrix::display() {
	cout << "Matrix:" << endl;
	for (int i = 0; i < row; i++) {
		for (int j = 0; j < col; j++) {
			cout << matrix[i][j] << " ";
		}
		cout << "\n";
	}
	cout << "\n\n";
}

void Matrix::addMatrix(Matrix &othMatrix) {
	Matrix result(row,col);
	for (int i = 0; i < result.row; i++) {
		for (int j = 0; j < result.col; j++) {
			result.matrix[i][j] = matrix[i][j] + othMatrix.matrix[i][j];
		}
	}
	result.display();
}