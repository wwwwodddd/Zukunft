#include <bits/stdc++.h>
using namespace std;
int n, c, z, f[100020];
pair<int, int> x[100020], y[100020];
pair<int, pair<int, int> > a[200020];
int F(int x) {
	return f[x] != x ? f[x] = F(f[x]) : x;
}
int main() {
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		scanf("%d%d", &x[i].first, &y[i].first);
		x[i].second = y[i].second = i;
		f[i] = i;
	}
	sort(x, x + n);
	sort(y, y + n);
	for (int i = 1; i < n; i++) {
		a[c++] = {x[i].first - x[i - 1].first, {x[i].second, x[i - 1].second}};
		a[c++] = {y[i].first - y[i - 1].first, {y[i].second, y[i - 1].second}};
	}
	sort(a, a + c);
	for (int i = 0; i < c; i++) {
		if (F(a[i].second.first) != F(a[i].second.second)) {
			f[F(a[i].second.first)] = F(a[i].second.second);
			z += a[i].first;
		}
	}
	printf("%d\n", z);
	return 0;
}