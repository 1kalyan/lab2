#include<iostream>
#include<cmath>
using namespace std;

// Function to calculate factorial
double factorial(double n) {
    if (n <= 1)
        return 1;
    return n * factorial(n - 1);
}

// Function to perform backward difference interpolation
double backwardInterpolation(int n, double xp, double x[], double fx[]) {
    double bd[5][5], h, s;
    
    // Calculate the backward differences table
    for (int i = 0; i < n; i++) {
        bd[i][0] = fx[i];
    }
    for (int j = 1; j < n; j++) {
        for (int i = n - 1; i >= j; i--) {
            bd[i][j] = bd[i][j - 1] - bd[i - 1][j - 1];
        }
    }

    h = x[1] - x[0];
    s = (xp - x[n - 1]) / h;

    double v = bd[n - 1][0], p = 1;
    for (int i = 1; i < n; i++) {
        p = p * (s + i - 1) / factorial(i);
        v = v + (bd[n - 1][i] * p);
    }

    return v;
}

int main() {
    int n;
    double xp, x[5], fx[5];
    cout << "Enter the number of points: ";
    cin >> n;
    cout << "Enter the value of x at which the interpolated value is needed: ";
    cin >> xp;
    cout << "Enter the value of x and fx:\n";
    for (int i = 0; i < n; i++) {
        cin >> x[i] >> fx[i];
    }

    double interpolatedValue = backwardInterpolation(n, xp, x, fx);
    cout << "The interpolated value is: " << interpolatedValue;
    return 0;
}
