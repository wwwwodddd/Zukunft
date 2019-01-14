#include <bits/stdc++.h>
using namespace std;
int n;
int f[1020];
int F(int x) {
	return f[x] != x ? f[x] = F(f[x]) : x;
}
int main() {
	scanf("%d", &n);
	for (int i = 1; i <= n; i++) {
		f[i] = i;
	}
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j < i; j++) {
			if (F(i) == F(j)) {
				continue;
			}
			printf("Q %d %d\n", i, j);
			fflush(stdout);
			int x;
			scanf("%d", &x);
			if (x == 1) {
				f[F(i)] = F(j);
			}
		}
	}
	printf("A\n");
	return 0;
}