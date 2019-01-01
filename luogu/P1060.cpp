#include <bits/stdc++.h>
using namespace std;
int n, m, x, y, f[100020];
int main() {
	scanf("%d%d", &m, &n);
	for (int i = 0; i < n; i++) {
		scanf("%d%d", &x, &y);
		y *= x;
		for (int j = m; j >= x; j--) {
			f[j] = max(f[j], f[j - x] + y);
		}
	}
	printf("%d\n", f[m]);
	return 0;
}