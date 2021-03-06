#pragma once
#include "pch.h"
#include <iostream>
#include "Sequence_tree.h"
#include "SortedSequence.h"
#include "HumanParameters.h"
#include "BinarySearch.h"
#include "BinaryTree.h"
#include "B_tree.h"

using namespace std;

void Operation_1(), Operation_2(), Operation_3(), Operation_4();
bool Check(int index, int max);
int Enter_attribute();
Sequence_tree<HumanParameters> *Enter_sequence();
HumanParameters *Enter_element();
int Output();
float Enter_key();

int main()
{
	Sequence_tree<HumanParameters> *seq = new Sequence_tree<HumanParameters>();
	seq->Generate(10000);
	HumanParameters *searching = new HumanParameters(1000, 1000, 1000);
	seq->Append(searching);
	B_tree<int, HumanParameters> *binary = new B_tree<int, HumanParameters>(seq, 1000, 1);
	binary->result->Write_result();
	int operation = 0;
	do {
		cout << "SEARCHING ALGORITHMS" << endl;
		cout << "Enter the number of operation:" << endl;
		cout << "1) Binary searching" << endl;
		cout << "2) Binary tree" << endl;
		cout << "3) B/B+ tree" << endl;
		cout << "4) Compare all algorithms" << endl;
		cout << "5) Exit" << endl << endl;
		do {
			cin >> operation;
		} while (!Check(operation, 5));
		switch (operation) {
		case 1: Operation_1(); break;
		case 2: Operation_2(); break;
		case 3: Operation_3(); break;
		case 4: Operation_4(); break;
		case 5: break;
		}
	} while (operation != 5);
}

bool Check(int index, int max) {
	int flag = true;
	if ((index > max) || (index < 1)) {
		cout << "Incorrect input! Please, try again." << endl << endl;
		flag = false;
	}
	return flag;
}

void Operation_1() {
	int attribute = Enter_attribute();
	Sequence_tree<HumanParameters> *seq = new Sequence_tree<HumanParameters>();
	seq = Enter_sequence();
	float key = Enter_key();
	int operation;
	
	cout << "Enter the way of searching:" << endl;
	cout << "1) In half" << endl;
	cout << "2) Golden ratio" << endl;
	cout << "3) Two numbers" << endl;
	cout << "4) Fibonacci" << endl << endl;
	do {
		cin >> operation;
	} while (!Check(operation, 4));
	
	BinarySearch<float, HumanParameters> *searching = new BinarySearch<float, HumanParameters>(seq, key, operation, attribute);
	if (Output() == 2) {
		seq->Write();
	}
	searching->result->Write_result();
	cout << searching->search_time << endl << endl;
}

void Operation_2() {
	int attribute = Enter_attribute();
	Sequence_tree<HumanParameters> *seq = new Sequence_tree<HumanParameters>();
	seq = Enter_sequence();
	float key = Enter_key();

	BinaryTree<float, HumanParameters> *searching = new BinaryTree<float, HumanParameters>(seq, key, attribute);
	if (Output() == 2) {
		seq->Write();
	}
	searching->result->Write_result();
	cout << searching->search_time << endl << endl;
}

void Operation_3() {
	int attribute = Enter_attribute();
	Sequence_tree<HumanParameters> *seq = new Sequence_tree<HumanParameters>();
	seq = Enter_sequence();
	float key = Enter_key();

	B_tree<float, HumanParameters> *searching = new B_tree<float, HumanParameters>(seq, key, attribute);
	if (Output() == 2) {
		seq->Write();
	}
	searching->result->Write_result();
	cout << searching->search_time << endl << endl;
}

void Operation_4() {
	double time[9];
	
	Sequence_tree<HumanParameters> *seq_tree_1 = new Sequence_tree<HumanParameters>();
	for (int i = 1; i <= 10000; i++) {
		seq_tree_1->Append(new HumanParameters(i, i, i));
	}
	BinarySearch<float, HumanParameters> *binary_1 = new BinarySearch<float, HumanParameters>(seq_tree_1, 10000, 1, 1);
	time[0] = binary_1->search_time;

	BinaryTree<float, HumanParameters> *binary_2 = new BinaryTree<float, HumanParameters>(seq_tree_1, 10000, 1);
	time[1] = binary_2->search_time;

	B_tree<float, HumanParameters> *binary_3 = new B_tree<float, HumanParameters>(seq_tree_1, 10000, 1);
	time[2] = binary_3->search_time;
	delete(seq_tree_1);

	Sequence_tree<HumanParameters> *seq_tree_2 = new Sequence_tree<HumanParameters>();
	for (int i = 10000; i >= 1; i--) {
		seq_tree_2->Append(new HumanParameters(i, i, i));
	}

	BinarySearch<float, HumanParameters> *binary_8 = new BinarySearch<float, HumanParameters>(seq_tree_2, 10000, 1, 1);
	time[7] = binary_8->search_time;
	
	BinaryTree<float, HumanParameters> *binary_4 = new BinaryTree<float, HumanParameters>(seq_tree_2, 10000, 1);
	time[3] = binary_4->search_time;

	B_tree<float, HumanParameters> *binary_5 = new B_tree<float, HumanParameters>(seq_tree_2, 10000, 1);
	time[4] = binary_5->search_time;
	delete(seq_tree_2);

	Sequence_tree<HumanParameters> *seq_tree_3 = new Sequence_tree<HumanParameters>();
	seq_tree_3->Generate(10000);

//	BinarySearch<float, HumanParameters> *binary_9 = new BinarySearch<float, HumanParameters>(seq_tree_3, 110, 1, 1);
//	time[8] = binary_9->search_time;

	BinaryTree<float, HumanParameters> *binary_6 = new BinaryTree<float, HumanParameters>(seq_tree_3, 110, 1);
	time[5] = binary_6->search_time;
	B_tree<float, HumanParameters> *binary_7 = new B_tree<float, HumanParameters>(seq_tree_3, 110, 1);
	time[6] = binary_7->search_time;
	
	cout << endl << "ANALYSIS (10000 elements, time in msec)" << endl << endl;
	cout << "1) Already sorted sequence:" << endl;
	cout << "	Binary search: " << time[0] << endl;
	cout << "	Binary tree: " << time[1] << endl;
	cout << "	B/B+ tree: " << time[2] << endl << endl;

	cout << "2) Sorted backwards sequence:" << endl;
	cout << "	Binary search: " << time[7] << endl;
	cout << "	Binary tree: " << time[3] << endl;
	cout << "	B/B+ tree: " << time[4] << endl << endl;

	cout << "2) Random sequence:" << endl;
	cout << "	Binary tree: " << time[5] << endl;
	cout << "	B/B+ tree: " << time[6] << endl << endl;
}

int Enter_attribute() {
	int attribute;
	cout << "Enter the number of searching attribute:" << endl;
	cout << "1) Age" << endl;
	cout << "2) Weight" << endl;
	cout << "3) Height" << endl << endl;
	do {
		cin >> attribute;
	} while (!Check(attribute, 3));
	return attribute;
}

Sequence_tree<HumanParameters> *Enter_sequence() {
	Sequence_tree<HumanParameters> *seq = new Sequence_tree<HumanParameters>();
	int operation;
	cout << "Sequence:" << endl;
	cout << "1) Enter by yourself" << endl;
	cout << "2) Generate" << endl << endl;
	do {
		cin >> operation;
	} while (!Check(operation, 2));
	int N;
	cout << "Enter the length of sequence: ";
	cin >> N;
	cout << endl << endl;

	switch (operation) {
	case 1: {
		for (int i = 0; i < N; i++) {
			cout << "Element " << i+1 << endl;
			seq->Append(Enter_element());
		}
		break;
	}
	case 2: {
		seq->Generate(N);
		break;
	}
	}
	return seq;
}

HumanParameters *Enter_element() {
	int age;
	float weight, height;
	cout << "Age: ";
	cin >> age;
	cout << "\nWeight: ";
	cin >> weight;
	cout << "\nHeight: ";
	cin >> height;
	cout << endl;
	HumanParameters *element = new HumanParameters(age, weight, height);
	return element;
}

float Enter_key() 
{
	float key;
	cout << "Enter searching key: ";
	cin >> key;
	cout << endl;
	return key;
}

int Output() {
	int output;
	cout << "Choose the output:" << endl;
	cout << "1) Only result" << endl;
	cout << "2) All sequence and then result" << endl << endl;
	do {
		cin >> output;
	} while (!Check(output, 2));
	return output;
}
