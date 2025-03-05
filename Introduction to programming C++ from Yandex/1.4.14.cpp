#include <iostream>

using namespace std;

int main()
{
    int a, b, c, a1, b1, c1;
    cin >> a >> b >> c >> a1 >> b1 >> c1;
    if (a < b)
        swap(a, b);
    if (a < c)
        swap(a, c);
    if (b < c)
        swap(b, c);
    if (a1 < b1)
        swap(a1, b1);
    if (a1 < c1)
        swap(a1, c1);
    if (b1 < c1)
        swap(b1, c1);
    if(a == a1 && b == b1 && c == c1) {
        cout<<"Boxes are equal";
    } else if (a<=a1 && b <= b1 && c<=c1) {
        cout<<"The first box is smaller than the second one";
    } else if (a>=a1 && b>=b1 && c>=c1) {
        cout<<"The first box is larger than the second one";
    } else {
        cout<<"Boxes are incomparable";
    }
   return 0;
}