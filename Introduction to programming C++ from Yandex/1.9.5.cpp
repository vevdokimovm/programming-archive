#include <iostream>
#include <cmath>

using namespace std;

bool IsPointInCircle(double x, double y, double xc, double yc, double r){
    return pow(xc - x, 2) + pow(yc - y, 2) <= r * r;
}

int main()
{
    double x, y, xc, yc, r;
    cin >> x >> y >> xc >> yc >> r;
    if (IsPointInCircle(x, y, xc, yc, r)){
        cout << "YES";
    }
    else {
        cout << "NO";
    }
    return 0;
}