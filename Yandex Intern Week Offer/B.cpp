#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int n, k;
    cin >> n >> k;
    vector<int> l(n);
    
    for (int i = 0; i < n; ++i) cin >> l[i];

    sort(l.begin(), l.end());
    
    int ans = 0;
    if (k % 2 == 0) ans = l[n - 1 - k / 2] - l[k / 2];
    else { // k % 2 == 1
        int DifIfRightDeleted = l[n - 1 - k / 2 - 1] - l[k / 2];
        int DifIfLeftDeleted = l[n - 1 - k / 2] - l[k / 2 + 1];
        ans = min(DifIfRightDeleted, DifIfLeftDeleted);
    }
    
    cout << ans << endl;
    
    return 0;
}