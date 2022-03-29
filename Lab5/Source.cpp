#define _CRT_SECURE_NO_WARNINGS 
#include<iostream>
#include<math.h>
#include<algorithm>
using namespace std;

double mean(double array[], int n) {
	double sum = 0;
	for (int i = 0; i < n; i++)
		sum += array[i];

	return sum / n;
}

double median(double array[], int n) {
	sort(array, array + n);
	if (n % 2 == 0)
		return (array[n / 2 - 1] + array[n / 2]) / 2;/*even*/
	return array[n / 2];/*odd*/
}

double deviatioin(double array[], int n, double mean) {
	double sum = 0;
	for (int i = 0; i < n; i++) {
		sum = sum + pow((array[i] - mean), 2);
	}
	return sqrt(sum / (n - 1));
}

double mode(double array[], int n) {
	int number = array[0];
	int mode = number;
	int count = 1;
	int countMode = 1;

	for (int i = 1; i < check; i++) {
		if (array[i] == number) {
			count++;
		} else {
			if (count > countMode){
				countMode = count;
				mode = number;
			}
			count = 1;
			number = array[i];
		}
	}
	return mode;
}

double range(double array[], int temp) {
	double max = array[0];
	for (int i = 0; i < temp; i++)
	{
		if (max < array[i])
			max = array[i];
	}
	double min = array[0];
	for (int i = 0; i < temp; i++) {
		if (min > array[i])
			min = array[i];
	}
	return max - min;
}



int main() {
	int inputData;

	cout << "Enter the number of students:" << endl;
	cin >> inputData;

	double* array = new double[inputData];

	cout << "Enter the grade:" << endl;
	for (int i = 1; i < inputData+1; i++) {
		cout << "Srudent[" << i << "] - ";
		cin >> array[i-1];
	}
	cout << "Mean = " << mean(array, inputData) << endl;
	cout << "Median = " << median(array, inputData) << endl;
	cout << "Standard deviatioin = " << deviatioin(array, inputData, mean(array, inputData));

	return 0;
}

