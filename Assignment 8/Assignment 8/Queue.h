//Programmer: Anna Felipe
//Programmer ID: 1506055

#ifndef QUEUE_H 
#define QUEUE_H

template <typename V>
class Queue {

	struct Node	{

		V value;
		Node* next;
	};

	Node* firstNode;
	int siz;
	Node* lastNode;

	public:

		Queue();
		void push(const V&);
		V& front();
		V& back();
		void pop();
		int size() const { 
			return siz; 
		} 
		bool empty() const { 
			return siz == 0; 
		} 
		void clear();
		~Queue() { 

			clear(); 
		}
		Queue<V>& operator=(const Queue<V>&);
		Queue(const Queue<V>&);

};

template <typename V>
Queue<V>::Queue()	{

	lastNode = 0;
	siz = 0;

}

template <typename V>
void Queue<V>::push(const V& value)	{

	Node* temp = new Node;
	temp->value = value;
	if (lastNode) {

		lastNode->next = temp;
	}
	else {

		firstNode = temp;

		lastNode = temp;

		++siz;
	}
}

template <typename V>
V& Queue<V>::front()	{

	return firstNode->value;

}


template <typename V>
V& Queue<V>::back()	{

	return lastNode->value;

}

template <typename V>
void Queue<V>::pop()	{

	if (firstNode)	{

		Node* p = firstNode;
		firstNode = firstNode->next;
		delete p;
		--siz;
	}
	if (siz == 0)	{

		lastNode = 0;
	}

}

template <typename V>
void Queue<V>::clear()	 {

	while (firstNode)

	{

		Node* p = firstNode;

		firstNode = firstNode->next;

		delete p;

		--siz;

	}

	lastNode = 0;

}

template <typename V>
Queue<V>::Queue(const Queue& original)	{

	firstNode = 0;
	lastNode = 0; 
	siz = original.siz;

	for (Node* p = original.firstNode; p; p = p->next) {

		Node* temp = new Node;
		temp->value = p->value;
		temp->next = 0;

		if (lastNode)

			lastNode->next = temp;

		else

			firstNode = temp;
			lastNode = temp;
	}
}

template <typename V>
Queue<V>& Queue<V>::operator=(const Queue& original)	{

	if (this != &original)	{

		while (firstNode)	{

			Node* p = firstNode->next;

			delete firstNode;

			firstNode = p;

		}

		lastNode = 0;

		for (Node* p = original.firstNode; p; p = p->next)	{

			Node* temp = new Node;

			temp->value = p->value;

			temp->next = 0;

			if (lastNode)

				lastNode->next = temp;

			else

				firstNode = temp;

			lastNode = temp;
		}
		siz = original.siz;
	}
	return *this;

};

#endif