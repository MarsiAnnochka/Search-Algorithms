#pragma once
#include "HumanParameters.h"
#include "Node.h"
#include <ctime>
template<class TElement = HumanParameters>
class Sequence_tree
{
protected:
	Node<TElement> *head;
	int Length;
	bool IsEmpty;

	void Index_check(int index) {
		if ((index < 0) || (index >= this->GetLength())) {
			throw std::out_of_range("");
		}
	}

public:
	Sequence_tree<TElement>() {
		Length = 0;
		IsEmpty = true;
		this->head = nullptr;
	}

	
	int GetLength() {
		return Length;
	}
	bool GetIsEmpty() {
		return IsEmpty;
	}


	void Append(TElement *item) {
		this->InsertAt(this->GetLength(), item);
	}
	
	void InsertAt(int index, TElement *item) {
		if (index == 0) {}
		else if (index == this->GetLength()) {
			Index_check(index - 1);
		}
		else { Index_check(index); }
		if (Length == 0)
			IsEmpty = false;
		Node<TElement> *new_node = new Node<TElement>(item);
		if (index == this->GetLength()) {
			new_node->Set_next(head);
			head = new_node;
		}
		else if (index == 0) {
			this->Get_element(0)->Set_next(new_node);
		}
		else {
			new_node->Set_next(this->Get_element(index - 1));
			this->Get_element(index)->Set_next(new_node);
		}
		(this->Length)++;
	}

	TElement *Get(int index) {
		return this->Get_element(index)->value;
	}

	Node<TElement> *Get_element(int index) {
		Node<TElement> *found_element = this->head;
		int counter = this->GetLength() - 1;

		do {
			if (counter == index) {
				break;
			}
			else {
				found_element = found_element->next;
				counter--;
			}
		} while (true);
		return found_element;
	}

	void Filling_from_array(TElement *arr[], int size) {
		for (int i = 0; i < this->GetLength(); i++) {
			free(this->Get_element(i));
		}
		this->head = nullptr;
		this->Length = 0;
		for (int i = 0; i < size; i++) {
			this->Append(arr[i]);
		}
	}

	void Generate(int N) {
		srand(time(0));
		for (int i = 0; i < N; i++) {
			HumanParameters *element = new HumanParameters(1 + rand() % 110, 1 + rand() % 200, 1 + rand() % 300);
			this->Append(element);
		}
	}

	void Write() {
		cout << "[AGE]	[WEIGHT]  [HEIGHT]" << endl;
		for (int i = 0; i < this->GetLength(); i++) {
			cout << this->Get_element(i)->value->GetAge() << "  ";
			cout << this->Get_element(i)->value->GetWeight() << "  ";
			cout << this->Get_element(i)->value->GetHeight() << endl << endl;
		}
	}
};

