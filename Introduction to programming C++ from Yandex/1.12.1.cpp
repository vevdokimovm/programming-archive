#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main()
{
    int n;
    cin >> n;
    vector <int> l(n);
    for (int i = 0; i < n; i++){
        cin >> l[i];
    }
    sort(l.begin(), l.end());
    for (vector<int>::const_iterator now = l.begin(); now != l.end(); now++){
        cout << *now << " ";
    }
    return 0;
}