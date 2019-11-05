#include <bits/stdc++.h>
using namespace std;
int v[100000020];
int c[100000020];
int n = 100000000;
int a[30];
int z[30];
int main() {
	for (int i = 2; i <= n; i++) {
		if (v[i] > 0) {
			continue;
		}
		for (int j = i; j <= n; j += i) {
			v[j] = i;
		}
	}
	for (int i = 2; i <= n; i++) {
		c[i] = c[i - 1];
		if (v[i] == i) {
			c[i]++;
		}
	}
	a[0] = 2;
	a[1] = 1;
	for (; a[0] <= n;) {
		int c = 0;
		for (int i = 0; a[i] != 0; i++) {
			if (v[a[i]] != a[i]) {
				c++;
			}
			if (i > 0) {
				z[c]++;
			}
		}
		int i = 0;
		while (true) {
			a[i]++;
			if (v[a[i]] == a[i]) {
				i++;
			} else {
				break;
			}
		}
	}
	long long ans = 1;
	int mod = 1000000007;
	for (int i = 0; i < 30; i++) {
		if (z[i] > 0) {
			printf("%d %d\n", i, z[i]);
			ans = ans * z[i] % mod;
		}
	}
	cout << ans << endl;
	return 0;
}