#include <bits/stdc++.h>
using namespace std;
int n, m;
int a[500020];
int b[500020];
int c[500020];
vector<int> p[500020];
void change(int x, int y) {
	for (int i = x; i <= n; i += i & -i) {
		c[i] += y;
	}
}
int query(int x) {
	int re = 0;
	for (int i = x; i > 0; i -= i & -i) {
		re += c[i];
	}
	return re;
}
int main() {
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		scanf("%d", &b[i]);
	}
	for (int i = 0; i < n; i++) {
		scanf("%d", &a[i]);
		p[b[i]].push_back(a[i]);
	}
	long long ans = 0;
	for (int i = 0; i < n; i++) {
		ans += i - query(a[i]);
		change(a[i], 1);
	}
	memset(c, 0, sizeof c);
	for (int i = 1; i <= n; i++) {
		for (int j = 0; j < p[i].size(); j++) {
			ans -= j - query(p[i][j]);
			change(p[i][j], 1);
		}
		for (int j = 0; j < p[i].size(); j++) {
			change(p[i][j], -1);
		}
	}
	cout << ans << endl;
	return 0;
}
