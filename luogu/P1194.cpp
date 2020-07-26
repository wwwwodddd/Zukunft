#include <bits/stdc++.h>
using namespace std;
int f[520];
int n, m, x, z;
pair<int, pair<int, int> > a[250020];
int F(int x) {
	return f[x] != x ? f[x] = F(f[x]) : x;
}
int main() {
	scanf("%d%d", &x, &n);
	for (int i = 1; i <= n; i++) {
		f[i] = i;
		a[m++] = make_pair(x, make_pair(0, i));
	}
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			scanf("%d", &x);
			if (i < j && x != 0) {
				a[m++] = make_pair(x, make_pair(i, j));
			}
		}
	}
	sort(a, a + m);
	for (int i = 0; i < m; i++) {
		int x = F(a[i].second.first);
		int y = F(a[i].second.second);
		if (x != y) {
			f[x] = y;
			z += a[i].first;
		}
	}
	printf("%d\n", z);
	return 0;
}