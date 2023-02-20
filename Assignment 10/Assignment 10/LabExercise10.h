//Programmer: Anna Felipe
//Programmer ID: 1506055

#pragma once

template <typename K, typename V>
class AssociativeArray
{
	struct Node
	{
		K key;
		V value;
		bool inUse;
	};

	Node* values; 
	int siz;
	int cap;
	void capacity(int);

public:
	AssociativeArray();
	AssociativeArray(const AssociativeArray&);
	AssociativeArray<K, V>& operator=(const AssociativeArray<K, V>&); //asignmemt operator
	~AssociativeArray(); //destructor prototype
	V operator[](const K&) const;
	V& operator[](const K&); //setter
	bool containsKey(const K&) const; //getter
	void deleteKey(const K&); //setter
	queue<K> keys() const;
	int size() { return siz; }
	void clear();

};

template <typename K, typename V>
AssociativeArray<K,V>::AssociativeArray(){ 

	firstNode = 0; 
	size = 0;
}

template <typename K, typename V>
AssociativeArray<K, V>::AssociativeArray(const AssociativeArray<K, V>&) {
	Node* lastNode = 0;
	firstNode = 0;
	siz = original.siz;
	for (Node* p = original.firstNode; p; p = p->next)
	{
		Node* temp = new Node;
		temp->value = p->value;
		temp->key = p->key;
		temp->next = 0;
		
		if (lastNode) {
			lastNode->next = temp;
		}
		else 
			firstNode = temp;
		lastNode = temp;
	}
}

template <typename K, typename V>
AssociativeArray<K, V>& AssociativeArray<K, V>::operator=(const AssociativeArray<K, V>& original) {
	if (this != &original)
	{
		while (firstNode)
		{
			Node* p = first;
			firstNode = first->next;
			delete p;
		}
		node* lastNode = 0;
		for (node* p = original.first; p; p = p->next)
		{
			node* temp = new node;
			temp->value = p->value;
			temp->next = 0;
			if (last) last->next = temp;
			else first = temp;
			last = temp;
		}
		siz = original.size;
	}
	return *this;
}

template <typename K, typename V>
AssociativeArray<K, V>::~AssociativeArray() {
	while (firstNode) {
		node* p = firstNode;
		firstNode = firstNode->next;
		delete p;
		size--;
	}

}

template <typename K, typename V>
V AssociativeArray<K, V>::operator[](const K&) const {
	for (int i = 0; i < capl i++) {
		if (values[i].inUse && values[i].key == index) {
			return values[i].value;
		}
	}
}

template <typename K, typename V>
V& AssociativeArray<K, V>::operator[](const K&) const {
	
	int indexOfFirstUnusedKey = cap; 
	for (int index = 0; index < cap; index++) 
	{
		if (data[index].inUse)
		{
			if (data[index].key == key) 
				return data[index].value;
		}
		else if (indexOfFirstUnusedKey == cap)
			indexOfFirstUnusedKey = index; 
	}
	if (indexOfFirstUnusedKey == cap) capacity(2 * cap); 
	data[indexOfFirstUnusedKey].key = key;
	data[indexOfFirstUnusedKey].inUse = true;
	++siz;
	return data[indexOfFirstUnusedKey].value; 
}

template <typename K, typename V>
bool AssociativeArray<K, V>::containsKey(const K&) const {
	Node* p, * prev; 
	for (p = firstNode, prev = 0; p; prev = p, p = p->next)
		if (p->key == key)
			break;
	if (p)
	{
		--siz;
		if (prev) prev->next = p->next; 
		else firstNode = p->next; 
		delete p; 
	}
}

template <typename K, typename V>
void AssociativeArray<K, V>::deleteKey(const K&) {
	Node* p, prev;
	for (p = firstnode, prev = 0; p; prev = p, p = p->next)
		if (p->key == key)
			break;
	if (p)
	{
		--siz;
		if (prev)prev->next = p->next;
		else firstnode = p->next;
		delete p;
	}
}

template <typename K, typename V>
queue<K> AssociativeArray<K, V>::keys() const {
	queue<K> k_queue;
	for (int i = 0; i < cap; ++i){
		if (values[i].inUse) 
			k_queue.push(values[i].key);
	}
	return k_queue;
}

template <typename K, typename V>
void AssociativeArray<K, V>::clear() {

}