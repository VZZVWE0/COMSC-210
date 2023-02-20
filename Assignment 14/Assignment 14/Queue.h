//Programmer: Anna Felipe
//Programmer ID: 1506055

#pragma once
#ifndef LAB_EXERCISE_8
#define LAB_EXERCISE_8

template<typename V>
class Queue {

	struct Node
	{
		V value;
		Node* next;
	};

	int siz;
	Node* firstNode;
	Node* lastnode;
	V dummy;

public:

	Queue();
	Queue(const Queue<V>&);
	Queue<V>& operator=(const Queue<V>&);
	~Queue();
	void push(const V&);
	const V& front() const;
	const V& back() const;
	void pop();
	int size() const {

		return siz;
	}
	bool empty() const {

		return siz == 0;
	}
	void clear();

};
template<typename V>
Queue<V>::Queue() {

	size = 0;
	firstNode = 0;
	lastnode = 0;
}
template<typename V>
Queue<V>::Queue(const Queue<V>& original) {

	firstNode = 0;
	Node* lastnode = 0;
	siz = original.size;
	for (Node* p = original.firstNode; p; p = p->next)
	{
		Node* temp = new Node;
		temp->value = p->value;
		temp->next = 0;
		if (lastnode) lastnode->next = temp;
		else firstNode = temp;
		lastnode = temp;
	}
}
template<typename V>
Queue<V>& Queue<V>::operator = (const Queue<V>& original) {

	if (this != &original)
	{
		while (firstNode)
		{
			Node* p = firstNode;
			firstNode = firstNode->next;
			delete p;
		}
		Node* lastNode = 0;
		for (Node* p = original.first; p; p = p->next)
		{
			Node* temp = new Node;
			temp->value = p->value;
			temp->next = 0;
			if (lastnode) lastnode->next = temp;
			else firstNode = temp;
			lastnode = temp;
		}
		siz = original.size;
	}
	return *this;

}
template<typename V>
Queue<V>::~Queue() {

	while (firstNode) {
		Node* p = firstNode;
		firstNode = firstNode->next;
		delete p;
		size--;
	}

}
template<typename V>
void Queue<V>::push(const V& value) {

	Node* temp = new Node;
	temp->value = value;
	temp->next = 0;
	if (lastnode) {

		lastnode->next = temp;
	}
	else
		firstNode = temp;
	lastnode = temp;
	++size;
}

template<typename V>
const V& Queue<V>::front() const {

	return firstNode->value;

}
template<typename V>
const V& Queue<V>::back() const {

	return lastnode->value;
}

template<typename V>
void Queue<V>::pop() {

	if (firstNode)
	{
		Node* p = firstNode;
		firstNode = firstNode->next;
		delete p;
		--size;
	}

}
template<typename V>
void Queue<V>::clear() {

	while (firstNode)
	{
		void pop();
	}
};

#endif