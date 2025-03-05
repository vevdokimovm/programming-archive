#include <iostream>

using namespace std;

int main()
{
    int n, count = 0;
    double r_1, x, r, sum = 0;
    cin >> n >> x >> r;
    if (n == 0){
        sum = r;
    } else {
        r_1 = r;
        cin >> r;
        sum = r_1 * x + r;
    }
    while (count <= n - 2){
        cin >> r;
        sum = sum * x + r;
        count++;
    }
    cout << sum << endl;
    return 0;
}