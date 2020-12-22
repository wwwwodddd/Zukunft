#include <bits/stdc++.h>
using namespace std;
int n, m, l, x, y;
int fac[12];
int v[12] = {};
void decode(int x) {
	for (int i = 0; i < n; i++) {
		int cnt = x / fac[n - 1 - i] % (n - i);
		for (int j = 1; j <= n; j++) {
			if (v[j] == 0) {
				if (cnt == 0) {
					v[j] = i + 1;
					break;
				} else {
					cnt--;
				}
			}
		}
	}
}
int main() {
	scanf("%d%d%d", &n, &m, &l);
	fac[0] = 1;
	for (int i = 1; i <= n; i++) {
		fac[i] = fac[i - 1] * i;
	}
	decode(l - 1);
	for (int i = 0; i < m; i++) {
		scanf("%d%d", &x, &y);
		printf("%d", v[x] > v[y]);
	}
	printf("\n");
	return 0;
}