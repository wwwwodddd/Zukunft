#include <bits/stdc++.h>
using namespace std;
int n, m, ans;
int a[100020];
int p[100020];
map<int, int> g;
set<int> s;
int main() {
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}
	for (int i = n - 1; i >= 0; i--) {
		if (g.find(a[i]) == g.end()) {
			p[i] = n;
		} else {
			p[i] = g[a[i]];
		}
		g[a[i]] = i;
	}
	for (int i = 0; i < n; i++) {
		if (s.find(i) == s.end()) {
			ans++;
			if (s.size() == m) {
				s.erase(--s.end());
			}
		} else {
			s.erase(i);
		}
		s.insert(p[i]);
	}
	cout << ans << endl;
	return 0;
}