#include <iostream>

using namespace std;

int main ()
{
    int now, a = 1, b = 0, index = 0;
    cin >> now;
    while (now != b)
    {
        a = a + b;
        b = a - b;
        ++index;
        if (now < b)
        {
            index = -1;
            break;
        }
    }
    cout << index ;
    return 0;
}