// stack.cpp : This file contains the 'main' function. Program execution begins and ends there
#include <iostream>
#include <ctime>

template<typename T>
class Stack {
public:
	Stack() : _top(NULL), _size(0){}
	~Stack();
	void push(T data);
	void pop();
	void clear();
	int size();
	bool empty();
	T& top();
private:
	template<typename T>
	class Node {
	public:
		T data;
		Node *next;
		Node(T data) : data(data){}
		Node(T data, Node *node) : data(data), next(node){}
	};
	Node<T> *_top;
	int _size;
};

template<typename T>
Stack<T>::~Stack()
{
	clear();
}

template<typename T>
void Stack<T>::push(T data)
{
	try {
		if (_top != NULL) {
			Node<T> *temp = new Node<T>(data, _top);
			_top = temp;
		}
		else {
			_top = new Node<T>(data);
		}
		_size++;
	}
	catch(std::bad_alloc){
		std::cout << "bad alloc" << std::endl;
	}
}

template<typename T>
void Stack<T>::pop()
{
	Node<T> *temp = _top;
	_top = _top->next;
	delete temp;
	_size--;
}

template<typename T>
void Stack<T>::clear()
{
	while (_size != 0)
	{
		pop();
	}
}

template<typename T>
int Stack<T>::size()
{
	return _size;
}

template<typename T>
bool Stack<T>::empty()
{
	bool stat = _size == 0 ? true : false;
	return stat;
}

template<typename T>
T & Stack<T>::top()
{
	return _top->data;
}


int main()
{
	Stack<int> stack;
	stack.push(10);
	std::cout << stack.size() << std::endl;
	std::cout << clock() / 1000.0 << "sec" << std::endl;
	return 0;
}


