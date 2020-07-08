#pragma once
#include "Sequence.h"
#include "ArraySequence.h"
using namespace std;
template<typename TElement>
class ISorter
{
public:
	ArraySequence<TElement>* result;

	ISorter<TElement>(Sequence<TElement>* seq) {
		result = new ArraySequence<TElement>();
		result->Copy(seq);
	}
	virtual Sequence<TElement>* Sort() = 0;
};

