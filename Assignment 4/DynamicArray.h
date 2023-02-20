#pragma once
//Programmer: Anna Felipe
//Programmer ID: 1506055

#include <string>
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
