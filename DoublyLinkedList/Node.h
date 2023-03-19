#pragma once

template<typename T> 
struct Node {

	T data;
	Node<T>* next;
	Node<T>* prev;

	Node();

	Node(T data);

};

#include "Node.tpp"
