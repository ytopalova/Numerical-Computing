#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include<math.h>



double Mean(double array[], int n) {
    float sum = 0;

    for (int i = 0; i < n; i++) {
        sum += array[i];
    }
    return sum / n;
}

double MeanXY(double x[], double y[], int n) {
    float sum = 0;
    for (int i = 0; i < n; i++) {
        sum += x[i] * y[i];
    }
    return sum / n;
}

double Meansquared(double array[], int n) {
    float sum = 0;
    for (int i = 0; i < n; i++) {
        sum += pow(array[i], 2);
    }
    return sum / n;
}


int main() {
    int j = 0;

    double x[90];
    double y[90];

    printf("enter the number of data points:");
    scanf("%d ", &j);

    printf("Enter x axis: ");

    for (int i = 0; i <= j; i++) {
        scanf("%d", &x[i]);

    }
    printf("Enter y axis:");
    for (int i = 0; i <= j; i++) {
        scanf("%d", &y[i]);
    }
    double Meanx = Mean(x, j);
    double Meany = Mean(y, j);
    double yFitted, slope, b;

    slope = ((Meanx * Meany) - MeanXY(x, y, j)) / pow(Meanx, 2) - Meansquared(x, j);
    b = Meany - slope * Meanx;

    
    printf("y = %0.2f x + %0.2f \n", slope, b);
    printf("x \t\t\t y(observed) \t\t y(fitted)\n");
    printf("-----------------------------------------------------------------------------------");
    for (int i = 0; i < j; i++) {
        double fittedY = (slope * x[i]) + b;
        printf ( i, x[i], y[i],fittedY);
    }
   

    return 0;

}

