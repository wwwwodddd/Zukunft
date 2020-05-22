#include <bits/stdc++.h>
using namespace std;
int n, a[100020];
int c[200020];
void R(int x, int y) {
	for (; x <= 2 * n + 10; x += x & -x) {
		c[x] += y;
	}
}
int G(int x) {
	int re = 0;
	for (; x > 0; x -= x & -x) {
		re += c[x];
	}
	return re;
}
bool ok(int M) {
	memset(c, 0, sizeof c);
	int s = n + 1;
	long long cnt = 0;
	for (int i = 0; i < n; i++) {
		R(s, 1);
		if (a[i] >= M) {
			s++;
		} else {
			s--;
		}
		cnt += G(s);
	}
	return cnt * 2 >= (long long)n * (n + 1) / 2;
}
int main() {
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		scanf("%d", &a[i]);
	}
	int L = 0, R = 1e9 + 1;
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