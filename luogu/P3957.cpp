#include <bits/stdc++.h>
using namespace std;
int n, d, k;
int x[500020];
int s[500020];
int q[500020], b, f;
long long g[500020];
long long calc(int M) {
	int L = max(1, d - M);
	int R = d + M;
	long long re = 0;
	b = f = 0;
	for (int i = 1, j = 0; i <= n; i++) {
		while (j <= n && x[i] - x[j] >= L) {
			while (b < f && g[j] > g[q[f - 1]]) {
				f--;
			}
			q[f++] = j++;
		}
		while (b < f && x[i] - x[q[b]] > R) {
			b++;
		}
		if (b < f) {
			g[i] = g[q[b]] + s[i];
		} else {
			g[i] = -1e18;
		}
		re = max(re, g[i]);
	}
	return re;
}
int main() {
	scanf("%d%d%d", &n, &d, &k);
	for (int i = 1; i <= n; i++) {
		scanf("%d%d", &x[i], &s[i]);
	}
	int L = -1, R = 1000000007;
	while (L < R - 1) {
		int M = (L + R) / 2;
		if (calc(M) >= k) {
			R = M;
		} else {
			L = M;
		}
	}
	if (R == 1000000007) {
		printf("-1\n");
	} else {
		printf("%d\n", R);
	}
	return 0;
}