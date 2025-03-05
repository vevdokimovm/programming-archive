#include <iostream>

using namespace std;

int min(int a, int b){
    if (a >= b){
        return b;
    } else {
        return a;
    }
}

int min4(int a, int b, int c, int d){
    int r = min(a, b);
    int k = min(c, d);
    if (r >= k){
        return k;
    } else {
        return r;
    }
}

int main()
{
    int r, k, n, l;
    cin >> r >> k >> n >> l;
    cout << min4(r, k, n, l) << endl;
    return 0;
}