#include <iostream>
#include <set>

using namespace std;

int main()
{
    set <int> s;
    set <int> s1;
    set <int> s2;
    int c, c1;
    cin >> c;
    for (int i = 0; i < c; i++){
        int x;
        cin >> x;
        s.insert(x);
    }
    cin >> c1;
    for (int i = 0; i < c1; i++){
        int y;
        cin >> y;
        if (s.find(y) != s.end()){
            s2.insert(y);
        }
        s1.insert(y);
    }
    for (auto now : s2){
        cout << now << " ";
    }
    return 0;
}