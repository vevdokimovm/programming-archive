#include <iostream>

using namespace std;

int main()
{
    char k, al_num, ans;
    cin >> k;
    if (k >= 'a' && k <= 'z'){
        al_num = k - 'a';
        ans = 'A' + al_num;
        cout << ans;
    } else if (k >= 'A' && k <= 'Z'){
        al_num = k - 'A';
        ans = 'a' + al_num;
        cout << ans;
    } else {
        cout << k;
    }
    return 0;
}