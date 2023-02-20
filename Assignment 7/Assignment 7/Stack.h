#pragma once
//Programmer: Anna Felipe
//Programmer ID: 1506055

#ifndef STACK_H
#define STACK_H

template <typename V>
class Stack
{
	struct Node
	{
		V value;
		Node* next;
	};

	Node* firstNode;
	int siz;
	V dummy;

public:

	Stack(); 
	~Stack();
	Stack(Stack& original);
	const Stack& operator= (Stack& right);
	void push(const V& v);
	const V& peek() const;
	void pop();
	void top();
	void clear();
	int size()const;
	bool empty() const;
};


template<typename V>
Stack<V>::Stack()
{
	this->firstNode = nullptr;
	siz = 0;
	dummy = V();
}

template<typename V>
Stack<V>::~Stack()
{
	while (firstNode)
	{
		Node* p = firstNode;
		firstNode = firstNode->next;
		delete p;
	}
}
template<typename V>
Stack<V>::Stack(Stack<V>& original)
{
	firstNode = 0;
	Node* lastNode = 0;
	siz = original.siz;
	for (Node* p = original.firstNode; p; p = p->next)
	{
		Node* temp = new Node{ p->value, 0 };
		if (lastNode)
			lastNode->next = temp;
		else 
			firstNode = temp;
		lastNode = temp;
	}
}
template<typename V>
const Stack<V>& Stack<V>::operator=(Stack<V>& original)
{
	if (this != &original)
	{
		this->clear();

		firstNode = 0;
		Node* lastNode = 0;
		siz = original.siz;

		for (Node* p = original.firstNode; p; p = p->next) {

			Node* temp = new Node{ p->value, p->next };
			if (lastNode)
				lastNode->next = temp;
			else
				firstNode = temp;
			lastNode = temp;
		}
	}
	return *this;
}
template<typename V>
void Stack<V>::push(const V& val)
{
	++siz;
	Node* temp = new Node{ val, nullptr };

	temp->next = firstNode;
	firstNode = temp;
}
template<typename V>
const V& Stack<V>::peek() const
{
	if (!firstNode)
	{
		return dummy;
	}
	return firstNode->value;

}
template<typename V>
void Stack<V>::pop()
{
		if (firstNode)
		{
			Node* temp = firstNode;
			firstNode = firstNode->next;
			delete temp;
			siz--;
		}
}
template<typename V>
void Stack<V>::top() {
	
	Node* temp = firstNode;
	return firstNode->value;
	
}
template<typename V>
void Stack<V>::clear()
{
	while (firstNode)
	{
		Node* temp = firstNode;
		firstNode = firstNode->next;
		delete temp;
	}
	siz = 0;
	firstNode = nullptr;
}
template<typename V>
int Stack<V>::size() const
{
	return this->siz;
}
template<typename V>
bool Stack<V>::empty() const
{
	return (siz == 0) ? true : false;
}
#endif