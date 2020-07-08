#pragma once
#include "ISorter.h"
#include "ArraySequence.h"
using namespace std;
template<typename TElement>
class SelectionSort : public ISorter<TElement>
{
public:
	SelectionSort<TElement>(Sequence<TElement>* seq) : ISorter<TElement>(seq) {}

	Sequence<TElement>* Sort() {
		int saving;
		int lowindex;
		int lowkey;
		for (int i = 0; i < this->result->GetLength() - 1; i++) {
			lowindex = i;
			lowkey = this->result->ptr[i];
			for (int j = i + 1; j < this->result->GetLength(); j++) {
				if (this->result->ptr[j] < lowkey) {
					lowkey = this->result->ptr[j];
					lowindex = j;
				}

			}
			saving = this->result->ptr[i];
			this->result->ptr[i] = this->result->ptr[lowindex];
			this->result->ptr[lowindex] = saving;
		}
		return this->result;
	}
};

