#pragma once
#include "B_node.h"
#include "HumanParameters.h"
#include "Sequence_tree.h"
#include <ctime>
template<typename TYPE, class TElement = HumanParameters>
class B_tree
{
public:
	TElement *result;
	double search_time;

	B_tree<TYPE, TElement>(Sequence_tree<TElement> *seq, TYPE key, int sorting_parameter) {
		double start = clock();
		this->root = nullptr;
		this->sorting_parameter = sorting_parameter;
		this->result = nullptr;
		for (int i = 0; i < seq->GetLength(); i++) {		
			this->Insert(seq->Get(i));
		}
		
		this->Search(key, this->root);
		double end = clock();
		search_time = end - start;
	}

	void Delete_tree() {
		this->Delete(this->root);
	}
	
private:
	B_node<TElement> *root;
	int sorting_parameter;

	void Delete(B_node<TElement> *node) {
		if (node != nullptr) {
			for (int i = 0; i <= (2 * t - 1); i++) {
				if (node->children[i] != nullptr) this->Delete(node->children[i]);
				else {
					delete(node);
					break;
				}
			}
		}
	}

	void Insert_to_node(TElement *value, B_node<TElement> *node) {
		node->value[node->count] = value;
		node->count = node->count + 1;
		this->Sort(node);
	}

	void Sort(B_node<TElement> *node) {
		TElement *m;
		TYPE value_i, value_j;
		for (int i = 0; i < (2 * t - 1); i++) {
			for (int j = i + 1; j <= (2 * t - 1); j++) {
				if ((node->value[i] != nullptr) && (node->value[j] != nullptr)) {

					switch (sorting_parameter) {
					case 1: {
						value_i = node->value[i]->GetAge();
						value_j = node->value[j]->GetAge();
						break;
					}
					case 2: {
						value_i = node->value[i]->GetWeight();
						value_j = node->value[j]->GetWeight();
						break;
					}
					case 3: {
						value_i = node->value[i]->GetHeight();
						value_j = node->value[j]->GetHeight();
						break;
					}
					}

					if (value_i > value_j) {
						m = node->value[i];
						node->value[i] = node->value[j];
						node->value[j] = m;
					}
				}
				else break;
			}
		}
	}

	void Insert(TElement *value) {
		if (this->root == nullptr) {
			B_node<TElement> *new_root = new B_node<TElement>(value);
			this->root = new_root;
		}
		else {
			B_node<TElement> *ptr = this->root;
			TYPE value_new, value_i;
			while (ptr->leaf == false) { 
				for (int i = 0; i <= (2 * t - 1); i++) { 
					switch (sorting_parameter) {
					case 1: {
						value_new = value->GetAge();
						value_i = ptr->value[i]->GetAge();
						break;
					}
					case 2: {
						value_new = value->GetWeight();
						value_i = ptr->value[i]->GetWeight();
						break;
					}
					case 3: {
						value_new = value->GetHeight();
						value_i = ptr->value[i]->GetHeight();
						break;
					}
					}

					if ((ptr->value[i] != nullptr)) {
						if (value_new < value_i) {
							ptr = ptr->children[i];
							break;
						}
						if ((ptr->value[i + 1] == nullptr) && (value_new >= value_i)) {
							ptr = ptr->children[i + 1];
							break;
						}
					}
					else break;
				}
			}
			this->Insert_to_node(value, ptr);

			while (ptr->count == 2 * t) {
				if (ptr == root) {
					ptr = this->Restruct(ptr);
					break;
				}
				else {
					ptr = this->Restruct(ptr);
				}
			}
		}
	}

	B_node<TElement> *Restruct(B_node<TElement> *node) {
		B_node<TElement> *child_1 = new B_node<TElement>();
		for (int j = 0; j <= t - 2; j++) child_1->value[j] = node->value[j];
		for (int j = t - 1; j <= (2 * t - 1); j++) child_1->value[j] = nullptr;
		child_1->count = t - 1; 
		if (node->children_count != 0) {
			for (int i = 0; i <= (t - 1); i++) {
				child_1->children[i] = node->children[i];
				child_1->children[i]->parent = child_1;
			}
			for (int i = t; i <= (2 * t); i++) child_1->children[i] = nullptr;
			child_1->leaf = false;
			child_1->children_count = t; 
		}
		else {
			child_1->leaf = true;
			child_1->children_count = 0;
			for (int i = 0; i <= (2 * t); i++) child_1->children[i] = nullptr;
		}

	
		B_node<TElement> *child_2 = new B_node<TElement>();
		for (int j = 0; j <= (t - 1); j++) child_2->value[j] = node->value[j + t];
		for (int j = t; j <= (2 * t - 1); j++) child_2->value[j] = nullptr;
		child_2->count = t; 
		if (node->children_count != 0) {
			for (int i = 0; i <= t; i++) {
				child_2->children[i] = node->children[i + t];
				child_2->children[i]->parent = child_2;
			}
			for (int i = t + 1; i <= (2 * t); i++) child_2->children[i] = nullptr;
			child_2->leaf = false;
			child_2->children_count = t;
		}
		else {
			child_2->leaf = true;
			child_2->children_count = 0;
			for (int i = 0; i <= (2 * t); i++) child_2->children[i] = nullptr;
		}

		if (node->parent == nullptr) { 
			node->value[0] = node->value[t - 1];
			for (int j = 1; j <= (2 * t - 1); j++) node->value[j] = nullptr;
			node->children[0] = child_1;
			node->children[1] = child_2;
			for (int i = 2; i <= (2 * t); i++) node->children[i] = nullptr;
			node->parent = nullptr;
			node->leaf = false;
			node->count = 1;
			node->children_count = 2;
			child_1->parent = node;
			child_2->parent = node;
			return node;
		}
		else {
			this->Insert_to_node(node->value[t - 1], node->parent);
			for (int i = 0; i <= (2 * t); i++) {
				if (node->parent->children[i] == node) node->parent->children[i] = nullptr;
			}
			for (int i = 0; i <= (2 * t); i++) {
				if (node->parent->children[i] == nullptr) {
					for (int j = (2 * t); j > (i + 1); j--) node->parent->children[j] = node->parent->children[j - 1];
					node->parent->children[i + 1] = child_2;
					node->parent->children[i] = child_1;
					break;
				}
				
			}
			child_1->parent = node->parent;
			child_2->parent = node->parent;
			node->parent->leaf = false;
			B_node<TElement> *parent = new B_node<TElement>();
			parent = child_1->parent;
			delete(node);
			return parent;
		}
	}

	void Search(TYPE key, B_node<TElement> *node) {
		if ((node != nullptr)&&(this->result == nullptr)) {
			if (node->leaf == false) {
				int i;
				TYPE value;
				for (i = 0; i <= (2 * t - 1); i++) {
					if (node->value[i] != nullptr) {
						switch (sorting_parameter) {
						case 1: {
							value = node->value[i]->GetAge();
							break;
						}
						case 2: {
							value = node->value[i]->GetWeight();
							break;
						}
						case 3: {
							value = node->value[i]->GetHeight();
							break;
						}
						}
						
						if (key == value) 
						{
							this->result = node->value[i]; 
							break;
						}
						else if (key < value) {
							this->Search(key, node->children[i]);
							break;
						}
						else { this->Search(key, node->children[i + 1]); }
					}
					else { break; }
				}
				
			}
			else {
				for (int j = 0; j <= (2 * t - 1); j++) {
					if ((this->result == nullptr)&& (node->value[j] != nullptr)) {
						TYPE value;
						switch (sorting_parameter) {
						case 1: {
							value = node->value[j]->GetAge();
							break;
						}
						case 2: {
							value = node->value[j]->GetWeight();
							break;
						}
						case 3: {
							value = node->value[j]->GetHeight();
							break;
						}
						}
						if (key == value) this->result = node->value[j];
					}
				}
			}
		}
	}
};

