#pragma once
#include <iostream>
#include "Node.h"


template <typename T>
class List {

	Node<T>* first;
	size_t size;

public:

	~List();

	List();

	List(const List<T>& other);

	List(List<T>&& other);

	void addFirst(T data);

	void pushBack(T data);

	Node<T> getFirst();

	Node<T> getLast();

	size_t length();

	bool isEmpty();

	List<T>& operator=(const List<T>& other);

	template<class H> friend std::ostream& operator<<(std::ostream& out, const List<H>& list);

};

#include "List.tpp"

