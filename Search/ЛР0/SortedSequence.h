#include "Node.h"
#include <ctime>
#pragma once
#include "HumanParameters.h"
#include <stdexcept>
#include <iostream>
using namespace std;
template<class TElement = HumanParameters>
class SortedSequence
{
private:
	int Length;
	bool IsEmpty;
	Node<TElement> *head;
	int attribute;

	void Index_check(int index) {
		if ((index < 0) || (index >= this->GetLength())) {
			throw std::out_of_range("");
		}
	}
public:
	int GetAttribute() {
		return this->attribute;
	}

	int GetLength() {
		return Length;
	}
	bool GetIsEmpty() {
		return IsEmpty;
	}

	SortedSequence<TElement>() {
		this->head = nullptr;
		this->Length = 0;
	}

	void Set_attribute(int new_attribute) {
		this->attribute = new_attribute;
	}

	Node<TElement> *Get_element(int index) {

		Index_check(index);

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

	TElement *Get(int index) {

		return this->Get_element(index)->value;
	}

	SortedSequence<TElement> *GetSubsequence(int startIndex, int endIndex) {

		this->Index_check(startIndex);
		this->Index_check(endIndex);
		if (startIndex <= endIndex) {
			SortedSequence<TElement> *Subsequence = new SortedSequence();
			for (int i = startIndex; i < endIndex + 1; i++) {
				Subsequence->Add(this->Get(i));
			}
			return Subsequence;
		}
		else {
			throw std::exception(" ");
		}
	}
	
	void Add(TElement *item) {
		Node<TElement> *new_node = new Node<TElement>(item);
		if (this->GetLength() == 0) {
			this->IsEmpty = false;
			(this->Length)++;
			new_node->Set_next(head);
			head = new_node;
		}
		else {
			switch (attribute) {
			case 1: {
				if (item->GetAge() >= this->Get(this->GetLength() - 1)->GetAge()) {
					new_node->Set_next(head);
					head = new_node;
				}
				else if (item->GetAge() <= this->Get(0)->GetAge()) {
					this->Get_element(0)->Set_next(new_node);
				}
				else {
					for (int i = 1; i < this->GetLength(); i++) {
						if (item->GetAge() < this->Get(i)->GetAge()) {
							new_node->Set_next(this->Get_element(i - 1));
							this->Get_element(i)->Set_next(new_node);
							break;
						}
					}
				}
				break;
			}
			case 2: {
				if (item->GetWeight() >= this->Get(this->GetLength() - 1)->GetWeight()) {
					new_node->Set_next(head);
					head = new_node;
				}
				else if (item->GetWeight() <= this->Get(0)->GetWeight()) {
					this->Get_element(0)->Set_next(new_node);
				}
				else {
					for (int i = 1; i < this->GetLength(); i++) {
						if (item->GetWeight() < this->Get(i)->GetWeight()) {
							new_node->Set_next(this->Get_element(i - 1));
							this->Get_element(i)->Set_next(new_node);
							break;
						}
					}
				}
				break;
			}
			case 3: {
				if (item->GetHeight() >= this->Get(this->GetLength() - 1)->GetHeight()) {
					new_node->Set_next(head);
					head = new_node;
				}
				else if (item->GetHeight() <= this->Get(0)->GetHeight()) {
					this->Get_element(0)->Set_next(new_node);
				}
				else {
					for (int i = 1; i < this->GetLength(); i++) {
						if (item->GetHeight() < this->Get(i)->GetHeight()) {
							new_node->Set_next(this->Get_element(i - 1));
							this->Get_element(i)->Set_next(new_node);
							break;
						}
					}
				}
				break;
			}
			}
			
			(this->Length)++;
		}
	}

	void Remove(TElement *item) {

		int place = -1;
		for (int i = 0; i < this->GetLength(); i++) {
			if (item->Equal(this->Get_element(i)->value)) {
				place = i;
				break;
			}
		}
		if (place == -1) {
			throw std::exception(" ");
		}
		else {
			if (place == this->GetLength() - 1) {
				Node<TElement> *new_head = new Node<TElement>(this->head->next->value);
				new_head = this->head->next;
				free(this->Get_element(place));
				this->head = new_head;
			}
			else if (place == 0) {
				free(this->Get_element(place));
			}
			else {
				this->Get_element(place + 1)->Set_next(this->Get_element(place - 1));
			}
			(this->Length)--;
			if (this->Length == 0)
				this->IsEmpty = true;
		}
	}

	void Generate(int N) {
		srand(time(0));
		for (int i = 0; i < N; i++) {
			std::cout << i << endl;
			HumanParameters *element = new HumanParameters(1 + rand() % 110, 1 + rand() % 200, 1 + rand() % 300);
			this->Add(element);
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

