#include <iostream>

using namespace std;

int main()
{
  int N,i = 1;
  cin >> N;
  while (i*2<=N)
  {
      cout << i << " ";
      i = i*2;
  }
  cout << i;
  return 0;
}