#include <bits/stdc++.h>
using namespace std;
int n, m, o, l, r, a[1020], b[1020];
int mode() {
	int t = 0;
	for (int i = l; i < r; i++) {
		b[t++] = a[i];
	}
	sort(b, b + t);
	int z = 0, c = 0;
	for (int i = 0, j; i < t; i = j) {
		for (j = i; j < t && b[j] == b[i]; j++) {

		}
		if (j - i > c) {
			z = b[i];
			c = j - i;
		}
	}
	return z;
}
int main() {
	scanf("%d%d", &n, &m);
	for (int i = 0; i < n; i++) {
		scanf("%d", &a[i]);
	}
	for (int i = 0; i < m; i++) {
		scanf("%d%d%d", &o, &l, &r);
		l--;
		if (o) {
			a[l] = r;
		} else {
			printf("%d\n", mode());
		}
	}
}