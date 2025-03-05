#include <iostream>
using namespace std;

int main(){
    int p, x, y;
	cin >> p >> x >> y;
	x = (x * 100 + y) * (p + 100) / 100;
	cout << x / 100 << " " << x % 100;
  return 0;
}