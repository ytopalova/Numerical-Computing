/**********************************************************************
Student Name : Yuliia Topalova
Student Number : 040981104
Assignment Number : Assignment 1, Lagrange Interpolation 
Course Name / Number : CST8233 Numerical Computing
Lab Sect : 304  
Professor: Hala Own
Due date of assignment: 7 February 2021
Submission date of assignment: 7 February 2021
List of source and header files in the project: ass1.c
***********************************************************************/
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <math.h> 

/********************************************************************
* Function name: lagrange
* Purpose: calculate lagrange
* In parameters: int n, double x, double* xk, double* fk
* Out parameters: p
* Version: 1
* Author: Yuliia Topalova
**********************************************************************
Lagrange interpolation
n - number of points
x - where to evaluate
xk[n] - nodes
fk[n] - function values
*********************************************************************/
double lagrange(int n, double x, double* xk, double* fk) {
	int i, k;
	double p, lk;
	p = 0.0;
	for (k = 0; k < n; k++) {
		lk = 1.0;
		for (i = 0; i < n; i++) {
			if (i == k) continue;
			/* accumulate Lk(x) */
			lk *= (x - xk[i]) / (xk[k] - xk[i]);
		}
		/* accumulate the sum */
		p += lk * fk[k];
	}
	return p;
}
/********************************************************************
* Function name: equationA
* Purpose: calculate equation for function A
* In parameters:  double x
* Out parameters: the value fron our equationA
* Version: 1
* Author: Yuliia Topalova
*****************************************/
static double equationA(double x) {
	return (sqrt(1.0 + pow(x, 2))); 
}

/********************************************************************
* Function name: equationB
* Purpose: calculate equation for function B
* In parameters:  double x
* Out parameters: the value fron our equationB
* Version: 1
* Author: Yuliia Topalova
*****************************************/
static double equationB(double x) {
	return (1.0 / (1.0 + 25 * pow(x, 2)));
}

/***********************************************************************
* Function name: functionA
* Purpose: to calculate and output the true value and the absolute error
*			with different orders
* In parameters:  none
* Out parameters: the value fron our equationA
* Version: 1
* Author: Yuliia Topalova
***********************************************************************/
void functionA () {
	int k;
	double p, t, a, xk;
	double y[41], x[99], f[99];
	
	/*calculating the y values for each x*/
	for (k = 0; k < 41; k++) {
		y[k] = -1.0 + 2.0 * k / (41 - 1);
	}
	/*generated different orders*/
	for (int n = 5; n <= 15; n += 5) {
		printf("\nWhen n = %d\n", n);
		printf("K	Xk		 P	     True value 	Absolute Error\n");

		/*starting building our table for each n*/
		for (k = 0; k < n; k++) {
			/* calculating  values*/
			xk = -1.0 + 2.0 * k / n;
			f[k] = equationA(xk);
			x[k] = xk;
		}
		
		for (k = 0; k < 41; k++) {
			xk = y[k];
			/* Calling polynomial for calculations*/
			p = lagrange(n, xk, x, f); 
			/* Rounding polynomial to 6 decimal */
			p = round(p * 1000000.0) / 1000000.0; 
			t = equationA(xk); /* true value */
			a = t - p; /* absolute error calculation */
			
			printf("%d	%f	%f	%f	%0.2E \n", k, xk, p, t, fabs(a));
			
		}
	}
}

/***********************************************************************
* Function name: functionB
* Purpose: to calculate and output the true value and the absolute error
*			with different orders
* In parameters:  none
* Out parameters: none
* Version: 1
* Author: Yuliia Topalova
***********************************************************************/
void functionB() {
	int k;
	double p, t, a, xk;
	double y[41], x[99], f[99];

	/*calculating the y values for each x*/
	for (k = 0; k < 41; k++) {
		y[k] = -1.0 + 2.0 * k / (41 - 1);
	}
	/*generated different orders*/
	for (int n = 5; n <= 15; n += 5) {
		printf("\nWhen n = %d\n", n);
		printf("K	Xk		 P	     True value 	Absolute Error\n");

		/*starting building our table for each n*/
		for (k = 0; k < n; k++) {
			/* calculating  values*/
			xk = -1.0 + 2.0 * k / n;
			f[k] = equationB(xk);
			x[k] = xk;
		}

		for (k = 0; k < 41; k++) {
			xk = y[k];
			/* Calling polynomial for calculations*/
			p = lagrange(n, xk, x, f);
			/* Rounding polynomial to 6 decimal */
			p = round(p * 1000000.0) / 1000000.0;
			t = equationB(xk); /* true value */
			a = t - p; /* absolute error calculation */
			/*printing our table*/
			printf("%d	%f	%f	%f	%0.2E \n", k, xk, p, t, fabs(a));
		}
	}
}

/***********************************************************************
* Function name: main
* Purpose: output the menu and callingthe functions
* In parameters:  none
* Out parameters: none
* Version: 1
* Author: Yuliia Topalova
***********************************************************************/
int main() {
	int choice;
	printf("Lagrange Interpolation\n");
	printf("Menu\n");
	printf("1. Fanction A\n");
	printf("2. Fanction B\n");
	printf("3. Quit\n");
	printf("Enter your choice :");

	scanf("%d", &choice);/* reading choice*/
	switch (choice) {
	case 1:
		functionA(); /*calling function A*/
		break;
	case 2:
		functionB(); /*calling function B*/
		break;
	}while (choice != 3); /*close the program if choice is 3*/
	return(0);
}