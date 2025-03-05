#include <iostream>
#include <cmath>
using namespace std;

int main()
{
    double a, b, c, x, x1, D, D_2;
    cin >> a >> b >> c;
    D = b*b - 4 * a * c;
    if (D < 0)
    {
        cout << " ";
    }
    else if (D == 0)
    {
        x = -b / (2*a);
        cout << x;
    }
    else if (D > 0)
    {
        D_2 = sqrt(D);
        x = (-b + D_2) / (2*a);
        x1 = (-b - D_2) / (2*a);
        if (x > x1)
        {
            cout << x1 <<" "<< x;
        }
        else
        {
            cout << x << " " << x1;
        }
    }
    return 0;
}