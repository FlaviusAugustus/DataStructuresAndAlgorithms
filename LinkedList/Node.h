#pragma once

template <typename T>
struct Node {

	T data;
	Node* next;

	Node();

	Node(T data);

	~Node();

};

#include "Node.tpp"