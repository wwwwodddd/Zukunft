#include <bits/stdc++.h>
using namespace std;
int n, m, l, z;
int c[20020];
bitset<20020> dp;
int f[20020];
int F(int x) {
	return f[x] != x ? f[x] = F(f[x]) : x;
}
int main() {
	cin >> n >> l >> m;
	for (int i = 1; i <= n; i++) {
		f[i] = i;
		c[i] = 1;
	}
	for (int i = 0; i < m; i++) {
		int x, y;
		cin >> x >> y;
		x = F(x);
		y = F(y);
		if (x != y) {
			c[y] += c[x];
			f[x] = y;
		}
	}
	dp[0] = 1;
	for (int i = 1; i <= n; i++) {
		if (F(i) == i) {
			dp |= dp << c[i];
		}
	}
	for (int i = 0; i <= n; i++) {
		if (dp[i] && abs(z - l) > abs(i - l))
		{
			z = i;
		}
	}
	cout << z << endl;
	return 0;
}