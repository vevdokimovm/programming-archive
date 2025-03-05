#include <iostream>
#include <cmath>

using namespace std;

int MinDivisor(int a, int b, double c){
    int res = a / b;
    if (a == 1){
        return 1;
    } else if (a == 0) {
        return 0;
    } else if (res * b == a && b <= c){
        return b;
    } else if (b > c){
        return a;
    } else {
        return MinDivisor(a, b + 1, c);
    }
}

bool IsPrime(int a, int b, double c){
    return MinDivisor(a, b, c) == a;
}

int main()
{
    int n, div = 2;
    double sqrtn;
    cin >> n;
    sqrtn = sqrt(n);
    if (IsPrime(n, div, sqrtn)){
        cout << "YES";
    } else {
        cout << "NO";
    }
    return 0;
}