#include <iostream>

using namespace std;

int main()
{
  int a, b = 2;
  cin >> a;
    while ( a % b != 0 )
    {
         b = b + 1;
    }
    cout << b;
  return 0;
}