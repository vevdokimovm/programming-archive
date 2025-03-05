#include <iostream>
using namespace std;

int main()
{
  int n, m;
  cin >> n >> m;
  int a[100][100] = {0};
  int c = 1, k = 0, x_s = 1, y_s = 0, x = 0, y = 0;
  for (int c = 1; c <= n*m; c++)
  {
    a[y][x] = c;
    x += x_s;
    y += y_s;
    if (x < 0 || y<0 || x>m-1 || y>n-1 || a[y][x] != 0)
    {
      x -= x_s;
      y -= y_s;
      k++;
      if (k == 4)
      {
        k = 0;
      }
      if (k == 0)
      {
        x_s = 1;
        y_s = 0;
      }
      if (k == 1)
      {
        x_s = 0;
        y_s = 1;
      }
      if (k == 2)
      {
        x_s = -1;
        y_s = 0;
      }
      if (k == 3)
      {
        x_s = 0;
        y_s = -1;
      }
      x += x_s;
      y += y_s;
    }
  }


    for(int i = 1; i <= n; i++){
    for(int j = 1; j <= m; j++){
    std::cout.width(4); std::cout << a[i-1][j-1];}
    cout<<endl;}


  return 0;
}