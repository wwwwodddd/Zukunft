#include <bits/stdc++.h>
using namespace std;
int e, m, n, l, s;
int a[1020];
int b[1020];
int c[1020];
int d[1020];
int main() {
	scanf("%d%d%d%d%d", &e, &m, &n, &l, &s);
	for (int i = 0; i < m; i++) {
		scanf("%d%d", &a[i], &b[i]);
		c[i] = e;
	}
	for (int i = m; i < m + l; i++) {
		scanf("%d%d%d", &a[i], &b[i], &c[i]);
		c[i] = e - c[i];
	}
	memset(d, 0xc0, sizeof d);
	d[s] = e;
	bool changed;
	for (int i = 0; i < n; i++) {
		changed = false;
		for (int i = 0; i < m + l; i++) {
			if (d[a[i]] > -1e9 && d[b[i]] < d[a[i]] + c[i]) {
				d[b[i]] = d[a[i]] + c[i];
				changed = true;
			}
		}
		if (!changed) {
			break;
		}
	}
	if (changed) {
		printf("-1\n");
	} else {
		printf("%d\n", *max_element(d + 1, d + n + 1));
	}
	return 0;
}