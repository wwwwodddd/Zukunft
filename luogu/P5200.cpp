#include <bits/stdc++.h>
using namespace std;
int n;
int c[1000020];
int a[1000020];
int z[1000020];
int v[1000020];
void change(int x, int y) {
	for (int i = x; i <= n; i += i & -i) {
		c[i] += y;
	}
}
int query(int x) {
	int re = 0;
	for (int i = x; i > 0; i -= i & -i) {
		re += c[i];
	}
	return re;
}
int main() {
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		scanf("%d", &a[i]);
		change(a[i], 1);
	}
	int ans = -1;
	for (int i = n - 1; i >= 0; i--) {
		if (i == 0 || a[i - 1] > a[i]) {
			ans = i;
			break;
		}
	}
	printf("%d\n", ans);
	for (int i = ans - 1; i >= 0; i--) {
		change(a[i], -1);
		z[i] = query(a[i]) + ans - 1 - i;
	}
	if (ans == 0) {
		printf("\n");
	} else {
		for (int i = 0; i < ans; i++) {
			printf("%d%c", z[i], i == ans - 1 ? '\n' : ' ');
		}
	}
	return 0;
}