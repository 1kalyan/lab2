#include<iostream>
#include<cmath>
using namespace std;


double factorial(double n) {
    if (n <= 1)
        return 1;
    return n * factorial(n - 1);
}

int main() {
    int n;
    double xp, x[5], fx[5], fd[5][5], h, s;
    cout << "Enter the number of points: ";
    cin >> n;
    cout << "Enter the value of x at which the interpolated value is needed: ";
    cin >> xp;
    cout << "Enter the value of x and fx:\n";
    for (int i = 0; i < n; i++) {
        cin >> x[i] >> fx[i];
    }

    for (int i = 0; i < n; i++) {
        fd[i][0] = fx[i];
    }
    for (int j = 1; j < n; j++) {
        for (int i = 0; i < n - j; i++) {
            fd[i][j] = fd[i + 1][j - 1] - fd[i][j - 1];
        }
    }

    h = x[1] - x[0];
    s = (xp - x[0]) / h;

    double v = fd[0][0], p = 1;
    for (int i = 1; i < n; i++) {
        p = p * (s - i + 1) / factorial(i);
        v = v + (fd[0][i] * p);
    }
    cout << "The interpolated value is: " << v;
    return 0;
}