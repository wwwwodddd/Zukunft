#include <bits/stdc++.h>
using namespace std;
int a[20], v[20], n;
void dfs(int x) {
	if (x == n) {
		for (int i = 0; i < n; i++) {
			printf("%5d", a[i]);
		}
		printf("\n");
		return;
	}
	for (int j = 1; j <= n; j++) {
		if (v[j]) {
			continue;
		}
		v[j] = 1;
		a[x] = j;
		dfs(x + 1);
		v[j] = 0;
	}
}
int main() {
	scanf("%d", &n);
	dfs(0);
	return 0;
}