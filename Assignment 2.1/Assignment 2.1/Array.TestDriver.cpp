//Programmer: Anna Felipe
//Programmer ID: 1506055

/* Test Driver for main application.
Program test all functions are working
correctly with expected and actual outputs
before being implemented in main */

#include <iostream>
#include <cassert>

using namespace std;

class Array
{

private:

	int values[100];
	int dummy;

public:

	Array();
	int capacity() const;
	int operator[ ](int) const;
	int& operator[ ](int);
};

int main()
{
	
	cout << "Programmer: Anna Felipe" << endl;
	cout << "Programmer's ID: 1506055" << endl;
	cout << "File: " << __FILE__ << endl;
	cout << endl;

	Array a;

	cout << "*******Testing Array::capacity*******" << endl;
	cout << "EXPECTED: 100" << endl;
	cout << "ACTUAL: " << a.capacity() << endl;
	cout << endl;
	assert(100 == a.capacity());

	cout << "*******Testing Array::operator[ ] setter*******" << endl;
	cout << endl;

	a[25] = 12345;
	a[50] = 54321;

	cout << "EXPECTED: 12345 for a[25]" << endl;
	cout << "RESULT: " << a[25] << endl;
	cout << endl;
	assert(12345 == a[25]);

	cout << "EXPECTED: 54321 for a[50]" << endl;
	cout << "RESULT: " << a[50] << endl;
	cout << endl;
	assert(54321 == a[50]);

	a[-1] = 999;

	cout << "EXPECTED: 999 for a[-1]" << endl;
	cout << "RESULT: " << a[-1] << endl;
	cout << endl;
	assert(999 == a[-1]);

	assert(999 == a[-25]);
	assert(999 == a[100]); 
	assert(999 != a[9]); 
	assert(999 != a[0]); 

	cout << "*******Testing the Array::operator[ ] getter*******" << endl;
	cout << endl;
		const Array b = a;
		for (int i = 0; i < 100; i++) {

			assert(a[i] == b[i]);
		}

	cout << "*******CONST OBJECT TEST*******" << endl;
		const Array c;
		assert(c.capacity() == 100);
		assert(c[0] == c[0]);
		assert(c[-1] == c[-1]);
}

Array::Array()
{
	dummy = 0;

	for (int i = 0; i < 100; i++) {

		values[i] = 0;
	}
}

int Array::capacity() const
{
	return 100;
}

int Array::operator[](int indexrange) const
{
	if (indexrange < 0 || indexrange >= capacity()) {

		return dummy;
	}
	else {

		return values[indexrange];
	}
}

int& Array::operator[](int indexrange)
{
	if (indexrange < 0 || indexrange >= capacity()) {

		return dummy;
	}
	else {

		return values[indexrange];
	}
}