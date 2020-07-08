#pragma once
#include "HumanParameters.h"
template<class TElement = HumanParameters>
class Node
{
public:
	Node<TElement> *next;
	TElement *value;

	Node<TElement>(TElement *item) {
		this->value = item;
	}
	void Set_next(Node<TElement> *next) {
		this->next = next;
	}
	
};

