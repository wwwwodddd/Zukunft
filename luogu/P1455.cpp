#include <bits/stdc++.h>
using namespace std;
int n, m, w;
int c[10020];
int d[10020];
int f[10020];
int dp[10020];
int F(int x) {
	return f[x] != x ? f[x] = F(f[x]) : x;
}
int main() {
	cin >> n >> m >> w;
	for (int i = 1; i <= n; i++) {
		cin >> c[i] >> d[i];
		f[i] = i;
	}
	for (int i = 0; i < m; i++) {
		int x, y;
		cin >> x >> y;
		x = F(x);
		y = F(y);
		if (x != y) {
			c[y] += c[x];
			d[y] += d[x];
			f[x] = y;
		}
	}
	for (int i = 1; i <= n; i++) {
		if (F(i) == i) {
			for (int j = w; j >= c[i]; j--) {
				dp[j] = max(dp[j], dp[j - c[i]] + d[i]);
			}
		}
	}
	cout << dp[w] << endl;
}