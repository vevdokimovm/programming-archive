#include <iostream>
using namespace std;
int main() {
  int a, b;
  cin >> a >> b;
  cout << (109 + a*b%109)%109;
  return 0;
}