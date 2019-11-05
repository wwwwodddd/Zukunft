#include <bits/stdc++.h>
using namespace std;
int v[100100];
int p[100100], pc;
int q[100100];
int a[100100], sum;
int cnt = 0;
long long ans = 0;
long long L = 1e10;
void dfs(int x, long long y) {
	if (sum == 0) {
		printf("%lld\n", y);
		cnt++;
		ans += y;
	}
	for (int i = x; i > 0; i--) {
		long long b = y * p[i];
		long long u = p[i] - 1;
		while (u > 1) {
			a[q[v[u]]]++;
			sum++;
			while (a[q[v[u]]] >= 3) {
				a[q[v[u]]] -= 3;
				sum -= 3;
			}
			u /= v[u];
		}
		for (int j = 1; b < L; b *= p[i], j++) {
			if ((a[i] + 2 * j - 1) % 3 == 0) {
				int o = a[i];
				a[i] -= o;
				sum -= o;
				dfs(i - 1, b);
				a[i] += o;
				sum += o;
			}
		}
		u = p[i] - 1;
		while (u > 1) {
			a[q[v[u]]] += 2;
			sum += 2;
			while (a[q[v[u]]] >= 3) {
				a[q[v[u]]] -= 3;
				sum -= 3;
			}
			u /= v[u];
		}
	}
}
int main() {
	for (int i = 2; i < 100100; i++) {
		if (v[i] > 0) {
			continue;
		}
		p[++pc] = i;
		q[i] = pc;
		for (int j = i; j < 100100; j += i) {
			v[j] = i;
		}
	}
	dfs(pc, 1);
	printf("%d\n", cnt - 1);
	printf("%lld\n", ans - 1);
}