#include <bits/stdc++.h>
using namespace std;
int t, n, s, a[22], b[4];
bool dfs(int x) {
	if (x == n) {
		return true;
	}
	for (int i = 0; i < 4; i++) {
		if (b[i] >= a[x]) {
			b[i] -= a[x];
			if (dfs(x + 1)) {
				return true;
			}
			b[i] += a[x];
		}
	}
	return false;
}
int main() {
	scanf("%d", &t);
	for (int tt = 0; tt < t; tt++) {
		scanf("%d", &n);
		s = 0;
		for (int i = 0; i < n; i++) {
			scanf("%d", &a[i]);
			s += a[i];
		}
		b[0] = b[1] = b[2] = b[3] = s / 4;
		if (s % 4 == 0 && dfs(0)) {
			printf("yes\n");
		} else {
			printf("no\n");
		}
	}
	return 0;
}