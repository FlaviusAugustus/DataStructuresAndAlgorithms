#pragma once
#include <iostream>
#include "Node.h"

template<typename T> 
class DoublyLinkedList {

	Node<T>* head;
	Node<T>* tail;
	size_t size;

	public:

	DoublyLinkedList();

	DoublyLinkedList(size_t size);

	DoublyLinkedList(const DoublyLinkedList<T>& other);

	~DoublyLinkedList();

	DoublyLinkedList<T>& operator=(const DoublyLinkedList<T>& other);

	void pushBack(T data);

	void addFirst(T data);

	void clear();

	//both methods return a base value (T()) if the list is empty
	T removeLast();

	T removeFirst();

	bool isEmpty();

	size_t length();

	template<typename U> friend std::ostream& operator<<(std::ostream& out, const DoublyLinkedList<U>& list);

};

#include "DoublyLinkedList.tpp"
