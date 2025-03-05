#include <iostream>

using namespace std;

int main()
{
int a, b, x, y;
  cin >> x >> y >> a >> b;
  if ((a - x < 2 && a - x > -2) && (b - y < 2 && b - y > -2))
    cout << "YES" << endl;
  else
    cout << "NO" << endl;
}