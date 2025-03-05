#include <iostream>

using namespace std;

double power(double c, int y){
    if (y == 0){
        return 1;
    }
    else if (y > 0){
        return c * power(c, y - 1);
    }
    else {
        return 1 / c * power (c, y + 1);
    }
}

int main()
{
    int n;
    double a;
    cin >> a >> n;
    cout << power(a, n) << endl;
    return 0;
}