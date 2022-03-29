#include <iostream>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <iomanip>

using namespace std;

int main() {
    cout << "x\t\t y\t Exact derivative\t  Centered\t  Forward\t  Backward" << endl;
    double x = 0;
    double y = 0 * sin(pow(0, 2)) + 1;
    double exactY = sin(pow(0, 2)) + 2 * pow(0, 2) * cos(pow(0, 2));
    double forwardY = (((0.25) * sin(pow(0.25, 2)) + 1) - (0 * sin(pow(0, 2)) + 1)) / 0.25;

    cout << fixed << setprecision(6) << setfill('0');
    
    cout << x << "\t" << y << "\t" << exactY << "\t\t" << "-" << "\t" << forwardY << "\t\t" << "-" << endl;
    
    for (double x = 0.25; x < 4.0; x = x + 0.25) {

        double xy = x * sin(pow(x, 2)) + 1;
        double exact = sin(pow(x, 2)) + 2 * pow(x, 2) * cos(pow(x, 2));

        double centered = (((x + 0.25) * sin(pow(x + 0.25, 2)) + 1) - ((x - 0.25) * sin(pow(x - 0.25, 2)) + 1)) / (2 * 0.25);
        double forward = (((x + 0.25) * sin(pow(x + 0.25, 2)) + 1) - (x * sin(pow(x, 2)) + 1)) / 0.25;
        double backward = ((x * sin(pow(x, 2)) + 1) - ((x - 0.25) * sin(pow(x - 0.25, 2)) + 1)) / 0.25;
        
        cout << fixed << setprecision(6) << setfill('0');
        cout << x << " \t " << xy << " \t " << exact << " \t " << centered << " \t " << forward << " \t " << backward << endl;
    
    }

    double x4 = 4.0;
    double y4 = x4 * sin(pow(x4, 2)) + 1;
    double exact4 = sin(pow(x4, 2)) + 2 * pow(x4, 2) * cos(pow(x4, 2));
    double backward4 = ((x4 * sin(pow(x4, 2)) + 1) - ((x4 - 0.25) * sin(pow(x4 - 0.25, 2)) + 1)) / 0.25;

    cout << fixed << setprecision(6) << setfill('0');
    cout << x4 << "\t" << y4 << "\t" << exact4 << "\t\t" << "-" << "\t" << "-" << "\t\t" << backward4 << endl;

    return 0;
}
