#include <iostream>
#include <math.h>
using namespace std;


int main()
{
    int n;
    double xin, x[5], fx[5], dd[5];
    cout << "Enter the number of point: ";
    cin >> n;
    cout << "Enter the value of x at with interpolated value is needed: ";
    cin >> xin;

    cout << "Enter the value of x: ";
    for (int i = 0; i < n; i++)
    {
        cin >> x[i];
    }
    cout << "Enter the value of f(x)";
    for (int i = 0; i < n; i++)
    {
        cin >> fx[i];
    }
    for (int i = 0; i < n; i++)
    {
        dd[i] = fx[i];
    }
    for (int i = 0; i < n; i++)
    {
        for (int j = n - 1; j >=i+1 + 1;j--)
        {
            dd[j] = (dd[j] - dd[j - 1]) / (x[j] - x[j - 1 - i]);
        }
    }
    double p = 1, v = 0;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < i ; j++)
        {
            p = p * (xin - x[j]);
        }
        v = v + dd[i] * p;
        p = 1;
    }
    cout<<v;
    return 0;
}