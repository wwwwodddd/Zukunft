#include <bits/stdc++.h>
using namespace std;
int n, m;
int a[100020];
bool ok(int M) {
	int p = a[0], cnt = 1;
	for (int i = 1; i < n; i++) {
		if (a[i] - p >= M) {
			p = a[i];
			cnt++;
		}
	}
	return cnt >= m;
}
int main() {
	scanf("%d%d", &n, &m);
	int L = 0, R = 1e9;
	for (int i = 0; i < n; i++) {
		scanf("%d", &a[i]);
	}
	sort(a, a + n);
	while (L < R - 1) {
		int M = (L + R) / 2;
		if (ok(M)) {
			L = M;
		} else {
			R = M;
		}
	}
	printf("%d\n", L);
	return 0;
}