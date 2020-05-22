#include <bits/stdc++.h>
using namespace std;
int n, k, lc[2];
string s[2020], z;
bitset<10001> f[2020];
pair<int, int> l[2][2020];
int main() {
	ios::sync_with_stdio(0);
	cin >> n >> k;
	for (int i = 0; i < n; i++) {
		cin >> s[i];
	}
	f[n][k] = 1;
	for (int i = n - 1; i >= 0; i--) {
		f[i] = f[i + 1] | (f[i + 1] >> s[i].size());
		if (f[i + 1][s[i].size()]) {
			l[0][lc[0]++] = make_pair(i, 0);
		}
	}
	for (int i = 0, ii = 0; i < k; i++, ii ^= 1) {
		char c = '~';
		for (int jj = 0; jj < lc[ii]; jj++) {
			pair<int, int> j = l[ii][jj];
			c = min(c, s[j.first][j.second]);
		}
		z += c;
		int t = n + 1;
		for (int jj = 0; jj < lc[ii]; jj++) {
			pair<int, int> j = l[ii][jj];
			if (s[j.first][j.second] == c) {
				if (j.second + 1 == s[j.first].size()) {
					t = min(t, j.first);
				} else {
					l[ii ^ 1][lc[ii ^ 1]++] = make_pair(j.first, j.second + 1);
				}
			}
		}
		for (int j = t + 1; j < n; j++) {
			if (i + 1 + s[j].size() <= k && f[j + 1][i + 1 + s[j].size()]) {
				l[ii ^ 1][lc[ii ^ 1]++] = make_pair(j, 0);
			}
		}
		lc[ii] = 0;
	}
	cout << z << endl;
	return 0;
}