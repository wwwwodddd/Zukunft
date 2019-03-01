#include <bits/stdc++.h>
using namespace std;
int n, m, s;
int a[500020];
int b[500020];
int c[500020];
long long d[500020];
int main() {
	scanf("%d%d%d", &n, &m, &s);
	for (int i = 0; i < m; i++) {
		scanf("%d%d%d", &a[i], &b[i], &c[i]);
	}
	for (int i = 1; i <= n; i++) {
		d[i] = 2147483647;
	}
	d[s] = 0;
	while (true) {
		bool changed = false;
		for (int i = 0; i < m; i++) {
			if (d[b[i]] > d[a[i]] + c[i]) {
				d[b[i]] = d[a[i]] + c[i];
				changed = true;
			}
		}
		if (!changed) {
			break;
		}
	}
	for (int i = 1; i <= n; i++) {
		printf("%lld%c", d[i], i == n ? '\n' : ' ');
	}
}