#include <iostream>

using namespace std;

int main()
{
    int a;
    cin >> a;
    int b = a % 1000;
    int b1 = b % 10;
    int b2 = a / 1000;
    int c = b / 100;
    int c1 = b / 10 % 10;
    if (b1 == b2 && c1 == c){
        cout << 1;
    } else {
        cout << 37;
    }
    return 0;
}