#include <bits/stdc++.h>
using namespace std;
int t, n;
int a[52];
int v[52];
int g[52][52];
int gcd(int x, int y) {
	return y ? gcd(y, x % y) : x;
}
bool ok() {
	
}
int main() {
	scanf("%d", &t);
	for (int i = 1; i <= 50; i++) {
		for (int j = 1; j <= 50; j++) {
			g[i][j] = gcd(i, j);
		}
	}
	for (int tt = 0; tt < t; tt++) {
		scanf("%d", &n);
		memset(v, 0, sizeof v);
		int g = 0;
		for (int i = 0; i < n; i++) {
			scanf("%d", &a[i]);
			v[a[i]] = 1;
			g = gcd(g, a[i]);
		}
		for (int i = 0; i < )
	}
	return 0;
}
