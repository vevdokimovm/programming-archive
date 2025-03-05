#include <iostream>
#include <map>
#include <string>

using namespace std;

int main()
{
    map <string, string> m;
    int n;
    cin >> n;
    for (int i = 0; i < n; i++){
        string s;
        string j;
        cin >> s >> j;
        m[s] = j;
        m[j] = s;
    }
    string h;
    cin >> h;
    if (m.find(h) != m.end()){
        cout << m[h];
    }
}