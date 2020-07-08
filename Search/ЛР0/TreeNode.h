#pragma once
#include "HumanParameters.h"
template<class TElement = HumanParameters>
class TreeNode
{
public:
	TreeNode<TElement> *left;
	TreeNode<TElement> *right;
	HumanParameters *value;
	int height;

	TreeNode<TElement>(TElement *new_node) {
		this->value = new_node;
		this->left = nullptr;
		this->right = nullptr;
		height = 1;
	}

	int BC() {
		return this->right->Get_height() - this->left->Get_height();
	}

	void Hight_recount() {
		if (this->left->Get_height() > this->right->Get_height()) {
			this->height = this->left->Get_height() + 1;
		}
		else { this->height = this->right->Get_height() + 1; }
	}

	int Get_height() {
		if (this) return this->height;
		else return 0;
	}
};