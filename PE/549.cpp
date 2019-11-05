#include <iostream>
#include <cstdio>
using namespace std;
int v[100000001];
int n = 100000000;
int a[20];
int b[20];
int c;
int calc(int x) {
	int u = x;
	memset(a, 0, sizeof a);
	memset(b, 0, sizeof b);
	c = 0;
	while (u > 1) {
		if (c == 0 || a[c - 1] != v[u]) {
			c++;
		}
		a[c - 1] = v[u];
		b[c - 1]++;
		u /= v[u];
	}
	int L = 1;
	int R = x;
	while (L < R - 1) {
		int M = (L + R) / 2;
		int ok = 1;
		for (int i = 0; i < c; i++) {
			int have = 0, tmp = M;
			while (tmp > 0) {
				tmp /= a[i];
				have += tmp;
			}
			if (have < b[i]) {
				ok = 0;
			}
		}
		if (ok) {
			R = M;
		} else {
			L = M;
		}
	}
	return R;
}


int main() {
	for (int i = 2; i <= n; i++) {
		if (v[i] == 0) {
			for (int j = i; j <= n; j += i) {
				v[j] = i;
			}
		}
	}
	long long ans = 0;
	for (int i = 2; i <= n; i++) {
		if (i % 1000000 == 0) {
			printf("%d\n", i);
		}
		int tmp = calc(i);
		ans += tmp;
//		printf("%d %d\n", i, tmp);
	}
	printf("%lld\n", ans);
	return 0;
}