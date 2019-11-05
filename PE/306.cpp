#include <stdio.h>
#include <iostream>
using namespace std;
int f[10020];
int v[10020];
int n;
int F(int x) {
	if (x < 68) {
		return f[x];
	} else {
		return f[x % 34 + 68];
	}
}
int main() {
	n = 1000;
	for (int i = 2; i <= n; i++) {
		for (int j = 2; j <= i; j++) {
			v[f[j - 2] ^ f[i - j]] = i;
		}
		while(v[f[i]] == i) {
			f[i]++;
		}
	}
	n = 1000000;
	int ans = 0;
	for (int i = 1; i <= n; i++) {
		if (F(i) != 0) {
			ans++;
		}
	}
	printf("%d\n", ans);
	return 0;
}