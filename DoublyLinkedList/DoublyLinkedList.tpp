#pragma once
#include <iostream>
#include "DoublyLinkedList.h"


template<typename T> 
DoublyLinkedList<T>::DoublyLinkedList() : 
	size(), head(), tail() {}

template<typename T>
DoublyLinkedList<T>::DoublyLinkedList(size_t Tsize) :
	size(Tsize), head(), tail() {

	head = new Node<T>;

	Node<T>* nodePtr = head;

	for(size_t i = 0; i < Tsize - 1; i++) {
	
		nodePtr->next = new Node<T>;
		nodePtr->next->prev = nodePtr;
		nodePtr = nodePtr->next;

	}

}

template<typename T>
DoublyLinkedList<T>::DoublyLinkedList(const DoublyLinkedList& other) : size(other.size) {

	head = new Node<T>(other.head->data);

	//iterators over both lists
	Node<T>* nodePtr = head;
	const Node<T>* nodePtrOther = other.head->next;

	while(nodePtrOther) {

		nodePtr->next = new Node<T>;
		nodePtr->next->data = nodePtrOther->data;
		nodePtr->next->prev = nodePtr;

		nodePtr = nodePtr->next;
		nodePtrOther = nodePtrOther->next;

	}

	tail = nodePtr;

}

template<typename T>
DoublyLinkedList<T>::~DoublyLinkedList() {

	Node<T>* node;

	while (head) {

		node = head;
		head = head->next;
		delete node;

	}

	size = 0;

}

template<typename T>
void DoublyLinkedList<T>::addFirst(T data) {

	Node<T>* newNode = new Node<T>(data); 
	size++;

	if (!head) { head = tail = newNode; return; }
	
	head->prev = newNode;
	newNode->next = head;

	head = newNode;

}

template<typename T>
void DoublyLinkedList<T>::pushBack(T data) {

	Node<T>* newNode = new Node<T>(data); 
	size++;

	if (!tail) { head = tail = newNode; return; }

	tail->next = newNode;
	newNode->prev = tail;

	tail = newNode;
	
}

//what if value returned by the default constructor is a valid value???
template<typename T>
T DoublyLinkedList<T>::removeLast() {

	if (!tail) { return T(); }

	Node<T>* nodeToDelete = tail;
	T returnData = nodeToDelete->data;
	tail = tail->prev;
	tail->next = nullptr; //prevent double deletion

	delete nodeToDelete;

	size--;

	return returnData;

}

template<typename T>
T DoublyLinkedList<T>::removeFirst() {

	if (!head) { return T(); }

	Node<T>* nodeToDelete = head;
	T returnData = head->data;
	head = head->next;

	nodeToDelete->next = nullptr;
	delete nodeToDelete;

	size--;

	return returnData;
}

template<typename T>
void DoublyLinkedList<T>::clear() {

	Node<T>* node;

	while(head) {
	
		node = head;
		head = head->next;
		delete node;
	
	}

	size = 0;

}


template<typename T>
size_t DoublyLinkedList<T>::length() {

	return size;

}

template<typename T>
bool DoublyLinkedList<T>::isEmpty() {

	return size == 0;

}

template<typename T>
DoublyLinkedList<T>& DoublyLinkedList<T>::operator=(const DoublyLinkedList<T>& other) {

	DoublyLinkedList tmp(other);

	clear();

	std::swap(this->head, tmp.head);
	std::swap(this->tail, tmp.tail);
	std::swap(this->size, tmp.size);

	return *this;

}

template<typename T>
std::ostream& operator<<(std::ostream& out, const DoublyLinkedList<T>& list) {

	const Node<T>* iterNode = list.head;

	while (iterNode) {

		out << iterNode->data << " ";
		iterNode = iterNode->next;

	}

	return out;

}



