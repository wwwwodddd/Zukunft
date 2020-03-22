#include <bits/stdc++.h>
using namespace std;
int n, m;
int a[100020];
bool ok(int M) {
	long long cnt = 0;
	for (int i = 0; i < n; i++) {
		cnt += a[i] / M;
	}
	return cnt >= m;
}
int main() {
	scanf("%d%d", &n, &m);
	int L = 0, R = 1e9;
	for (int i = 0; i < n; i++) {
		scanf("%d", &a[i]);
	}
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