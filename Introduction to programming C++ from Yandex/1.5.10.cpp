#include <iostream>

using namespace std;

int main ()
{
    int now, a = 1, b = 0, index = 0;
    cin >> now;
    while (now != index)
    {
        a = a + b;
        b = a - b;
        ++index;
        if (now == 0)
        {
            b = 0;
        }
        else if (now == 1)
        {
            b = 1;
        }
    }
    cout << b ;
}