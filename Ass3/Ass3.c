/**********************************************************************
Student Name : Yuliia Topalova
Student Number : 040981104
Assignment Number : Assignment 3, Maclurin Series Application
Course Name / Number : CST8233 Numerical Computing
Lab Sect : 304
Professor: Hala Own
Due date of assignment: 9 April 2021
Submission date of assignment: 5 April 2021
List of source and header files in the project: ass3.c
***********************************************************************/

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

/*********************************************************************
* Function name: main
* Purpose: main method prints menu, take user input and evaluate 
		   the Maclaurin Series
* In parameters:  nothing
* Out parameters: nothing
* Version: 1
* Author: Yuliia Topalova
********************************************************************/
int main(void) {
	while (1) {
		int x, y, choice;
		double array[7];
		double range;
		double t = 0.0;
		double exact, rExactE, rSerE;
		double series = 0.0;

		printf("Evalute the Maclaurin Series approximation to D(t) = exp(t) * cos(t)\n");
		printf("1: Evaluate the series\n");
		printf("2: Quit\n");
		printf("> ");
		scanf("%d", &choice);
		switch (choice) {

		case 1:
			printf("Evaluating the series\n");
			printf("Please enter the number of (non - zero) terms in the series (1, 2, 3, 4, 5 or 6) :\n");
			// reading user input
			scanf("%d", &x);
			printf("\n");
			while ((getchar()) != '\n');


			if (x >= 1 && x <= 6) {
				// checks if the number of terms between 1 and 6
				printf("Please enter the range of t to evaluate in 10 increments (0.0 < t < +4.0):\n");
				scanf("%lf", &range);
				printf("\n");

				// checks if the range between 0 and 4
				if (range > 0 && range <= 4) {
					printf("\nMACLAURIN SERIES\n");
					printf("   t \t\tD(t) Series \t\tD(t) Exact \t\t%RExactE \t\t%RSerE\n");
				}
				else {
					printf("Please enter valid range!");
					return 0;
				}
			}
			else {
				printf("Please Enter Values between 1 & 6");
				return 0;
			}
			// getting values in the array
			for (int i = 0; i <= 10; i++) {

				series = 0.0;
				array[0] = 1;
				array[1] = t;
				array[2] = (-1 * t * t * t) / 3;
				array[3] = (-1 * t * t * t * t) / 6;
				array[4] = (-1 * t * t * t * t * t) / 30;
				array[5] = (t * t * t * t * t * t * t) / 630;
				array[6] = (t * t * t * t * t * t * t * t) / 2520;

				for (y = 0; y < x; y++) {
					series += array[y];
				}

				exact = exp(t) * cos(t);
				rExactE = 100 * (exact - series) / exact;
				rSerE = 100 * (array[x] / series);

				// outprint the values
				printf("%.3e\t", t);
				printf("%.5e\t\t", series);
				printf("%.5e\t\t", exact);
				printf("%.5e\t\t", rExactE);
				printf("%.5e\n", rSerE);
				t = t + (range / 10);

			}
			printf("\n");
			break;

		case 2:
			exit(0);
			break;

		default:
			printf("Please, enter the valid value!\n");
		}
		while ((getchar()) != '\n');
	}
	return 0;
}