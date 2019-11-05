#include <iostream>
#include <cstdio>
using namespace std;
int v[100000020];
int a[100];
int b[100];
int w[10000];
int c;
int n = 100000000;
long long ans = 0;
void dfs(int x, int s) {
	if (x == c) {
		w[s]++;
		return;
	}
	for (int i = 0; i <= b[x]; i++) {
		dfs(x + 1, s + i);
	}
	return;
}
int main() {
	for (int i = 2; i <= n; i++) {
		if (v[i] > 0) {
			continue;
		}
		for (int j = i; j <= n; j += i) {
			v[j] = i;
		}
	}
	for (int i = 1; i <= n; i++) {
		if (i % 100000 == 0) {
			printf("%d\n", i);
		}
		memset(w, 0, sizeof w);
		int x = i;
		int sum = 0;
		c = 0;
		while (x > 1) {
			if (c == 0 || a[c - 1] != v[x]) {
				c++;
				a[c - 1] = v[x];
				b[c - 1] = 0;
			}
			b[c - 1]++;
			sum++;
			x /= v[x];
		}
		dfs(0, 0);
		int tmp = 0;
		for (int i = 0; i <= sum; i++) {
			tmp = max(tmp, w[i]);
		}
		ans += tmp;
	}
	printf("%lld\n", ans);
	return 0;
}