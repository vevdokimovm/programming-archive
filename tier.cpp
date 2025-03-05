#include <bits/stdc++.h>

using namespace std;

#define info(msg) cout << (#msg) << " = " << (msg) << endl;
#define print(msg) cout << (msg) << endl;
#define forv(var, initial, n) for (int (var) = (initial); (var) < (n); (++var));
#define pb push_back
#define fr first
#define sc second
#define prev preww

using ll = long long;
using ull = unsigned long long;
using ld = long double;
using pii = pair<int, int>;
using pll = pair<ll, ll>;
using vi = vector<int>;

const int INF = 2e9;
const ll LINF = 9e18;
const int MOD1 = 2e9 + 11;
const int MOD2 = 1e9 + 9;
const int MOD3 = 1e9 + 7;

//program

struct Node {
    Node(){
        for (int i = 0; i <= 9; ++i) next[i] = nullptr;
        isTerminal = false;
    }

    Node *next[10];
    bool isTerminal;
};

bool is_the_last_one(Node *node){
    Node head = *node;
    for (int i = 0; i <= 9; ++i){
        if (head.next[i] != nullptr) return false;
    }
    return true;
}

bool doesnt_have_prefix(Node node){
    for (int i = 0; i <= 9; ++i){
        if (node.next[i] != nullptr) {
            if (node.next[i]->isTerminal) {
                if (!is_the_last_one(node.next[i])) return false;
            }
            doesnt_have_prefix(*node.next[i]);
        }
    }
    return true;
}

void output_trie(Node head, int lvl = 0){
    cout << lvl << " : \n";
    for (int i = 0; i <= 9; ++i){
        if (head.next[i] != nullptr) cout << i << ' ';
    }
    cout << endl;

    for (int i = 0; i <= 9; ++i){
        if (head.next[i] != nullptr) output_trie(*head.next[i], lvl + 1);
    }
}

int main(){
    //freopen("input.txt", "r', stdin);
    //freopen("output.txt", "w", stdout);
    ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0);
    int t = 0;
    cin >> t;
    vector<string> ans;
    for (int i = 0; i < t; ++i){
        int n = 0;
        cin >> n;
        Node Head;

        //Build Trie
        for (int j = 0; j < n; ++j){
            string s = "";
            cin >> s;
            int len_s = s.size();
            Node cur_head = Head;
            for (int k = 0; k < len_s; ++k){
                int p = s[k] - '0';
                if (cur_head.next[p] == nullptr){
                    cur_head.next[p] = new Node;
                    if (k == len_s - 1) cur_head.next[p]->isTerminal = true;
                    cur_head = *cur_head.next[p];
                }
            }
        }

		//Output of trie. Why empty?
        //output_trie(Head);
        //Algorithm
        if (!doesnt_have_prefix(Head)) ans.pb("NO");
        else ans.pb("YES");
    }
    
	for (auto elem : ans) cout << elem << endl;
    return 0;
}
