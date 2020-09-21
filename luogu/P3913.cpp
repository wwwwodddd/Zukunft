#include <bits/stdc++.h>
using namespace std;
long long n;
int m;
int x[1000020], xc;
int y[1000020], yc;
int main() {
	scanf("%d%d", &n, &m);
	for (int i = 0; i < m; i++) {
		scanf("%d%d", &x[i], &y[i]);
	}
	sort(x, x + m);
	sort(y, y + m);
	xc = unique(x, x + m) - x;
	yc = unique(y, y + m) - y;
	printf("%lld\n", n * n - (n - xc) * (n - yc));
	return 0;
}