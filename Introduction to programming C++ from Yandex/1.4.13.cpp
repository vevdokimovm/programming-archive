#include <iostream>
using namespace std;

int main()
{
    int a, b, c;
    cin >> a >> b >> c;
    int the_most;
    int number_2;
    int number_3;
    if (a>=b && a>=c)
    {
        the_most = a;
        number_2 = b;
        number_3 = c;
    }
    if (b>=a && b>=c)
    {
        the_most = b;
        number_2 = a;
        number_3 = c;
    }
    if (c>=a && c>=b)
    {
        the_most = c;
        number_2 = a;
        number_3 = b;
    }
    int number_1;
    int number_4;
    if (number_2<=number_3)
    {
        number_1 = number_2;
        number_4 = number_3;
    }
    else
    {
        number_1 = number_3;
        number_4 = number_2;
    }
    cout << number_1 <<" "<< number_4 <<" "<< the_most << endl;
    return 0;
}