#include <iostream>
using namespace std;

int main()
{
    int n1, n2, n3;
    cin >> n1 >> n2 >> n3;
    cout << (n1%2+n1/2) + (n2%2+n2/2) + (n3%2+n3/2);
    return 0;
}