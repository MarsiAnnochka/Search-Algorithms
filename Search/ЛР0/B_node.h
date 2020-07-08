#pragma once
#include "HumanParameters.h"
const int t = 2;

template<class TElement = HumanParameters>
class B_node
{
public:
	TElement **value = new TElement*[2*t];
	B_node<TElement> **children = new B_node<TElement>*[2 * t + 1];
	B_node<TElement> *parent;
	int count;
	int children_count;
	bool leaf;


	B_node<TElement>() {
		
	}

	B_node<TElement>(TElement *value) {
		this->value[0] = value;
		for (int j = 1; j <= (2 * t - 1); j++) this->value[j] = 0;
		for (int i = 0; i <= (2 * t); i++) this->children[i] = nullptr;
		this->count = 1;
		this->children_count = 0;
		this->leaf = true;
		this->parent = nullptr;
	}

	void Set_value() {

	}
};

