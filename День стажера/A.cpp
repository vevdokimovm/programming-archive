#include <iostream>
#include <string>
#include <vector>

using namespace std;

vector<int> makeNums(string& s) {
	vector<int> ans;

	int pow = 1;
	int curNum = 0;
	for(int i = s.size() - 1; i >= 0; --i) {
		if (s[i] == '+') {
			ans.push_back(curNum);
			pow = 1;
			curNum = 0;
		}
		else if (s[i] == '-') {
			ans.push_back(-curNum);
			pow = 1;
			curNum = 0;
		}
		else {
			curNum += (s[i] - '0') * pow;
			pow *= 10;
		}
	}

	ans.push_back(curNum);

	return ans;
}

int main() {
	string s = "";
	std::cin >> s;
	long long ans = 0;

	vector<int> algSum = makeNums(s);

	for (auto num : algSum) {
		ans += num;
	}

	std::cout << ans << endl;

	return 0;
}