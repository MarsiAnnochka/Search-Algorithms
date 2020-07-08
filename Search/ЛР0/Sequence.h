#pragma once

#include <stdexcept>
#include <iostream>
#include <time.h>
#include <cstdlib>
using namespace std;
template<class TElement>
class Sequence
{
protected:
	int Length;
	bool IsEmpty;

	void Index_check(int index) {
		if ((index < 0) || (index >= this->GetLength())) {
			throw std::out_of_range("");
		}
	}

public:
	Sequence<TElement>() {
		Length = 0;
		IsEmpty = true;
	}
	
	Sequence<TElement>(int size) {
		Length = 0;
		if (size < 0) {
			throw std::exception(" ");
		}
		
	}

	int GetLength() {
		return Length;
	}
	bool GetIsEmpty() {
		return IsEmpty;
	}
	
	
	void Append(TElement item) {
		this->InsertAt(this->GetLength(), item);
	}
	void Prepend(TElement item) {
		this->InsertAt(0, item);
	}
	
	virtual void InsertAt(int index, TElement item) {
			if (index == 0) {
				
			}
			else if (index == this->GetLength()){
				Index_check(index - 1);
			}
			else { Index_check(index); }
			if (Length == 0)
				IsEmpty = false;
			Length++;
	}

	virtual TElement Get(int index) = 0;

	virtual void Write() {};

	TElement GetFirst() {
		return this->Get(0);
	}
	TElement GetLast() {
		return this->Get(this->GetLength() - 1);
	}

	virtual Sequence<TElement> *GetSubsequence(int startIndex, int endIndex) = 0;

	virtual void Filling_from_array(TElement arr[], int size) {
		
		this->Length = 0;
		for (int i = 0; i < size; i++) {
			this->Append(arr[i]);
		}
	}

	virtual void Remove(TElement item) = 0;

	bool CorrectSort() {
		bool flag = 1;
		for (int i = 0; i < this->GetLength() - 1; i++) {
			if (this->Get(i) > this->Get(i + 1)) {
				flag = 0;
			}
		}
		return flag;
	}

	
};

