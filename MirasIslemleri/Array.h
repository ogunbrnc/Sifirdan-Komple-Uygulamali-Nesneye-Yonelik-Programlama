#include <iostream>
using namespace std;

class Array {
protected:
	int* data;
	int size = 0;
	int capacity;
public:
	Array(int user_capacity = 5) {
		capacity = user_capacity;
		data = new int[capacity];
		cout << "new int array is created with capacity " << capacity << endl;
	}
	~Array() {
		delete[] data;
		cout << "Array destroyed" << endl;
	}
	Array(const Array& copyArray) {
		size = copyArray.size;
		capacity = copyArray.capacity;
		data = new int[capacity];
		for (int i = 0; i < copyArray.size; i++) {
			data[i] = copyArray.data[i];
		}
		cout << "Array copied to target." << endl;
	}
	void printItems() {
		if (size != 0) {// if size=0 then we just write capacity and size
			for (int i = 0; i < size; i++) {
				cout << data[i] << "-";
			}
		}
		cout << "\n" << "capacity=" << capacity << " size=" << size << endl;
	}
	void removeIndexItem(int index) {
		if (index<0 || index>capacity) {
			cout << "ERROR No item at the index" << index << endl;
			return;
		}
		for (int i = index; i < size; i++) {
			data[i] = data[i + 1];// we remove the item with scrolling.
		}
		size -= 1;
		cout << "Item is succesfully deleted" << endl;
	}
	void removeItem(int number) {
		int counter = 0;// number of item that removing
		for (int i = 0; i <= size; i++) {
			if (data[i] == number) {
				for (int j = i; j < size; j++) {// we continue with the last index.
					data[j] = data[j + 1];
				}
				counter += 1;
			}
		}
		cout << counter << "items (" << number << ")" << "are deleted from the Array" << endl;
		size -= counter;
	}
	int findIndex(int a, int b = 0) {// if user will not send index then we use default b=0
		for (int i = b; i < size; i++) {// if user user will index we start that index.
			if (data[i] == a) {
				return i;
			}
		}
		return -1;
	}
};

class sortedArray :public Array {
public:
	sortedArray(int user_capacity = 5) : Array(user_capacity) {};
	sortedArray(const sortedArray& oth) :Array(oth) {};
	void addItem(int number) {
		if (capacity == size) {// if the capacity is not enough
			int* temp_data = new int[capacity * 2];//we create new temp array with double capacity and copy the items to temp.
			for (int i = 0; i < size; i++) {
				temp_data[i] = data[i];//copy 
			}
			delete[] data;
			data = temp_data;//copy operation completed.
			capacity *= 2;
		}
		if (size == 0) {
			data[size] = number;// we have enough capacity and add element
			size++;
		}
		else if (size == 1) {
			if (data[size-1] < number) {
				data[size] = number;
				size++;
			}
			else {
				data[size] = data[size-1];
				data[size - 1] = number;
				size++;
			}
		}
		else if (data[size - 1] < number) {
			data[size] = number;
			size++;
		}
		else {
			for (int i = 0; i < size; i++) {
				if (data[i]<number && data[i + 1]>number) {
					for (int j = size - 1; j > i; j--) {
						data[j + 1] = data[j];
					}
					data[i + 1] = number;// we have enough capacity and add element
					size++;
					break;
				}
			}
		}
	}
};

class unsortedArray :public Array {
public:
	unsortedArray(int user_capacity = 5) : Array(user_capacity) {};
	unsortedArray(const unsortedArray& oth) :Array(oth) {};
	void addItem(int number){
		if (capacity == size) {// if the capacity is not enough
			int* temp_data = new int[capacity * 2];//we create new temp array with double capacity and copy the items to temp.
			for (int i = 0; i < size; i++) {
				temp_data[i] = data[i];//copy 
			}
			delete[] data;
			data = temp_data;//copy operation completed.
			capacity *= 2;
		}
		data[size] = number;// we have enough capacity and add element
		size++;
	}
};