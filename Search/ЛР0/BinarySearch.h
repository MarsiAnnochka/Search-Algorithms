#pragma once
#include "HumanParameters.h"
#include "Sequence.h"
#include "Sequence_tree.h"
#include "SortedSequence.h"
#include <ctime>
template<typename TYPE, class TElement = HumanParameters>
class BinarySearch
{
public:
	TElement *result;
	int index;
	double search_time;

	BinarySearch<TYPE, TElement>(Sequence_tree<TElement> *seq_unsort, TYPE key, int option, int attribute) {
		search_time = 0;
		result = nullptr;

		switch (option) {
		case 1: this->InHalf(seq_unsort, key, attribute); break;
		case 2: this->GoldenRatio(seq_unsort, key, attribute); break;
		case 3: this->TwoNumbers(seq_unsort, key, attribute); break;
		case 4: this->Fibonacci(seq_unsort, key, attribute); break;
		}
	}
private:

	void InHalf(Sequence_tree<TElement> *seq_unsort, TYPE key, int attribute) {
		double start = clock();

		SortedSequence<HumanParameters> *seq = new SortedSequence<HumanParameters>();
		seq->Set_attribute(attribute);
		for (int i = 0; i < seq_unsort->GetLength(); i++) {
			seq->Add(seq_unsort->Get(i));
		}

		result = nullptr;
		int right = seq->GetLength() - 1;
		int left = 0;
		int mid;

		TYPE current_value;
		while ((left <= right)&&(result == nullptr)) {
			mid = (left + right) / 2;
			switch (seq->GetAttribute()) {
			case 1: {
				current_value = seq->Get_element(mid)->value->GetAge();
				break;
			}
			case 2: {
				current_value = seq->Get_element(mid)->value->GetWeight();
				break;
			}
			case 3: {
				current_value = seq->Get_element(mid)->value->GetHeight();
				break;
			}
			}
			if (key == current_value) {
				result = seq->Get_element(mid)->value;
				index = mid;
				break;
			}
			else if (key < current_value) {
				right = mid - 1;
			}
			else {
				left = mid + 1;
			}
		}
		double end = clock();
		search_time = end - start;
	}

	void GoldenRatio(Sequence_tree<TElement> *seq_unsort, TYPE key, int attribute) {
		double start = clock();
		SortedSequence<HumanParameters> *seq = new SortedSequence<HumanParameters>();
		seq->Set_attribute(attribute);
		for (int i = 0; i < seq_unsort->GetLength(); i++) {
			seq->Add(seq_unsort->Get(i));
		}

		result = nullptr;
		const float golden_ratio = (1 + sqrt(5)) / 2;
		int right = seq->GetLength() - 1;
		int left = 0;
		int x1, x2;

		TYPE current_value_1, current_value_2;
		while ((left <= right) && (result == nullptr)) {
			x1 = right - (right - left) / golden_ratio;
			x2 = left + (right - left) / golden_ratio;
			if (x1 == x2) x2++;
			switch (seq->GetAttribute()) {
			case 1: {
				current_value_1 = seq->Get_element(x1)->value->GetAge();
				current_value_2 = seq->Get_element(x2)->value->GetAge();
				break;
			}
			case 2: {
				current_value_1 = seq->Get_element(x1)->value->GetWeight();
				current_value_2 = seq->Get_element(x2)->value->GetWeight();
				break;
			}
			case 3: {
				current_value_1 = seq->Get_element(x1)->value->GetHeight();
				current_value_2 = seq->Get_element(x2)->value->GetHeight();
				break;
			}
			}
			if (key == current_value_2)
			{
				result = seq->Get_element(x2)->value;
				index = x2;
				break;
			}
			else if (key == current_value_1)
			{
				result = seq->Get_element(x1)->value;
				index = x1;
				break;
			}
			else if (current_value_1 > key)
				right = x1;
			else if (current_value_2 < key)
				left = x2;
			else
			{
				right = x2;
				left = x1;
			}
		}
		double end = clock();
		search_time = end - start;
	}

	void TwoNumbers(Sequence_tree<TElement> *seq_unsort, TYPE key, int attribute) {
		double start = clock();
		SortedSequence<HumanParameters> *seq = new SortedSequence<HumanParameters>();
		seq->Set_attribute(attribute);
		for (int i = 0; i < seq_unsort->GetLength(); i++) {
			seq->Add(seq_unsort->Get(i));
		}
		result = nullptr;
		int right = seq->GetLength() - 1;
		int left = 0;
		int x1, x2;

		TYPE current_value_1, current_value_2;
		while ((left < right)&&(result == nullptr)) {
			if (right - left == 1) {
				x1 = left;
				x2 = right;
			}
			else {
				do {
					srand(clock());
					x1 = left + rand() % (right - left);
					x2 = left + rand() % (right - left);
				} while (x1 >= x2);
			}
			switch (seq->GetAttribute()) {
			case 1: {
				current_value_1 = seq->Get_element(x1)->value->GetAge();
				current_value_2 = seq->Get_element(x2)->value->GetAge();
				break;
			}
			case 2: {
				current_value_1 = seq->Get_element(x1)->value->GetWeight();
				current_value_2 = seq->Get_element(x2)->value->GetWeight();
				break;
			}
			case 3: {
				current_value_1 = seq->Get_element(x1)->value->GetHeight();
				current_value_2 = seq->Get_element(x2)->value->GetHeight();
				break;
			}
			}
			if (key == current_value_2)
			{
				result = seq->Get_element(x2)->value;
				index = x2;
				break;
			}
			else if (key == current_value_1)
			{
				result = seq->Get_element(x1)->value;
				index = x1;
				break;
			}
			else if (current_value_1 > key)
				right = x1;
			else if (current_value_2 < key)
				left = x2;
			else
			{
				right = x2;
				left = x1;
			}
		}
		double end = clock();
		search_time = end - start;

	}

	void Fibonacci(Sequence_tree<TElement> *seq_unsort, TYPE key, int attribute) {
		double start = clock();
		SortedSequence<HumanParameters> *seq = new SortedSequence<HumanParameters>();
		seq->Set_attribute(attribute);
		for (int i = 0; i < seq_unsort->GetLength(); i++) {
			seq->Add(seq_unsort->Get(i));
		}
		result = nullptr;
		int right = seq->GetLength() - 1;
		int left = 0;
		int point = 0;
		int x[3] = { 0,1,1 };

		TYPE current_value;
		switch (seq->GetAttribute()) {
		case 1: {
			if (key == seq->Get_element(0)->value->GetAge()) {
				result = seq->Get_element(0)->value;
				index = 0;
			}
			break;
		}
		case 2: {
			if (key == seq->Get_element(0)->value->GetWeight()) {
				result = seq->Get_element(0)->value;
				index = 0;
			}
			break;
		}
		case 3: {
			if (key == seq->Get_element(0)->value->GetHeight()) {
				result = seq->Get_element(0)->value;
				index = 0;
			}
			break;
		}
		}
		
		while ((left < right) && (result == nullptr)) {
			if (right - left == 2) {
			x[2] = 0;
			}
			if (x[2] > (right - left)) {
				x[0] = 0;
				x[1] = 1;
				x[2] = 1;
				point = left;
			}
			switch (seq->GetAttribute()) {
			case 1: {
				current_value = seq->Get_element(point + x[2])->value->GetAge();
				break;
			}
			case 2: {
				current_value = seq->Get_element(point + x[2])->value->GetWeight();
				break;
			}
			case 3: {
				current_value = seq->Get_element(point + x[2])->value->GetHeight();
				break;
			}
			}
			cout << point + x[2] << endl;
			if (key == current_value) {
				result = seq->Get_element(point + x[2])->value;
				index = point + x[2];
				break;
			}
			else if (key < current_value) {
				right = point + x[2];
				left = x[1];
				point = left;
				x[0] = 0;
				x[1] = 1;
				x[2] = 1;
			}
			
			else {
				int hold = x[1] + x[2];
				x[0] = x[1];
				x[1] = x[2];
				x[2] = hold;
				left = point + x[2];
			}
		}
		
		double end = clock();
		search_time = end - start;
	}

};

