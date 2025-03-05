#include <iostream>

using namespace std;

int main() 
{
   int max, now;
  cin >> now;
  max = now;
  int i = 1;
  while (now != 0) 
  {
    if (now > max) 
    {
      i = 1;
      max = now; 
    }
    
    cin >> now;
    if (max == now) i++;
  }
  cout << i;
  return 0;
}