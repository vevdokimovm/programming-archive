#include <iostream>
#include <vector>

using namespace std;

vector<int> fromDectoBin(int a){
	int p = 0;
	int twopow = 1;
	vector<int> powers(32);
	while (a){
		if (a > twopow){
			++p;
			twopow *= 2;
		}
		else if (a == twopow) {
			a = 0;
			powers[p] = 1;
			break;
		}
		// a < twopow
		else {
			a -= (twopow / 2);
			powers[p - 1] = 1;
			p = 0;
			twopow = 1;
		}
	}
	return powers;
}

int main(){
	int n;
	cin >> n;
	vector<int> w(n);
	vector<char> ans;
	for (int i = 0; i < n; ++i){
		cin >> w[i];
	}

	// cout << "sldkfjskd\n";
	// vector<int> p1 = fromDectoBin(2049);
	// vector<int> p2 = fromDectoBin(262164);
	// cout << "hi hi hi\n";
	// for (int i = 31; i >= 0; --i) cout << p1[i];
	// cout << endl;
	// for (int i = 31; i >= 0; --i) cout << p2[i];
	
	vector<int> cur_state(32, 0), next_state(32, 0);
	for (int i = 0; i < n; ++i){
		next_state = fromDectoBin(w[i]);
		int index = 0;
		for (int i = 0; i < 32; ++i){
			if (cur_state[i] != next_state[i]){
				index = i;
				break;
			}
		}

		if (index == 26) ans.push_back(' ');
		else ans.push_back('a' + index);
		cur_state = next_state;
	}


	for (auto c : ans) cout << c;
	return 0;
}