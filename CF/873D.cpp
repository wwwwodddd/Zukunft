#include <bits/stdc++.h>
using namespace std;
int n, k, p, a[100020];
void go(int l, int r) {
	if (k <= 0 || l == r - 1) {
		for (int i = l; i < r; i++) {
			a[i] = ++p;
		}
		return;
	}
	if (k >= 2) {
		int m = (l + r) / 2;
		k -= 2;
		go(m, r);
		go(l, m);
	}
}
int main() {
	scanf("%d%d", &n, &k);
	k--;
	go(0, n);
	if (k == 0) {
		for (int i = 0; i < n; i++) {
			printf("%d%c", a[i], i == n - 1 ? '\n' : ' ');
		}
	} else {
		printf("-1\n");
	}
	return 0;
}