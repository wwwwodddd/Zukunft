#include <bits/stdc++.h>
using namespace std;
int n, m, p, x, y;
int a[100020];
char s[100020][13];
int main() {
	scanf("%d%d", &n, &m);
	for (int i = 0; i < n; i++) {
		scanf("%d%s", &a[i], &s[i]);
	}
	for (int i = 0; i < m; i++) {
		scanf("%d%d", &x, &y);
		x ^= a[p];
		if (x) {
			p = (p + y) % n;
		} else {
			p = (p + n - y) % n;
		}
	}
	printf("%s\n", s[p]);
	return 0;
}