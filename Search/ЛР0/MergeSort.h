#pragma once
#include "ISorter.h"
#include "ArraySequence.h"
using namespace std;
template<typename TElement>
class MergeSort : public ISorter<TElement>
{
public:
	MergeSort<TElement>(Sequence<TElement>* seq) : ISorter<TElement>(seq) {
		
	}

	Sequence<TElement>* Sort() {
		this->Merge_1(0, this->result->GetLength() - 1);
		return this->result;
	}

private:
	void Merge_1(int first, int last)
	{
		{
			if (first < last)
			{
				this->Merge_1(first, (first + last) / 2);
				this->Merge_1((first + last) / 2 + 1, last);
				this->Merge_2(first, last);
			}
		}
	}

	void Merge_2(int first, int last)
	{
		int middle, start, final, j;
		int *mas = new int[last - first + 1];
		middle = (first + last) / 2;
		start = first;
		final = middle + 1;
		for (j = first; j <= last; j++)
			if ((start <= middle) && ((final > last) || (this->result->ptr[start] < this->result->ptr[final])))
			{
				mas[j-first] = this->result->ptr[start];
				start++;
			}
			else
			{
				mas[j-first] = this->result->ptr[final];
				final++;
			}

		for (j = first; j <= last; j++) { this->result->ptr[j] = mas[j-first]; }
		
	};
};

