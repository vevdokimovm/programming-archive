#include <iostream>
#include <cmath>
using namespace std;
int main()
{
  int n, k = 0;
  cin >>n;
  for(int i = n -1; i>0; i--){
  i -= k;
  k++; }
  cout << k;
}