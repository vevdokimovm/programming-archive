#include <iostream>



using namespace std;

int main()
{
    int i=1,N;
    cin >> N;
    while (i*i<=N)
    {
        cout << i*i << " ";
        i = i+1;
    }
  return 0;
}