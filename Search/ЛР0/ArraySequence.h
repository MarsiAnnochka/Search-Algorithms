#pragma once
#include "Sequence.h"
#include <cstdlib>
template<typename TElement>
class ArraySequence : public Sequence<TElement>
{
public:
	TElement *ptr;

	ArraySequence<TElement>() : Sequence<TElement>() {}

	ArraySequence<TElement>(int size) : Sequence<TElement>(size) {

		srand(time(nullptr));
		for (int i = 0; i < size; i++) {
			this->Append(rand() % 10000);
		}
	}

	void Copy(Sequence<TElement> *original) {
		this->Length = original->GetLength();
		if (this->Length == 0) { this->IsEmpty = true; }
		else { this->IsEmpty = false; }
		ptr = new TElement[original->GetLength()];
		for (int i = 0; i < original->GetLength(); i++) {
			this->ptr[i] = original->Get(i);
		}
	}
	
	TElement Get(int index) {
	
		Sequence<TElement>::Index_check(index);
		return this->ptr[index];
	}

	ArraySequence<TElement> *GetSubsequence(int startIndex, int endIndex) {
		Sequence<TElement>::Index_check(startIndex);
		Sequence<TElement>::Index_check(endIndex);

		if (startIndex <= endIndex) {
			ArraySequence<TElement> *Subsequence = new ArraySequence<TElement>();
			for (int i = startIndex; i <= endIndex; i++) {
				Subsequence->Append(this->ptr[i]);
			}
			return Subsequence;
		}
		else {
			throw std::exception(" ");
		}
	}

	void InsertAt(int index, TElement item) {
		Sequence<TElement>::InsertAt(index, item);
		if (this->Length == 1) {
			ptr = new TElement[1];
			ptr[0] = item;
		}
		else {
			ArraySequence<TElement> *extra_array = new ArraySequence<TElement>();
			extra_array->Copy(this);
			delete[]ptr;
			ptr = new TElement[this->GetLength()];
			for (int i = 0; i < index; i++) {
				this->ptr[i] = extra_array->ptr[i];
			}
			this->ptr[index] = item;
			for (int i = index + 1; i < this->GetLength(); i++) {
				this->ptr[i] = extra_array->ptr[i - 1];
			}
			delete[]extra_array;
		}
	}

	void Remove(TElement item) {
		int index = -1;
		for (int i = 0; i < this->GetLength(); i++) {
			if (this->ptr[i] == item) {
				index = i;
				break;
			}
		}
		if (index == -1) {
			throw std::exception(" ");
		}
		else {
			ArraySequence<TElement> *extra_array = new ArraySequence<TElement>();
			extra_array->Copy(this);
			(this->Length)--;
			delete[]ptr;
			ptr = new TElement[this->GetLength()];
			for (int i = 0; i < index; i++) {
				this->ptr[i] = extra_array->ptr[i];
			}
			for (int i = index; i < this->GetLength(); i++) {
				this->ptr[i] = extra_array->ptr[i + 1];
			}
			delete[]extra_array;
			if (this->Length == 0)
				this->IsEmpty = true;
		}
	}

	void Write() {
		for (int i = 0; i < this->GetLength(); i++) {
			std::cout << this->ptr[i] << "  ";
		}
		std::cout << std::endl;
	}
	
};


