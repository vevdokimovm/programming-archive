#include <iostream>
#include <cmath>

using namespace std;

int main()
{
    int p, x, y, count = 0, x1, y1, n, sum;
    double total = 0;
    cin >> p >> x >> y >> n;
    sum = x * 100 + y;
    total = sum * ((double)p / 100 + 1);
    total = trunc(total);
    while (count <= n - 2){
        total = total * ((double)p / 100 + 1);
        total = trunc(total);
        count++;
    }
    x1 = total / 100;
    y1 = (int)total % 100;
    cout << x1 << " " << y1;
    return 0;
}