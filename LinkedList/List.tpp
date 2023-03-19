#include <iostream>
#include "List.h"

template<typename T> List<T>::List() : size() , first() {}

template<typename T> List<T>::List(const List& other) {

	size = other.size;
	const Node<T>* tmpNode = other.first;

	first = new Node<T>;
	Node<T>* node = first;

	first->data = tmpNode->data;


	for(int i = 0; i < size -1; i++) {

		node->next = new Node<T>(tmpNode->next->data);
		node = node->next;
		tmpNode = tmpNode->next;
	
	}

}

template<typename T> List<T>::List(List&& other) {

	first = other.first;
	size = other.size;

	other.first = nullptr;
	other.size = 0;

}

template<typename T> List<T>::~List() {

	delete first;
	size = 0;
}

template<typename T> void List<T>::addFirst(T data) {

	size++;

	if (!first) { first = new Node<T>(data); return; }

	Node<T>* newNode = new Node<T>(data);
	newNode->next = first;
	first = newNode;

}

template<typename T> void List<T>::pushBack(T data) {

	size++;

	if (!first) { first = new Node<T>(data); return; }

	Node<T>* newNode = new Node<T>(data);
	Node<T>* tmp = first;
	while (tmp->next) {

		tmp = tmp->next;

	}

	tmp->next = newNode;

}

template<typename T> Node<T> List<T>::getLast() {

	Node<T>* tmp = first;
	while (tmp->next) {

		tmp = tmp->next;

	}

	return *tmp;

}

template<typename T> Node<T> List<T>::getFirst() {

	return *first;

}

template<typename T> size_t List<T>::length() {

	return size;

}

template<typename T> bool List<T>::isEmpty() {

	return size == 0;

}

template<typename T> std::ostream& operator<<(std::ostream& out, const List<T>& list) {

	Node<T>* tmp = list.first;

	while (tmp) {

		out << tmp->data << " ";
		tmp = tmp->next;

	}

	return out;

}

template<typename T> List<T>& List<T>::operator=(const List<T>& other) {

	if (this == &other) { return *this; }

	List<T> tmp(other);

	std::swap(tmp.first, first);
	std::swap(size, tmp.size);

	return *this;

} 

	
