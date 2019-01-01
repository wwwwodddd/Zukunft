#include <bits/stdc++.h>
using namespace std;
int n, m, x, y;
long long f[100020];
int main() {
	scanf("%d%d", &n, &m);
	f[0] = 1;
	for (int i = 0; i < n; i++) {
		scanf("%d", &x);
		for (int j = x; j <= m; j++) {
			f[j] += f[j - x];
		}
	}
	printf("%lld\n", f[m]);
	return 0;
}