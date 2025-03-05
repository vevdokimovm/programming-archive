#include <iostream>

using namespace std;

int main()
{
    char a;
    cin >> a;
    a >= '0' && a <= '9' ? cout << "yes" : cout << "no";
    return 0;
}