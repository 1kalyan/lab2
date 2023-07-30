#include <iostream>
using namespace std;

int main()
{
    double n, a[5], b[5], x, y = 0; // Initialize y to 0
    cout << "Enter the number of data points: ";
    cin >> n;

    for (int i = 0; i < n; i++)
    {
        cout << "Enter the value of x and functional value of x: ";
        cin >> a[i] >> b[i];
    }

    cout << "Enter the value of x to find functional value: ";
    cin >> x;

    for (int i = 0; i < n; i++)
    {
        double no = 1, de = 1; // Initialize no and de for each i
        for (int j = 0; j < n; j++) // Use j < n instead of j <= n
        {
            if (i != j)
            {
                no *= (x - a[j]);
                de *= (a[i] - a[j]);
            }
        }
        y += (no / de) * b[i];
    }
    cout << "Interpolated functional value at x = " << x << " is: " << y << endl;
    return 0;
}
