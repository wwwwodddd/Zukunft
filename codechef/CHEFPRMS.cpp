#include <bits/stdc++.h>
using namespace std;
bool P(int x) {
	if (x < 2) {
		return false;
	}
	for (int i = 2; i * i <= x; i++) {
		if (x % i == 0) {
			return false;
		}
	}
	return true;
}
int p[2000], pc;
int q[2000], qc;
int f[2000];
int main() {
	int t, n = 200;
	for (int i = 1; i <= n; i++) {
		if (P(i)) {
			p[pc++] = i;
		}
	}
	for (int i = 0; i < pc; i++) {
		for (int j = 0; j < i; j++) {
			if (p[i] * p[j] <= n) {
				q[qc++] = p[i] * p[j];
			}
		}
	}
	for (int i = 0; i < qc; i++) {
		for (int j = 0; j <= i; j++) {
			f[q[i] + q[j]] = 1;
		}
	}
	scanf("%d", &t);
	for (int tt = 0; tt < t; tt++) {
		scanf("%d", &n);
		if (f[n]) {
			printf("YES\n");
		} else {
			printf("NO\n");
		}
	}
	return 0;
}