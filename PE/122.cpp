#include <iostream>
#include <cstdio>
using namespace std;
int ans[220];
int a[20];
int n = 200;
void dfs(int x) {
	if (a[x - 1] <= n) {
		ans[a[x - 1]] = min(ans[a[x - 1]], x - 1);
	}
	if (x == 12) {
		return;
	}
	int b[400] = {}, c = 0;
	for (int i = 0; i < x; i++) {
		for (int j = 0; j <= i; j++) {
			b[c++] = a[i] + a[j];
		}
	}
	sort(b, b + c);
	c = unique(b, b + c) - b;
	for (int i = 0; i < c; i++) {
		a[x] = b[i];
		if (a[x] <= a[x - 1]) {
			continue;
		}
		dfs(x + 1);
	}
}

int main() {
	memset(ans, 0x3f, sizeof ans);
	a[0] = 1;
	dfs(1);
	int sum = 0;
	for (int i = 1; i <= n; i++) {
		printf("%d %d\n", i, ans[i]);
		sum += ans[i];
	}
	printf("%d\n", sum);
	return 0;
}