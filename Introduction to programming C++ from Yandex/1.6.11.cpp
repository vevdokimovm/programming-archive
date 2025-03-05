#include <iostream>
using namespace std;

int main()
{
    double a, b, c, d, e, f;
    cin >> a >> b >> c >> d >> e >> f;
    cout << (d * e - b * f) / (d * a - b * c) <<" "<< (e * c - a * f) / (b * c - a * d);
    return 0;
}