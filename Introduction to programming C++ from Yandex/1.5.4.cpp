#include <iostream>

using namespace std;

int main()
{
  int N,n=1;
  cin >> N;
  while (n*2<=N)
  {
      n = n*2;
  }
  if (N%n==0)
  {
     cout << "YES" << endl;
  }
  else
  {
      cout << "NO" << endl;
  }
  return 0;
}