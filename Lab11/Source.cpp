#include <iostream>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
//#include <bits/stdc++.h>
using namespace std;

int main()
{
    float error;
    float angle;
    float exact;
    float approx = 1;
    float sum = 1, t = 1, n = 1;

    cout << "Enter you approx. error bound: " << endl;
    cin >> error;

    cout << "Enter you angle in radians: " << endl;
    cin >> angle;

    exact = cos(angle);

    cout << "N.terms     Exact     Approximate Value     Absolute Error     %Relative Error" << endl;

    for (int i = 1; (exact - approx) <= (exact - approx) * 100 / exact || (approx - exact) <= (approx - exact) * 100 / exact; i++)
    {
        t = t * (-1) * angle * angle / (2 * i * (2 * i - 1));
        approx = approx + t;
        if ((exact - approx) > 0)
        {
            cout << i << "           " << exact << "     " << approx << "              " << fixed << (exact - approx) << "              " << (exact - approx) * 100.0 / exact << endl;
        }
        else if ((approx - exact) > 0)
        {
            cout << i << "           " << exact << "     " << approx << "              " << fixed << (approx - exact) << "              " << (approx - exact) * 100.0 / exact << endl;
        }
    }

    return 0;
}