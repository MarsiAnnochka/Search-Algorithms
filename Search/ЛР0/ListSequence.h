#include "Node.h"
#include "Sequence.h"
#pragma once
#include <stdexcept>
#include <iostream>
using namespace std;

template<typename TElement>
class ListSequence : public Sequence<TElement>
{
public:
	Node<TElement> *head;

	ListSequence<TElement>() : Sequence<TElement>() {
		this->head = nullptr;
	}
	void Filling_from_array(TElement arr[], int size)  {
		for (int i = 0; i < this->GetLength(); i++) {
			free(this->Get_element(i));
		}
		this->head = nullptr;
		Sequence<TElement>::Filling_from_array(arr,size);
	}
	
	Node<TElement> *Get_element(int index) {

		Sequence<TElement>::Index_check(index);

			Node<TElement> *found_element = this->head;
			int counter = this->GetLength()-1;
			
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

	TElement Get(int index) {
		
		return this->Get_element(index)->value;
	}
	void Write() {
		
		for (int i = 0; i < this->GetLength(); i++) {
			std::cout << this->Get(i) << "  ";
		}
		std::cout << std::endl;
	}

	
	Sequence<TElement> *GetSubsequence(int startIndex, int endIndex) {
		
			Sequence<TElement>::Index_check(startIndex);
			Sequence<TElement>::Index_check(endIndex);
			if (startIndex <= endIndex) {
				Sequence<TElement> *Subsequence = new ListSequence<TElement>();
				for (int i = startIndex; i < endIndex + 1; i++) {
					Subsequence->Append(this->Get(i));
				}
				return Subsequence;
			}
			else { 
				throw std::exception(" ");
			}
	}
	void InsertAt(int index, TElement item) {
		Sequence<TElement>::InsertAt(index, item);
		(this->Length)--;
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
	void Remove(TElement item) {
		
		int place = -1;
		for (int i = 0; i < this->GetLength(); i++) {
			if (this->Get(i) == item) {
				place = i;
				break;
			}
		}
		if (place == -1) {
			throw std::exception(" ");
		}
		else {
			if (place == this->GetLength()-1) {
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
	
};

