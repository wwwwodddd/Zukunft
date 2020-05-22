#include <bits/stdc++.h>
using namespace std;
int n, m, q;
string a[2];
set<int> s[2];
void go(int x, int y) {
	int p0 = *s[0].lower_bound(x);
	int p1 = *s[1].lower_bound(x);
	int p = min(p0, p1);
	if (x + q - y < p) {
		s[0].insert(x + q - y);
		s[1].insert(x + q - y);
		return;
	}
	int v = p;
	int t = p == p1;
	s[t ^ 1].insert(v);
	while (s[t].find(v) != s[t].end()) {
		s[t].erase(v);
		v++;
	}
	if (s[t ^ 1].find(v) != s[t ^ 1].end()) {
		s[t ^ 1].erase(v);
		go(v, y + p - x);
	} else {
		s[t].insert(v);
	}
}
int main() {
	ios::sync_with_stdio(false);
	cin >> n >> m >> q >> a[0] >> a[1];
	reverse(a[0].begin(), a[0].end());
	reverse(a[1].begin(), a[1].end());
	while (a[0].size() < m) {
		a[0].push_back('0');
	}
	while (a[1].size() < n) {
		a[1].push_back('0');
	}
	s[0].insert(1e9);
	s[1].insert(1e9);
	for (int i = max(n, m) - 1; i >= 0; i--) {
		if (a[0][i] == '1' && a[1][i] == '0') {
			s[0].insert(i);
		}
		if (a[0][i] == '0' && a[1][i] == '1') {
			s[1].insert(i);
		}
		if (a[0][i] == '1' && a[1][i] == '1') {
			go(i, 0);
		}
	}
	s[0].insert(-1);
	s[1].insert(-1);
	for (int i = 0; i < 2; i++) {
		auto it = --s[i].end();
		for (int j = *--it; j >= 0; j--) {
			if (j == *it) {
				it--;
				printf("1");
			} else {
				printf("0");
			}
		}
		printf("\n");
	}
	return 0;
}