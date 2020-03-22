#include <bits/stdc++.h>
using namespace std;
int n;
string s;
map<string, int> g;
int c[100020];
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
	for (int i = 1; i <= n; i++) {
		cin >> s;
		g[s] = i;
	}
	long long ans = 0;
	for (int i = 0; i < n; i++) {
		cin >> s;
		ans += i - query(g[s]);
		change(g[s], 1);
	}
	cout << ans << endl;
	return 0;
}