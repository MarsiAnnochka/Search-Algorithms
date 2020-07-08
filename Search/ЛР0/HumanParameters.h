#pragma once
#include <iostream>
#include <ctime>

using namespace std;

class HumanParameters
{
private:
	int age;
	float weight;
	float height;
public:
	HumanParameters() {}
	HumanParameters(int new_age, float new_weight, float new_height) {
		this->age = new_age;
		this->weight= new_weight;
		this->height = new_height;
	}

	int GetAge() {
		return age;
	}

	float GetWeight() {
		return weight;
	}

	float GetHeight() {
		return height;
	}

	bool Equal(HumanParameters *item) {
		bool flag = false;
		if ((this->GetAge() == item->GetAge()) && (this->GetWeight() == item->GetWeight()) && (this->GetHeight() == item->GetHeight())) {
			flag = true;
		}
		return flag;
	}

	void Write_result() {
		if (this == nullptr) {
			cout << "Key was not found" << endl << endl;
		}
		else {
			cout << "The key was found. All parameters:" << endl;
			cout << "Age: " << this->GetAge() << endl;
			cout << "Weight: " << this->GetWeight() << endl;
			cout << "Height: " << this->GetHeight() << endl << endl;
		}
	}

	void Generate() {
		this->age = 1 + rand() % 110;
		this->height = 1 + rand() % 220;
		this->weight = 1 + rand() % 300;
	}
};

