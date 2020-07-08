#pragma once
#include "ArraySequence.h"
#include "BubbleSort.h"
#include "Sequence.h"
#include "MergeSort.h"
#include "SelectionSort.h"
#include <fstream>
#include <ctime>
using namespace std;
template<typename TElement>
class Dispatch
{
private:
	double time;
public:
	Dispatch<TElement>() {
		int operation = 0;
		do {
			cout << "SORTING ALGORITHMS" << endl << endl;
			cout << "1) Enter sequence by yourself and sort" << endl;
			cout << "2) Sort generated sequence" << endl;
			cout << "3) Analysis of algorithms" << endl;
			cout << "4) Exit" << endl << endl;
			do {
				cin >> operation;
			} while (!Check(operation, 4));

			switch (operation) {
			case 1: Operation_1(); break;
			case 2: Operation_2(); break;
			case 3: Operation_3(); break;
			case 4: break;
			}
		} while (operation != 4);
	}

	bool Check(int index, int max) {
		int flag = true;
		if ((index > max) || (index < 1)) {
			cout << "Incorrect input! Please, try again."<< endl;
			flag = false;
		}
		return flag;
	}

	bool Check_size(int size) {
		int flag = true;
		if (size <= 0) {
			cout << "Incorrect size! Please, try again.";
			flag = false;
		}
		return flag;
	}

	void Operation_1() {
		cout << "Enter the size of the sequence: ";
		int size;
		do {
			cin >> size;
		} while (!Check_size(size));

		cout << endl << "Enter the elements of the sequence:" << endl;
		ArraySequence<TElement> *seq = new ArraySequence<TElement>();
		for (int i = 0; i < size; i++) {
			TElement element;
			cin >> element;
			seq->Append(element);
		}

		Output(seq, Sort(seq));

	}

	Sequence<TElement>* Sort(Sequence<TElement>* seq) {
		Sequence<TElement> *res = new ArraySequence<TElement>();
		cout << "Choose the sorting:" << endl;
		cout << "1) Bubble sort" << endl;
		cout << "2) Selection sort" << endl;
		cout << "3) Merge sort" << endl << endl;
		int sort;
		do {
			cin >> sort;
		} while (!Check(sort, 3));
		cout << endl;
		double start_time, end_time;
		switch (sort) {
		case 1: {
			BubbleSort<TElement> *sorter = new BubbleSort<TElement>(seq);
			start_time = clock();
			res = sorter->Sort();
			end_time = clock();
			break;
		}
		case 3: {
			MergeSort<TElement> *sorter = new MergeSort<TElement>(seq);
			start_time = clock();
			res = sorter->Sort();
			end_time = clock();
			break;
		}
		case 2: {
			SelectionSort<TElement> *sorter = new SelectionSort<TElement>(seq);
			start_time = clock();
			res = sorter->Sort();
			end_time = clock();
			break;
		}
		}
		time = end_time - start_time;
		return res;
	}

	void Output(Sequence<TElement> *seq, Sequence<TElement> *res) {
		cout << "Choose the output:" << endl;
		cout << "1) On the screen" << endl;
		cout << "2) To the file" << endl;
		cout << "3) Only checking result and time" << endl<<endl;
		int output;
		do {
			cin >> output;
		} while (!Check(output, 3));
		cout << endl;
		switch (output) {
		case 1: {
			cout << "Unsorted array: " << endl;
			seq->Write();

			cout << "Sorted array: " << endl;
			res->Write();

			if (res->CorrectSort()) {
				cout << "The sorting was successful!" << endl;
				cout << endl << "Runtime: " << time << " msec" << endl;
			}
			else { cout << "Something went wrong, sorting in incorrect!" << endl; }
			
			break;
		}
		case 2: {
			string FILE = "result.txt";
			ofstream out(FILE, std::ios::out);
			out << "Unsorted array: " << endl;
			for (int i = 0; i < seq->GetLength(); i++) {
				out << seq->Get(i) << "  ";
			}

			out << "Sorted array: " << endl;
			for (int i = 0; i < res->GetLength(); i++) {
				out << res->Get(i) << "  ";
			}

			if (res->CorrectSort()) {
				out << "The sorting was successful!" << endl;
				out << endl << "Runtime: " << time << " msec" << endl;
			}
			else { out << "Something went wrong, sorting in incorrect!" << endl; }
			
			break;
		}
		case 3: {
			if (res->CorrectSort()) {
				cout << "The sorting was successful!" << endl;
				cout << endl << "Runtime: " << time << " msec" << endl;
			}
			else { cout << "Something went wrong, sorting in incorrect!" << endl; }
			break;
		}
		}
	}

	void Operation_2() {
		cout << "Enter the size of the sequence: ";
		int size;
		do {
			cin >> size;
		} while (!Check_size(size));

		Sequence<TElement> *seq = new ArraySequence<TElement>(size);
		
		Output(seq, Sort(seq));
	}
	
	void Operation_3() {
		
		cout << "Choose the output:" << endl;
		cout << "1) On the screen" << endl;
		cout << "2) To the file" << endl;
		int output;
		do {
			cin >> output;
		} while (!Check(output, 2));
		cout << endl;

		double start_time, end_time;
		double time[9];
		Sequence<TElement> *res = new ArraySequence<TElement>();

		Sequence<TElement> *seq_1 = new ArraySequence<TElement>();
		for (int i = 0; i < 10000; i++) {
			seq_1->Append(i);
		}

		BubbleSort<TElement> *sorter_0 = new BubbleSort<TElement>(seq_1);
		start_time = clock();
		res = sorter_0->Sort();
		end_time = clock();
		time[0] = end_time - start_time;
		free(sorter_0);

		MergeSort<TElement> *sorter_1 = new MergeSort<TElement>(seq_1);
		start_time = clock();
		res = sorter_1->Sort();
		end_time = clock();
		time[1] = end_time - start_time;
		free(sorter_1);

		SelectionSort<TElement> *sorter_2 = new SelectionSort<TElement>(seq_1);
		start_time = clock();
		res = sorter_2->Sort();
		end_time = clock();
		time[2] = end_time - start_time;
		free(sorter_2);
		
		free(seq_1);

		Sequence<TElement> *seq_2 = new ArraySequence<TElement>();
		for (int i = 10000; i > 0; i--) {
			seq_2->Append(i);
		}

		BubbleSort<TElement> *sorter_3 = new BubbleSort<TElement>(seq_2);
		start_time = clock();
		res = sorter_3->Sort();
		end_time = clock();
		time[3] = end_time - start_time;
		free(sorter_3);

		MergeSort<TElement> *sorter_4 = new MergeSort<TElement>(seq_2);
		start_time = clock();
		res = sorter_4->Sort();
		end_time = clock();
		time[4] = end_time - start_time;
		free(sorter_4);

		SelectionSort<TElement> *sorter_5 = new SelectionSort<TElement>(seq_2);
		start_time = clock();
		res = sorter_5->Sort();
		end_time = clock();
		time[5] = end_time - start_time;
		free(sorter_5);

		free(seq_2);

		Sequence<TElement> *seq_3 = new ArraySequence<TElement>(10000);
		BubbleSort<TElement> *sorter_6 = new BubbleSort<TElement>(seq_3);
		start_time = clock();
		res = sorter_6->Sort();
		end_time = clock();
		time[6] = end_time - start_time;
		free(sorter_6);

		MergeSort<TElement> *sorter_7 = new MergeSort<TElement>(seq_3);
		start_time = clock();
		res = sorter_7->Sort();
		end_time = clock();
		time[7] = end_time - start_time;
		free(sorter_7);

		SelectionSort<TElement> *sorter_8 = new SelectionSort<TElement>(seq_3);
		start_time = clock();
		res = sorter_8->Sort();
		end_time = clock();
		time[8] = end_time - start_time;
		free(sorter_8);

		free(seq_3);

		switch (output) {
		case 1: {
			cout << endl << "ANALYSIS (10000 elements, time in msec)" << endl << endl;
			cout << "1) Already sorted sequence:" << endl;
			cout << "	Bubble sort: " << time[0] << endl;
			cout << "	Merge sort: " << time[1] << endl;
			cout << "	Selection sort: " << time[2] << endl << endl;

			cout << "2) Sorted backwards sequence:" << endl;
			cout << "	Bubble sort: " << time[3] << endl;
			cout << "	Merge sort: " << time[4] << endl;
			cout << "	Selection sort: " << time[5] << endl << endl;

			cout << "3) Unsorted sequence:" << endl;
			cout << "	Bubble sort: " << time[6] << endl;
			cout << "	Merge sort: " << time[7] << endl;
			cout << "	Selection sort: " << time[8] << endl << endl;
			break;
		}
		case 2: {
			string FILE = "analysis.txt";
			ofstream cout(FILE, std::ios::out);
			cout << endl << "ANALYSIS (10000 elements, time in msec)" << endl << endl;
			cout << "1) Already sorted sequence:" << endl;
			cout << "	Bubble sort: " << time[0] << endl;
			cout << "	Merge sort: " << time[1] << endl;
			cout << "	Selection sort: " << time[2] << endl << endl;

			cout << "2) Sorted backwards sequence:" << endl;
			cout << "	Bubble sort: " << time[3] << endl;
			cout << "	Merge sort: " << time[4] << endl;
			cout << "	Selection sort: " << time[5] << endl << endl;

			cout << "3) Unsorted sequence:" << endl;
			cout << "	Bubble sort: " << time[6] << endl;
			cout << "	Merge sort: " << time[7] << endl;
			cout << "	Selection sort: " << time[8] << endl << endl;
			break;
		}
		}
	}
};

