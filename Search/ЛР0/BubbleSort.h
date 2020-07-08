#pragma once
#include "ISorter.h"
#include "ArraySequence.h"
using namespace std;
template<typename TElement>
class BubbleSort : public ISorter<TElement>
{
public:
	BubbleSort<TElement>(Sequence<TElement>* seq) : ISorter<TElement>(seq) {}
	
	Sequence<TElement>* Sort() {
		
		int pairs = this->result->GetLength();
		bool swappedElements = true;
		int saving;
		while (swappedElements) {
			pairs--;
			swappedElements = false;
			for (int i = 0; i < pairs; i++) {

				if (this->result->ptr[i] > this->result->Get(i+1)) {
					saving = this->result->Get(i);
					this->result->ptr[i] = this->result->ptr[i+1];
					this->result->ptr[i+1] = saving;

					swappedElements = true;
				}
			}
		}
		return this->result;
	}
};

