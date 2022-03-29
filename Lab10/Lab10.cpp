#define _CRT_SECURE_NO_WARNINGS 
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <iostream>
using namespace std;

int main() {
	while (1) {
		double number = 0;
		cout << "Enter the values of x: ";
		cin >> number;

		int terms = 0;
		cout << "Enter the number of terms: ";
		cin >> terms;

		double trueValue = log(number);
		double approximateValue = 0;

		for (int j = 1; j < terms; j++) {
			approximateValue += (double)(pow((-1), (j - (double)1)) * pow((number - 1), j) / j);
		}

		double absoluteError = abs(trueValue - approximateValue);
		double relativeError = abs(absoluteError / trueValue) * 100;

		cout << fixed;
		cout << "The number of terms: " << terms << endl;
		cout << "True value: " << trueValue << endl;
		cout << "Approximate value: " << approximateValue << endl;
		cout << "Absolute error: " << absoluteError << endl;
		cout << "Relative error: " << relativeError << endl;
	}
}