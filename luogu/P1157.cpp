#include <bits/stdc++.h>
using namespace std;
int n, r, a[30];
void dfs(int x, int y) {
	if (x == r) {
		for (int i = 0; i < r; i++) {
			printf("%3d", a[i]);
		}
		printf("\n");
	} else {
		for (a[x] = y; a[x] <= n; a[x]++) {
			dfs(x + 1, a[x] + 1);
		}
	}
}
int main() {
	scanf("%d%d", &n, &r);
	dfs(0, 1);
	return 0;
}