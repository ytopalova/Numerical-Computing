#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

using namespace std;

double function(double x) {
	return sqrt(x);
}

double power(double x) {
	return pow(2, x);
}

double trapezoidal(double a, double b, double n) {
	double h = (b - a) / n;
	double s = function(a) + function(b);

	for (int i = 1; i < n; i++) {
		s += 2 * function(a + (i * h));
	}
	return (h / 2) * s;
}

int main() {
	double begin = 0.0;
	double end = 1.0;
	double answer = 2.0 / 3.0;
	double n, integral, absError;

	printf("%s       %s       %s\n", "N",  "Trapezoid",  "Absolute Error" );
	for (int i = 1; i <= 9; i++) {
		n = power(i);
		integral = trapezoidal(begin, end, n);
		absError = answer - integral;		
		
		printf("%g       %f       %f\n", n, integral, absError);
		
	}
	return 0;
}