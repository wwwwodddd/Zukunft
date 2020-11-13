#include <bits/stdc++.h>
using namespace std;
int n, m, c;
int a[100020];
bool ok(int x) {
	int cnt = 0;
	for (int i = 0, j = 0; i < n; i = j) {
		for (;j < n && j - i < c && a[j] - a[i] <= x;) {
			j++;
		}
		cnt++;
	}
	return cnt <= m;
}
int main() {
	scanf("%d%d%d", &n, &m, &c);
	for (int i = 0; i < n; i++) {
		scanf("%d", &a[i]);
	}
	sort(a, a + n);
	int L = -1;
	int R = 1e9;
	while (L < R - 1) {
		int M = (L + R) / 2;
		if (ok(M)) {
			R = M;
		} else {
			L = M;
		}
	}
	printf("%d\n", R);
	return 0;
}