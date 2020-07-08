#pragma once
#include <stdio.h>
#include <iostream>
#include <stdexcept>
class SequenceErrors
{
public:
	SequenceErrors(int index) {
		switch (index) {
		case 1: this->No_item(); break;
		case 2: this->StartEndIndex(); break; 
		case 3: this->Incorrect_index(); break; 
		default: break;
		}
		
	}
	void No_item() {
		std::cout << "The item was not found.\n";
	}
	void StartEndIndex() {
		std::cout << "startIndex must be less or equal to endIndex" << std::endl;
	}
	void Incorrect_index() {
		std::cout << "Error - incorrect index!" << std::endl;
	}
};

