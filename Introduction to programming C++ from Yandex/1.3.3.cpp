#include <iostream>
using namespace std;

int main()
{
    int n;
    cin >> n;
    cout << (n - n/100*100)%10;
    return 0;
}