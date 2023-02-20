#pragma once
//Programmer: Anna Felipe
//Programmer ID: 1506055

#include <iostream>
#include <string>
#include <cassert>
using namespace std;

#pragma once
#ifndef DYANMIC_ARRAY_H
#define DYNAMIC_ARRAY_H

template<typename T>
class DynamicArray
{
private:

	T* value;
	int cap;
	T dummy = T();

public:

	DynamicArray(int = 2);
	DynamicArray(const DynamicArray<T>&);
	~DynamicArray() { delete[] value; }
	DynamicArray<T>& operator = (const DynamicArray<T>&);
	int capacity() const;
	void capacity(int);
	T operator[ ] (int) const;
	T& operator[ ] (int);
};

int main()
{
	cout << "Programmer: Anna Felipe" << endl;;
	cout << "Programmer's ID: 1506055" << endl;
	cout << "File:" <<__FILE__ << endl;
	cout << endl;

	DynamicArray<int> a;
	DynamicArray<double> b;
	DynamicArray<char> c;
	DynamicArray<string> d;

	a.capacity(100);
	cout << "------------Testing DynamicArray::capacity------------------------" << endl;
	cout << "EXPECTED: 100\n";
	cout << "ACTUAL: " << a.capacity() << endl;
	cout << endl;
	assert(100 == a.capacity());
	

	cout << "-----------Testing DynamicArray<T>::DynamicArray(int cap)------------" << endl;
	cout << endl;
	for (int i = 0; i < a.capacity(); i++)
		assert(a[i] == 0);

	cout << "------------Testing the Array::operator[ ]setter------------------" << endl;
	
	a[10] = 666;
	cout << "EXPECTED: 666" << endl;
	cout << "ACTUAL: " << a[10] << endl;
	cout << endl;
	assert(666 == a[10]);
	
	cout << "-------------Testing the Array::operator[ ]getter-----------------" << endl;
	cout << endl;
	const DynamicArray<int> za = a;
	for (int i = 0; i < a.capacity(); i++)
		assert(a[i] == za[i]);
	
	cout << "------------------------Testing double------------------------" << endl;
	b[-1000] = 666.6;

	cout << "EXPECTED: 666.6" << endl;
	cout << "ACTUAL: " << b[-1000] << endl;
	assert(666.6 == b[-1000]);
	cout << endl; 

	cout << "------------------------Testing char------------------------" << endl;
	c[-200] = 'A';

	cout << "EXPECTED: A" << endl;
	cout << "ACTUAL: " << c[-200] << endl;
	assert('A' == c[-200]);
	cout << endl;

	cout << "------------------------Testing string------------------------" << endl;
	d[-90] = "fifty";


	cout << "EXPECTED: fifty" << endl;
	cout << "ACTUAL: " << d[-90] << endl;
	assert("fifty" == d[-90]);
	cout << endl;

	system("PAUSE");

	return 0;
}

template<typename T>
DynamicArray<T>::DynamicArray(int cap)
{
	this->cap = cap;
	value = new T[cap];

	for (int i = 0; i < cap; i++) {

		value[i] = T();
	}
}

template<typename T>
DynamicArray<T>::DynamicArray(const DynamicArray<T>& original)
{
	cap = original.cap;
	value = new T[cap];

	for (int i = 0; i < cap; i++) {

		value[i] = original.value[i];
	}
	dummy = original.dummy;
}

template<typename T>
DynamicArray<T>& DynamicArray<T>::operator=(const DynamicArray<T>& original)
{
	if (this != &original)
	{
		delete[] value;

		cap = original.cap;
		value = new T[cap];
		for (int i = 0; i < cap; i++) {

			value[i] = original.value[i];
		}
		dummy = original.dummy;
	}
	return *this;
}

template<typename T>
int DynamicArray<T>::capacity() const
{
	return cap;
}

template<typename T>
void DynamicArray<T>::capacity(int cap)
{
	T* temp = new T[cap];

	int limit = (cap < this->cap ? cap : this->cap);

	for (int i = 0; i < limit; i++) {

		temp[i] = value[i];
	}
	for (int i = limit; i < cap; i++) {

		temp[i] = T();
	}
	delete[] value;

	value = temp;

	this->cap = cap;

}

template<typename T>
T DynamicArray<T>::operator[](int index) const
{
	if (index < 0) {

		return dummy;
	}
	if (index >= cap) {

		return dummy;
	}
	else {

		return value[index];
	}
}

template<typename T>
T& DynamicArray<T>:: operator[ ] (int index)
{
	if (index < 0) {

		return dummy;
	}
	if (index >= cap) {

		capacity(index * 2);
	}
	else {

		return value[index];
	}
}

#endif DYNAMIC_ARRAY_H
