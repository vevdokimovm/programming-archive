#include <bits/stdc++.h>

using namespace std;

#define info(msg) cout << (#msg) << " = " << (msg) << endl;
#define print(msg) cout << (msg) << endl;
#define forv(var, initial, n) for (int (var) = (initial); (var) < (n); (++var))
#define pb push_back
#define fi first
#define se second

using ll = long long;
using ull = unsigned long long;
using ld = long double;
using pii = pair<int, int>;
using pll = pair<ll, ll>;
using vi = vector<int>;

const int INF = 2e9;
const long long LINF = 9e18;


int main(){
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0);
    int n;
    cin >> n;
    map<string, vector<string>> m, ans;
    string s = "";
    getline(cin, s);
    for (int i = 0; i < n; ++i){
        getline(cin, s);
        int len = s.size();
        bool flag = false;
        string first = "";
        int start = -1;
        for (int j = 0; j < len; ++j){
            if (s[j] == ' ' && !flag){
                first = s.substr(0, j);
                flag = true;
            }
            else if (s[j] >= 'a' && s[j] <= 'z' && start == -1 && flag){
                start = j;
            }
            else if (s[j] == ','){
                m[first].pb(s.substr(start, j - start));
                start = -1;
            }
        }
        m[first].pb(s.substr(start, len - start));
    }

    for (auto word : m){
        int len = word.se.size();
        for (int i = 0; i < len; ++i){
            ans[word.se[i]].pb(word.fi);
        }
    }

    cout << ans.size() << endl;

    for (auto word : ans){
        int len = word.se.size();
        cout << word.fi << " - ";
        for (int i = 0; i < len - 1; ++i){
            cout << word.se[i] << ", ";
        }
        cout << word.se[len - 1] << endl;
    }

    return 0;
}