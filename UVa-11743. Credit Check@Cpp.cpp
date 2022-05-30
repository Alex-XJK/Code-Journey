#include<iostream>
using namespace std;

#define length 16

//Jiakai XU, June 8 2021, coding for OJ 354Credit Check

int number[length];

int sumDigits() {
	int sum = 0;
	int temp = 0;
	for (int i = length - 1; i >= 0; i--){
		temp = number[i];
		if (temp > 9) {
			sum += 1;
			sum += temp % 10;
		}
		else {
			sum += temp;
		}
	}
	return sum;
}

int main() {
	int times = 0;
	cin >> times;
	char c;
	for (int i = times - 1; i >= 0; i--){
		//Get user input and Double the special digits
		for (int j = 0; j < length; j++){
			cin >> c;
			number[j] = (int)c - 48;
			if (j % 2 == 0) {
				number[j] *= 2;
			}
		}
		//Sum up every digits
		int result = sumDigits();
		//Judge and output
		if (result % 10 == 0) {
			cout << "Valid" << endl;
		}
		else {
			cout << "Invalid" << endl;
		}
	}
	return 0;
}