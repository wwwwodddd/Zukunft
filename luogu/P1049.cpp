#include <bits/stdc++.h>
using namespace std;
int n, m, x, f[100020];
int main() {
	scanf("%d%d", &m, &n);
	for (int i = 0; i < n; i++) {
		scanf("%d", &x);
		for (int j = m; j >= x; j--) {
			f[j] = max(f[j], f[j - x] + x);
		}
	}
	printf("%d\n", m - f[m]);
	return 0;
}