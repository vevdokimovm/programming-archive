#include <iostream>
#include<vector>
#include<algorithm>
#include<cmath>
#include<utility>

using namespace std;

bool comp(pair<int, int> a, pair<int, int> b){
    return sqrt(pow(a.first, 2) + pow(a.second, 2)) < sqrt(pow(b.first, 2) + pow(b.second, 2));
}

int main()
{
    int n;
    cin >> n;
    vector<pair <int, int>> a(n);
    for (int i = 0; i < n; i++){
        int x, y;
        cin >> x >> y;
        a[i] = {x, y};
    }
    sort(a.begin(), a.end(), comp);
    for (auto now : a){
        cout << now.first << " " << now.second << "\n";
    }
    return 0;
}