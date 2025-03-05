#include <iostream>
#include <cmath>

using namespace std;

int output(int a, int b)
{
    return (a + b);
}

int main()
{
    int a = 0;
    int b = 0;
    int c = 0;
    double x1 = 0;
    double x2 = 0;
    cin >> a >> b >> c;
    int D = b * b - 4 * a * c;
    if (D > 0){
        x1 = (-b + sqrt(D)) / (double)(2 * a);
        x2 = (-b - sqrt(D)) / (double)(2 * a);
        cout << x1 << " " << x2;
        return 0;
    } else if (D == 0){
        x1 = -b / (double)(2 * a);
        int x1_ = x1;
        x1_ % 2 == 0 ? cout << x1 << " " << x1 : cout << x1;
        return 0;
    }
    cout << "No real roots";
}