//Programmer: Anna Felipe
//Programmer ID: 1506055

#include <iostream>
#include <cassert>
#include <string>
using namespace std;

//#include "StaticArray.h";
//#include "StaticArray.h"; //ifndef test


template <typename T, int CAP>
class StaticArray {

private:

	T value[CAP];
	T dummy;

public:

	StaticArray();
	int capacity() const;
	T operator[](int) const;
	T& operator[](int);

};


int main()
{

	cout << "Programmer: Anna Felipe" << endl;
	cout << "Programmer's ID: 1506055" << endl;
	cout << "File: StaticArray.TestDriver.cpp" << endl;
	cout << endl;

	StaticArray<string, 100> a;

	cout << "*******Testing StaticArray<T, CAP>::capacity()*******" << endl;
	cout << "EXPECTED: 100" << endl;
	cout << "ACTUAL: " << a.capacity() << endl;
	cout << endl;
	assert(100 == a.capacity());

	cout << "*******Testing StaticArray<T, CAP>::operator[] setter*******" << endl;
	cout << endl;

	a[25] = "12345";
	a[50] = "54321";

	cout << "EXPECTED: 12345 for a[25]" << endl;
	cout << "RESULT: " << a[25] << endl;
	cout << endl;
	assert("12345" == a[25]);

	cout << "EXPECTED: 54321 for a[50]" << endl;
	cout << "RESULT: " << a[50] << endl;
	cout << endl;
	assert("54321" == a[50]);

	a[-1] = "999";

	cout << "EXPECTED: 999 for a[-1]" << endl;
	cout << "RESULT: " << a[-1] << endl;
	cout << endl;
	assert("999" == a[-1]);

	assert("999" == a[-25]);
	assert("999" == a[100]);
	assert("999" != a[9]);
	assert("999" != a[0]);

	cout << "*******Testing the StaticArray<T, CAP>::operator[] getter*******" << endl;
	cout << endl;
	const StaticArray<string, 100> b = a;
	for (int i = 0; i < 100; i++) {

		assert(a[i] == b[i]);
	}
	cout << "Pass" << endl; 
	cout << endl;

	cout << "*******Testing the Const Object*******" << endl;
	const StaticArray<string, 100> sc;
	assert(sc.capacity());
	assert(sc[0] == sc[0]);
	assert(sc[-1] == sc[-1]);
	cout << "Pass" << endl;

	return 0;


}

template <typename T, int CAP>
StaticArray<T, CAP>::StaticArray() {

	for (int i = 0; i < CAP; i++) {

		value[i] = dummy;
	}
}


template <typename T, int CAP>
int StaticArray<T, CAP>::capacity() const {

	return CAP;
}


template <typename T, int CAP>
T StaticArray<T, CAP>::operator[](int indexrange) const {

	if (indexrange < 0 || indexrange > CAP) {

		cout << "Out of range." << endl;

		return dummy;
	}
	else {

		return value[indexrange];
	}
}


template <typename T, int CAP>
T& StaticArray<T, CAP>::operator[](int indexrange) {

	if (indexrange < 0 || indexrange > CAP) {

		return dummy;
	}
	else {

		return value[indexrange];
	}

}
