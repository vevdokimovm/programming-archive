#include <iostream>
#include <cmath>
using namespace std;
int main() {
  int h = 0;
  int a = 0;
    int b = 0;
    cin >> h >> a >> b;
  cout << (h - b + a - b - 1) / (a - b);
  return 0;
}