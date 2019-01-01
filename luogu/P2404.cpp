#include <bits/stdc++.h>
using namespace std;
int a[20];
void dfs(int x, int y, int z) {
	if (x == 0) {
		if (y == 1) {
			return;
		}
		printf("%d", a[0]);
		for (int i = 1; i < y; i++) {
			printf("+%d", a[i]);
		}
		printf("\n");
	} else {
		for (a[y] = z; a[y] <= x; a[y]++) {
			dfs(x - a[y], y + 1, a[y]);
		}
	}
}
int main() {
	int n;
	cin >> n;
	dfs(n, 0, 1);
	return 0;
}