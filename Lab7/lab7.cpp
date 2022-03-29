#define _CRT_SECURE_NO_WARNINGS 
#include<iostream>
#include<math.h>
using namespace std;

double mean(double* array, int n) {
	double sum = 0;
	for (int i = 0; i < n; i++)
		sum += array[i];

	return sum / n;
}

double meanXY(double* x, double* y, int n) {
	double sum = 0;
	for (int i = 0; i < n; i++)
		sum += x[i] * y[i];

	return sum / n;
}
double meanSqrd(double* array, int n) {
	double sum = 0;
	for (int i = 0; i < n; i++)
		sum += pow(array[i], 2);

	return sum / n;
}
int main(){

	int numData = 0;
	cout << "Enter the number of data points:" << endl;
	cin >> numData;
	
	cout << endl;
	
	double* x = new double[numData];
	double* y = new double[numData];

	cout << "Enter the x-axis values" << endl;
	for (int i = 1; i <= numData; i++) {
		cin >> x[i - 1];
	}
	cout << endl;
	cout << "Enter the y-axis values" << endl;
	for (int i = 1; i <= numData; i++) {
		cin >> y[i - 1];
	}

	double slope, b, fittedY;
	double xMean = mean(x, numData);
	double yMean = mean(y, numData);

	slope = ((xMean * yMean) - meanXY(x, y, numData)) / (pow(xMean, 2) - meanSqrd(x, numData));
	b = yMean - slope * xMean;

	cout << "S.no\t\t\t x \t\t\t y(observed) \t\t y(fitted)" << endl;
	cout << "-----------------------------------------------------------------------------------" << endl;
	for (int i = 0; i < numData; i++) {
		fittedY = (slope * x[i]) + b;
		cout << i + 1 << "\t\t\t" << x[i] << "\t\t\t" << y[i] << "\t\t\t" << fittedY << endl;
	}
	cout << endl << "The linear fit line is of the form" << endl;
	cout << endl << "y = " << slope << "x + " << b << endl;
	
	return 0;
}
