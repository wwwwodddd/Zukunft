#include <bits/stdc++.h>
using namespace std;
int n, m, q, x[300020], y[300020], N;
long long z[300020];
int c[600020];
vector<pair<int, int> > a[300020];
vector<long long> b[300020], l;
void R(int x, int y) {
	for (; x <= N; x += x & -x) {
		c[x] += y;
	}
}
int A(int x) {
	int re = 0;
	for (int i = 1 << 20; i > 0; i /= 2) {
		if (re + i <= N && c[re + i] < x) {
			x -= c[re += i];
		}
	}
	return re + 1;
}
int main() {
	scanf("%d%d%d", &n, &m, &q);
	N = max(n, m) + q;
	for (int i = 0; i < q; i++) {
		scanf("%d%d", &x[i], &y[i]);
		if (y[i] < m) {
			a[x[i]].push_back(make_pair(y[i], i));
		}
	}
	for (int i = 1; i <= N; i++) {
		c[i]++;
		if (i + (i & -i) <= N) {
			c[i + (i & - i)] += c[i];
		}
	}
	for (int i = 1; i <= n; i++) {
		for (int j = 0; j < a[i].size(); j++) {
			int u = A(a[i][j].first);
			z[a[i][j].second] = u;
			R(u, -1);
		}
		for (int j = 0; j < a[i].size(); j++) {
			R(z[a[i][j].second], 1);
		}
	}
	for (int i = 0; i <= n; i++) {
		l.push_back((long long)i * m);
	}
	for (int i = 0; i < q; i++) {
		int u = A(x[i]);
		R(u, -1);
		if (y[i] < m) {
			b[x[i]].push_back(l[u]);
			if (z[i] < m) {
				z[i] = (long long)(x[i] - 1) * m + z[i];
			} else {
				z[i] = b[x[i]][z[i] - m];
			}
		} else {
			z[i] = l[u];
		}
		l.push_back(z[i]);
	}
	for (int i = 0; i < q; i++) {
		printf("%lld\n", z[i]);
	}
	return 0;
}