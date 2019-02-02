#include <bits/stdc++.h>
using namespace std;
int n, x, y;
int c[100020];
int main() {
	scanf("%d", &n);
	for (int i = 1; i < n; i++) {
		scanf("%d%d", &x, &y);
		c[x]++;
		c[y]++;
	}
	int cnt = 0;
	for (int i = 0; i < n; i++) {
		cnt = max(cnt, c[i] + 1);
	}
	printf("%d\n", cnt);
	return 0;
}