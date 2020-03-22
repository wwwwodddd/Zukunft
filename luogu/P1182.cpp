#include <bits/stdc++.h>
using namespace std;
int n, m;
int a[100020];
bool ok(int M) {
	int s = 0, cnt = 1;
	for (int i = 0; i < n; i++) {
		if (s + a[i] > M) {
			s = 0;
			cnt++;
		}
		s += a[i];
		if (s > M) {
			return false;
		}
	}
	return cnt <= m;
}
int main() {
	scanf("%d%d", &n, &m);
	int L = 0, R = 0;
	for (int i = 0; i < n; i++) {
		scanf("%d", &a[i]);
		R += a[i];
	}
	// L 是不可能的
	// R 是一定可能的 
	while (L < R - 1) {
		// 如果L == R - 1 就退出
		int M = (L + R) / 2;
		if (ok(M)) {
			R = M;
		} else {
			L = M;
		}
	}
	// L == R - 1
	// L 是不可能的
	// R 是可能的 
	printf("%d\n", R);
	return 0;
}