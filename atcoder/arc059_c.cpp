#include <bits/stdc++.h>
using namespace std;
int n, c, p = 1000000007;
int a[420], b[420];
long long f[420][420];
int main() {
	f[0][0] = 1;
	scanf("%d%d", &n, &c);
	for (int i = 0; i < n; i++) {
		scanf("%d", &a[i]);
	}
	for (int i = 0; i < n; i++) {
		scanf("%d", &b[i]);
	}
	for (int i = 0; i < n; i++) {
		for (int j = a[i]; j <= b[i]; j++) {
			long long u = 0;
			for (int k = 0; k <= c; k++) {
				u = (u * j + f[i][k]) % p;
				f[i + 1][k] = (f[i + 1][k] + u) % p;
			}
		}
	}
	printf("%lld\n", f[n][c]);
	return 0;
}