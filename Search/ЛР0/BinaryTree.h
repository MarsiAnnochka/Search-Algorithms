#pragma once
#include "pch.h"
#include <iostream>
#include <string>
#include <sstream>
#include "TreeNode.h"
#include "Sequence_tree.h"
#include "HumanParameters.h"

#pragma once
template<typename TYPE, class TElement = HumanParameters>
class BinaryTree
{

public:
	HumanParameters *result;
	double search_time;

	BinaryTree<TYPE, TElement>(Sequence_tree<HumanParameters> *seq, TYPE key, int sorting_parameter) {
		double start = clock();
		this->root = nullptr;
		this->sorting_parameter = sorting_parameter;
		for (int i = 0; i < seq->GetLength(); i++) {
			this->root = this->Insert(this->root, seq->Get(i));
		}
		
		this->Search(key);
		double end = clock();
		search_time = end - start;
	}

	void Delete_tree() {
		if (this->current != nullptr) {
			if (this->current->left != nullptr) {
				this->current = this->current->left;
				this->Delete_tree();
			}
			else if (this->current->right != nullptr) {
				this->current = this->current->right;
				this->Delete_tree();
			}
			else { delete[] this->current; }
		}
	}

	
private:
	TreeNode<TElement> *current;
	TreeNode<TElement> *root;
	
	int sorting_parameter;

	void Add(HumanParameters *new_element) {
		if (this->root == nullptr) {
			this->root = new TreeNode<HumanParameters>(new_element);
		}
		else {
			this->current = this->root;
			TYPE new_element_value;
			TYPE current_value;
			while (true) {
				switch (sorting_parameter) {
				case 1: {
					new_element_value = new_element->GetAge();
					current_value = this->current->value->GetAge();
					break;
				}
				case 2: {
					new_element_value = new_element->GetWeight();
					current_value = this->current->value->GetWeight();
					break;
				}
				case 3: {
					new_element_value = new_element->GetHeight();
					current_value = this->current->value->GetHeight();
					break;
				}
				}
				if (new_element_value < current_value) {
					if (this->current->left != nullptr) {
						this->current = this->current->left;
					}
					else {
						this->current->left = new TreeNode<TElement>(new_element);
						break;
					}
				}
				else {
					if (this->current->right != nullptr) {
						this->current = this->current->right;
					}
					else {
						this->current->right = new TreeNode<TElement>(new_element);
						break;
					}
				}

			}
		}
	}

	
	void Search(TYPE key) {
		result = nullptr;
		TYPE current_value;
		this->current = this->root;
		while ((this->current != nullptr)&&(this->result == nullptr)) {
			switch (sorting_parameter) {
			case 1: {
				current_value = current->value->GetAge();
				break;
			}
			case 2: {
				current_value = current->value->GetWeight();
				break;
			}
			case 3: {
				current_value = current->value->GetHeight();
				break;
			}
			}
			if (current_value == key) {
				this->result = this->current->value;
				break;
			}
			else if (key < current_value) {
				this->current = this->current->left;
			}
			else { this->current = this->current->right; }
		}
	}
	

	TreeNode<TElement> *RightRotation(TreeNode<TElement> *node)
	{
		TreeNode<TElement> *extra_node = node->left;
		node->left = extra_node->right;
		extra_node->right = node;
		node->Hight_recount();
		extra_node->Hight_recount();
		return extra_node;
	}

	TreeNode<TElement> *LeftRotation(TreeNode<TElement> *node)
	{
		TreeNode<TElement> *extra_node = node->right;
		node->right = extra_node->left;
		extra_node->left = node;
		node->Hight_recount();
		extra_node->Hight_recount();
		return extra_node;
	}

	TreeNode<TElement> *Balance(TreeNode<TElement> *node)
	{
		node->Hight_recount();
		if (node->BC() == 2)
		{
			if (node->right->BC() < 0) node->right = RightRotation(node->right);
			return LeftRotation(node);
		}
		if (node->BC() == -2)
		{
			if (node->left->BC() > 0) node->left = LeftRotation(node->left);
			return RightRotation(node);
		}
		return node;
	}

	TreeNode<TElement> *Insert(TreeNode<TElement> *node, HumanParameters *new_element)
	{
		if (!node) return new TreeNode<TElement>(new_element);

		TYPE new_element_value;
		TYPE current_value;

		switch (sorting_parameter) {
		case 1: {
			new_element_value = new_element->GetAge();
			current_value = node->value->GetAge();
			break;
		}
		case 2: {
			new_element_value = new_element->GetWeight();
			current_value = node->value->GetWeight();
			break;
		}
		case 3: {
			new_element_value = new_element->GetHeight();
			current_value = node->value->GetHeight();
			break;
		}
		}
		if (new_element_value < current_value) node->left = Insert(node->left, new_element);
		else node->right = Insert(node->right, new_element);
		return Balance(node);
	}
};


