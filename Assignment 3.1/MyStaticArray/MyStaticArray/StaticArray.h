//Programmer: Anna Felipe
//Programmer ID: 1506055

using namespace std;

#ifndef LAB_EXERCISE_3
#define LAB_EXERCISE_3

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


#endif LAB_EXERCISE_3

#pragma once
