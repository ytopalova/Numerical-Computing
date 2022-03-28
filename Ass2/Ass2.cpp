/**********************************************************************
Student Name : Yuliia Topalova
Student Number : 040981104
Assignment Number : Assignment 2, Linear regression least-squares method 
Course Name / Number : CST8233 Numerical Computing
Lab Sect : 304
Professor: Hala Own
Due date of assignment: 19 March 2021
Submission date of assignment: 17 March 2021
List of source and header files in the project: ass2.cpp
***********************************************************************/
#define _CRT_SECURE_NO_WARNINGS 
#define _CRTDBG_MAP_ALLOC
#include <iostream>
#include <algorithm>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

using namespace std;

/*********************************************************************
* Function name: calculation
* Purpose: calculate prognostic index
* In parameters:  double a0, double a1
* Out parameters: nothing
* Version: 1
* Author: Yuliia Topalova
********************************************************************/
void calculation(double a0, double a1) {
	int days;
	cout << "Please enter the days to extrapolate to: ";
	cin >> days;
	cout << "Days = " << days << endl;

	printf("Prognostic index = %.1f\n", pow(2.718, a0) * pow(2.718, days * a1));
	fflush(stdin);
}

/*********************************************************************
* Function name: median
* Purpose: calculate equation for mean
* In parameters:  double a[], int n
* Out parameters: the value of the median
* Version: 1
* Author: Yuliia Topalova
********************************************************************/
double median(double a[], int n) {
	sort(a, a + n);

	if (n % 2 != 0) {
		return a[n / 2];
	}
	double index1 = a[(n - 1) / 2];
	double index2 = a[n / 2];
	return (index1 + index2) / 2.0;
}

/*********************************************************************
* Function name: deviation
* Purpose: calculate equation for deviation
* In parameters:  double a[], double mean, int n
* Out parameters: the value of the deviation
* Version: 1
* Author: Yuliia Topalova
********************************************************************/
double deviation(double a[], double mean, int n) {
	double standardDeviation = 0.0;

	for (int i = 0; i < n; ++i) {
		standardDeviation += pow((a[i] - mean), 2);
	}
	return sqrt(standardDeviation / (n - 1.0));
}

/*********************************************************************
* Function name: mean
* Purpose: calculate equation for the mean
* In parameters: double a[], int n
* Out parameters: the value of the mean
* Version: 1
* Author: Yuliia Topalova
********************************************************************/
double mean(double a[], int n) {
	double sum = 0.0;

	for (int i = 1; i < n + 1; i++) {
		sum += a[i - 1];
	}
	return sum / n;
}

/*********************************************************************
* Function name: range
* Purpose: calculate the value of the range
* In parameters:  double a[], int n
* Out parameters: the value of the range
* Version: 1
* Author: Yuliia Topalova
********************************************************************/
double range(double a[], int n) {
	sort(a, a + n);

	return a[n - 1] - a[0];
}

/*********************************************************************
* Function name: mode
* Purpose: calculate the mode
* In parameters:  double a[], int n
* Out parameters: the value of the mode
* Version: 1
* Author: Yuliia Topalova
********************************************************************/
double mode(double a[], int n) {
	double mode = a[0]; 
	int counter = 1;
	int max = 0; 
	
	for (int i = 0; i < n - 1; i++) {
		if (a[i] == a[i + 1]) {
			counter++;
			if (counter > max) {
				max = counter;
				mode = a[i];
			}
		}else {
			counter = 1;
		}
	}
	return mode;
}

/*********************************************************************
* Function name: equationA
* Purpose: calculate equation for function A
* In parameters:  double x[], double y[], int n, double a0, double a1
* Out parameters: the value fron our equationA
* Version: 1
* Author: Yuliia Topalova
********************************************************************/
double standartError(double x[], double y[], int n, double a0, double a1) {
	double fitted[100];
	double error[100];
	double sError[100];
	double sum = 0;
	double standErr;

	for (int i = 1; i <= n; i++) {
		fitted[i - 1] = exp(a0) * (a1 * x[i - 1]);
	}
	for (int i = 1; i <= n; i++) {
		error[i - 1] = y[i - 1] - fitted[i - 1];
	}
	for (int i = 1; i <= n; i++) {
		sError[i - 1] = pow(error[i - 1], 2);
	}
	for (int i = 1; i <= n; i++) {
		sum += sError[i - 1];
	}
	standErr = sqrt(sum / (n - 2));
	return standErr;
}

/*********************************************************************
* Function name: submenu
* Purpose: this method displays submenu
* In parameters:  double a0, double a1
* Out parameters: nothing
* Version: 1
* Author: Yuliia Topalova
********************************************************************/
void submenu(double a0, double a1) {
	bool run = true;
	char choice;

	do {
		cout << "MENU\n\n1. Extrapolation\n2. Main Menu\n> ";
		cin >> choice;
		fflush(stdin);

		switch (choice) {
		case '1':
			calculation(a0, a1);
			break;
		case '2':
			run = false;
			cout << "Exiting...." << endl;
			break;
		default:
			fflush(stdin);
			cout << "Invalid input\n" << endl;
			break;
		}
	} while (run);
}

/*********************************************************************
* Function name: read_file
* Purpose: this method reads file and send values to another methods
* In parameters:  file
* Out parameters: the values from the file
* Version: 1
* Author: Yuliia Topalova
********************************************************************/
void read_file() {
	FILE* file;
	char file_name[255];
	double pointX = 0.0, pointY = 0.0;
	double pointX2 = 0.0, pointY2 = 0.0;
	double sumX = 0.0, sumY = 0.0;
	double sumX2 = 0.0, sumXY = 0.0;
	double a0 = 0.0, a1 = 0.0;

	cout << endl << "Please enter the name of the file to open: ";
	cin >> file_name;

	fflush(stdin);
	file = fopen(file_name, "r");

	if (!file) {
		perror(file_name);
		cout << endl;
		return;
	}
	if (file) {
		char line[1000];
		int  line_count = 0;
		double yValue[100];
		double xValue[100];
		char* text = fgets(line, 1000, file);

		cout << text;
		while (fgets(line, sizeof line, file)) {
			line_count++;
			sscanf_s(line, "%lf %lf", &pointX, &pointY);

			yValue[line_count - 1] = pointY;
			xValue[line_count - 1] = pointX;

			cout << pointX << "\t" << pointY << "\n";
			fflush(stdin);

			sumX += pointX;
			sumY += pointY;
			sumX2 += pointX * pointX;
			pointY2 += log(pointY);
			sumXY += pointX * log(pointY);
			pointX2 = sumX * sumX;

			a0 = (pointY2 - a1 * sumX) / line_count;
			a1 = ((line_count * sumXY) - (sumX * pointY2)) / ((line_count * sumX2) - pointX2);
		}
		fclose(file);

		cout << "There are " << line_count << " records.\n" << endl;
		cout << "Data Summary (Prognostic Index):\n" << endl;
		cout << "Mean = " << mean(yValue, line_count) << endl;
		cout << "Median = " << median(yValue, line_count) << endl;
		cout << "Range = " << range(yValue, line_count) << endl;
		cout << "Mode = " << mode(yValue, line_count) << endl;
		cout << "Standard Deviation = " << deviation(yValue, mean(yValue, line_count), line_count) << endl;
		cout << "Standard Error = " << standartError(xValue, yValue, line_count, a0, a1) << endl;
		printf("Linear Regression Fit. Prognostic index = %.1f*exp %.3f*days\n\n", exp(a0), a1);

		submenu(a0, a1);
	}
}

/*********************************************************************
* Function name: main
* Purpose: main method displaying main menu
* In parameters:  nothing
* Out parameters: nothing
* Version: 1
* Author: Yuliia Topalova
********************************************************************/
int main(void) {
	bool loop = true;
	int choice;
	_CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);

	do {
		cout << "LEAST SQUARES LINEAR REGRESSION\n\nMENU\n1. Exponential Fit\n2. Quit\n> ";
		cin >> choice;
		fflush(stdin);

		switch (choice) {
		case 1:
			read_file();
			break;
		case 2:
			loop = false;
			cout << "Exiting..." << endl;
			break;
		default:
			cout << "Please enter a valid option\n";
			break;
		}
	} while (loop);

	return 0;
}