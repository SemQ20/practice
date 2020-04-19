#include <iostream>

template<typename T>
class List {
public:
	List();
	~List();
	void push_front(T data);
	void removeAt(int index);
	void removeValue(int data);
	void insert(T data,int index);
	void pop_front();
	void pop_back();
	void push_back(T data);
	int size();
	void clear();
	T& operator[](const int index);
private:
	template<typename T>
	class Node{
	public:
		Node *next;
		T data;
		Node(T data = T(), Node *next = nullptr)
		{
			this->data = data;
			this->next = next;
		}
	};
	int getIndexForData(int startInd,T data);
	int Size;
	int index = 0;
	Node <T> *head;
};

template<typename T>
List<T>::List()
{
	Size = 0;
	head = nullptr;
}

template<typename T>
List<T>::~List()
{
	clear();
}

template<typename T>
void List<T>::push_front(T data)
{
	head = new Node<T>(data,head);
	Size++;
}

template<typename T>
void List<T>::removeAt(int index)
{
	Node<T> *point = this->head;
	if(index==0)
	{
		pop_front();
	}
	else {
		for (int i = 0; i < index-1; i++) {
			point = point->next;
		}
		Node<T> *toDelete = point->next;
		point->next = toDelete->next;
		delete toDelete;
		Size--;
	}
}

template<typename T>
void List<T>::removeValue(int data)
{

	index = getIndexForData(index,data);
	if (index >= Size) {}
	else {
		if (index == 0) {
			pop_front();
		}
		else {
			Node<T> *current = this->head;
			for (int i = 0; i < index - 1; i++) {
				current = current->next;
			}
			Node<T> *newNode = current->next;
			current->next = newNode->next;
			delete newNode;
			Size--;
		}
		index++;
		if (index <= Size) {
			removeValue(data);
		}
		else {
			index = 0;
		}
	}	
}

template<typename T>
void List<T>::insert(T data, int index)
{
	if (index == 0)
	{
		push_front(data);
	}
	else {
		Node<T> *current=this->head;
		for (int i = 0; i < index - 1; i++)
		{
			current = current->next;
		}
		Node<T> *newNode = new Node<T>(data, current->next);
		current->next = newNode;
		Size++;
	}
}

template<typename T>
void List<T>::pop_front()
{
	Node<T> *cur=head;
	head = head->next;
	delete cur;
	Size--;
}

template<typename T>
void List<T>::pop_back()
{
	removeAt(Size - 1);
}

template<typename T>
void List<T>::push_back(T data)
{
	if (head == nullptr)
	{
		head = new Node<T>(data);
	}
	else {
		Node<T> *current = this->head;
		while (current->next != nullptr)
		{
			current = current->next;
		}
		current->next = new Node<T>(data);
	}
	Size++;
}

template<typename T>
int List<T>::size()
{
	return Size;
}

template<typename T>
void List<T>::clear()
{
	while (Size) {
		pop_front();
	}
}

template<typename T>
T & List<T>::operator[](const int index)
{
	int count{ 0 };
	Node<T> *point = this->head;
	while (count != index)
	{
		point = point->next;
		count++;
		if (count == index)
			return point->data;
	}
	return point->data;
}

template<typename T>
int List<T>::getIndexForData(int startInd,T data)
{
	int count = startInd;
	Node<T> *point = this->head;
	if (count > 0) {
		for (int i = 0; i != count; i++) {
			point = point->next;
		}
		if (point == nullptr)
		{
			return count = Size;
		}
	}
	for (; count != Size;)
	{
		if (point->data != data)
		{
			point = point->next;
			count++;
		}
		else {
			return count;
		}
	}
}

int main()
{
	List<int> lst;
	lst.push_back(5);
	lst.push_back(3);
	lst.push_back(10);
	lst.push_back(20);
	lst.push_front(10);
	lst.push_back(3);
	lst.push_back(5);
	lst.push_back(8);
	lst.push_back(3);
	lst.insert(100, 1);
	lst.removeValue(3);
	for (int i = 0; i != lst.size(); ++i) {
		std::cout << lst[i]<<std::endl;
	}
	std::cout <<"list size:"<< lst.size()<<std::endl;
	lst.clear();
	std::cout << "list size:" <<lst.size();
	return 0;
}

