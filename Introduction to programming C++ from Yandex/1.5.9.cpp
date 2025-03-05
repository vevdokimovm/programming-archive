#include <iostream>

using namespace std;

int main()
{
    int now, max = 0, second_max = 0;
    cin >> now;
    while (now != 0)
    {
        if (now >= max)
        {
            second_max = max;
            max = now;
        } else if (now >= second_max){
            second_max = now;
        }
        cin >> now;
    }
    cout << second_max ;
    return 0;
}