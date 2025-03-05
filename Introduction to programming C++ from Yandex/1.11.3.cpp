#include <iostream>
#include <set>

using namespace std;

int main()
{
    set <int> s1;
    set <int> s2;
    int n, n1, count = 0, ans = 0;
    cin >> n;
    for (int i = 0; i < n; i++){
        int x;
        cin >> x;
        s1.insert(x);
    }
    cin >> n1;
    for (int i = 0; i < n1; i++){
        int y;
        cin >> y;
        if (s1.find(y) != s1.end()){
            count++;
        }
        s2.insert(y);
    }
    cout << count << endl;
    return 0;
}