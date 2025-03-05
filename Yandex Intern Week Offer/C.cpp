#include <iostream>
#include <vector>

using namespace std;

int main() {
	int n = 0;
	cin >> n;
	vector<int> dp(n + 1, 0);
	dp[0] = 0;
	dp[1] = 1;

	for (int i = 1, elem = 0; i <= n; ++i) { 
		cin >> elem;
		dp[i] = dp[elem] + 1;
	}

	int repNum = 0;
	int affected = 0;
	for (int i = 1; i <= n; ++i) {
		if (dp[i] > affected){
			repNum = i;
			affected = dp[i];
		}
	}

	cout << repNum << endl;

	return 0;
}