#include <bits/stdc++.h>
using namespace std;
int t, n;
int a[100020];
int gcd(int x, int y) {
	return y ? gcd(y, x % y) : x;
}
void gao() {
	scanf("%d", &n);
	int g = 0;
	int mx = 0;
	int lp = -1, lv = -1;
	for (int i = 0; i < n; i++) {
		scanf("%d", &a[i]);
	}
	for (int i = 0; i < n; i++) {
		if (a[i] > 0) {
			if (lp >= 0) {
				if (i - a[i] < lp - lv) {
					printf("impossible\n");
					return;
				}
				g = gcd(g, (i - a[i]) - (lp - lv));
			}
			lp = i;
			lv = a[i];
		}
		mx = max(mx, a[i]);
	}
	if (g == 0) {
		printf("inf\n");
		return;
	}
	if (g < mx) {
		printf("impossible\n");
		return;
	}
	printf("%d\n", g);
	return;
}
int main() {
	scanf("%d", &t);
	for (int tt = 0; tt < t; tt++) {
		gao();
	}
	return 0;
}