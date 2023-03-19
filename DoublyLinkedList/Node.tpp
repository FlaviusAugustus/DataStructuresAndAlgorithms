#pragma once
#include "Node.h"


template<typename T> Node<T>::Node() : data(), next(nullptr), prev(nullptr) {}

template<typename T> Node<T>::Node(T Tdata) : data(Tdata), next(nullptr), prev(nullptr) {}


