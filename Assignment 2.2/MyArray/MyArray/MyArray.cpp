//Programmer Name: Anna Felipe
//Programmer ID: 1506055*

#include <iostream>
#include <cstdlib>
#include <iomanip>

using namespace std;

class Array
{
	private:

		int values[100];
		int dummy;

	public:

		Array();
		int capacity() const;
		int operator[](int) const;
		int& operator[](int);
};

int main()
{
	
	cout << "Programmer: Anna Felipe " << endl;
	cout << "Programmer's ID: 1506055" << endl;
	cout << "File: " << __FILE__ << endl;
	cout << endl;

	Array a;
	Array b;

	string input;

	while (true)
	{

		cout << "Input an index and a value [Q to quit]: ";
		cin >> input;
		if (input == "Q" || input == "q") {

			break;
		}
		int index = atoi(input.c_str());
		cin >> input;
		if (input == "Q" || input == "q") {

			break;
		}
		a[index] = atoi(input.c_str());
		b[index] = 9999;
	}

	int storedValues = 0;
	
	for (int index = 0; index < b.capacity(); index++)
	{
		if (b[index] == 9999) {

			storedValues++;
		}
	}

	cout << endl;
	cout << "You stored this many values : " << storedValues << endl;
	cout << "The index-value pairs are: " << endl;
	cout << endl;

	for (int index = 0; index < b.capacity(); index++)
	{
		if (b[index] == 9999) {

			cout << setw(5) << index << " => " << a[index] << endl;
		}
	}

	cout << endl;

	while (true)
	{
		cout << "Input an index for me to look up [Q to quit]: ";
		cin >> input;
		cin.ignore(1000, 10);

		if (input == "Q" || input == "q") {

			break;
		}
		int index = atoi(input.c_str());
		if (b[index] == 9999 && index > 0 && index <= 100) {

			cout << "Found it -- the value stored at " << index << " is " << a[index] << endl;
			cout << endl;
		}
		else {

			cout << "I didn't find it" << endl;
			cout << endl;
		}
	}

	system("PAUSE");

	return 0;
}
//********************************************************************************************


Array::Array() {
	
	dummy = 0;

	for (int i = 0; i < 100; i++) {

		values[i] = 0;
	}
}
int Array::capacity() const {

	return 100;
}
int Array::operator[](int index) const
{
	if (index < 0 || index >= capacity()) return dummy;
	return values[index];
}

int& Array::operator[](int index)
{
	if (index < 0 || index >= capacity()) return dummy;
	return values[index];
}