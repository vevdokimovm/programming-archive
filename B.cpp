#include <iostream>
#include <vector>

using namespace std;

vector<vector<char>> mapVert(vector<vector<char>> const& w){
	int n = w.size();
	int m = w[0].size();
	vector<vector<char>> res(n, vector<char>(m, '\0'));
	for (int i = 0; i < n; ++i){
		for (int j = 0; j < m; ++j){
			res[i][(m - 1) - j] = w[i][j];
		}
	}

	for (int i = 0; i < n; ++i){
		for (int j = 0; j < m; ++j){
			if (res[i][j] == '\\') res[i][j] = '/';
			else if (res[i][j] == '/') res[i][j] = '\\';
		}
	}

	return res;
}

vector<vector<char>> mapHoriz(vector<vector<char>> const& w){
	int n = w.size();
	int m = w[0].size();
	vector<vector<char>> res(n, vector<char>(m, '\0'));
	for (int i = 0; i < n; ++i){
		for (int j = 0; j < m; ++j){
			res[(n - 1) - i][j] = w[i][j];
		}
	}

	return res;
}

int main(){
	int n, m;
	cin >> n >> m;
	vector<vector<char>> w(n, vector<char>(m));

	for (int i = 0; i < n; ++i){
		for (int j = 0; j < m; ++j){
			cin >> w[i][j];
		}
	}

	w = mapVert(w);
	w = mapHoriz(w);

	for (int i = 0; i < n; ++i){
		for (int j = 0; j < m; ++j){
			cout << w[i][j];
		}
		cout << endl;
	}
	return 0;
}