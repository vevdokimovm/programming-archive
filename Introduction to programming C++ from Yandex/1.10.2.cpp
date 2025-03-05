#include <iostream>

using namespace std;

int main()
{
    char a;
    cin >> a;
    if (a >= 'a' && a <= 'z') {
        char al_num = a - 'a';
        char ans = 'A' + al_num;
        cout << ans;
    } else cout << a;

}