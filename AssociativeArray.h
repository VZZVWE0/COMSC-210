//Programmer: Anna Felipe
//Programmer ID: 1506055

#ifndef ASSOCIATIVEARRAY_H
#define ASSOCIATIVEARRAY_H

using namespace std;

template <typename K, typename V>

class AssociativeArray {

	struct Node {

		K key;
		V value;
		bool inUse;

	};

	Node* values;
	int siz;
	int cap;
	void capacity(int);

public:

	AssociativeArray(int = 2); 
	AssociativeArray(const AssociativeArray<K, V>&);
	AssociativeArray<K, V>& operator=(const AssociativeArray<K, V>&); 
	~AssociativeArray() { 
		delete[] values; 
	} 
	V operator[](const K&) const; 
	V& operator[](const K&); 
	bool containsKey(const K&) const; 
	void deleteKey(const K&); 
	queue<K> keys() const;
	int size() const { 
		return siz; 
	} 
	void clear(); 

};

template <typename K, typename V>
AssociativeArray<K, V>::AssociativeArray(int cap) {

	siz = 0;
	this->cap = cap;
	values = new Node[cap];
}

template<typename K, typename V>
AssociativeArray<K, V>::AssociativeArray(const AssociativeArray<K, V>& original) {

	cap = original.cap;
	values = new Node[cap];
	for (int i = 0; i < cap; i++) {

		values[i].key = original.values[i].key;
		values[i].value = original.values[i].value;
		values[i].inUse = original.values[i].inUse;
	}

		siz = original.siz;
}

template<typename K, typename V>
AssociativeArray<K, V>& AssociativeArray<K, V>::operator=(const AssociativeArray& original) {

	if (this != &original) {

		delete[] values;
		cap = original.cap;
		values = new Node[cap];
		for (int i = 0; i < cap; i++) {

			values[i].key = original.values[i].key;
			values[i].value = original.values[i].value;
			values[i].inUse = original.values[i].inUse;
		}
		siz = original.siz;
	}
	return *this;
}

template <typename K, typename V>
V AssociativeArray<K, V>::operator[](const K& key) const{

	for (int i = 0; i < cap ; i++)
		if (values[i].key == key && values[i].inUse)
			return values[i].value;
	return V();
}

template <typename K, typename V>
V& AssociativeArray<K, V>::operator[](const K& key) {

	int unusedIndex = cap;

	for (int i = 0; i < cap; i++) {
		if (values[i].inUse == true) {
			if (values[i].key == key)
				return values[i].value;
		}
		else if (unusedIndex == cap)
			unusedIndex = i;
	}
	if (unusedIndex == cap)
		capacity(cap * 2);
	values[unusedIndex].key = key;
	values[unusedIndex].key = true;
	siz++;
	return values[unusedIndex].value;

}

template <typename K, typename V>
bool AssociativeArray<K, V>::containsKey(const K& key) const {

	for (int i = 0; i < cap; i++)
		if (values[i].key == key && values[i].inUse)
			return true;
	return false;
}

template <typename K, typename V>
void AssociativeArray<K, V>::deleteKey(const K& key) {

	for (int i = 0; i < cap; i++)
		if (values[i].key == key && values[i].inUse)
			values[i].inUse = false;
}

template <typename K, typename V>
queue<K> AssociativeArray<K, V>::keys() const {

	queue<K> keyQueue;

	for (int i = 0; i < cap; i++)
		if (values[i].inUse)
			keyQueue.push(values[i].key);
	return keyQueue;

}

template <typename K, typename V>
void AssociativeArray<K, V>::clear() {

	for (int index = 0; index < cap; index++) {
		values[index].inUse = false;
	}
	siz = 0;

}

template <typename K, typename V>
void AssociativeArray<K, V>::capacity(int newCap) {

	Node* temp = new Node[newCap];
	int limit = min(newCap, cap);
	for (int i = 0; i < limit; i++) {
		temp[i] = values[i];
	}
	for (int i = limit; i < cap; i++) {
		temp[i].value = V();
		temp[i].key = K();
	}

	delete[] values;
	values = temp;
	cap = newCap;
}

#endif