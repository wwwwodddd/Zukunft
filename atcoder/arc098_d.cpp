#include <bits/stdc++.h>
using namespace std;
int n, m, x, y;
vector<int> a[100020];
long long A[100020];
long long B[100020];
long long g[100020];
int f[100020];
int r[100020];
int v[100020];
int F(int x) {
	return f[x] != x ? f[x] = F(f[x]) : x;
}
int cmp(int x, int y) {
	return A[x] < A[y];
}
int main() {
	scanf("%d%d", &n, &m);
	for (int i = 1; i <= n; i++) {
		scanf("%lld%lld", &A[i], &B[i]);
		A[i] = max(A[i] - B[i], 0LL);
		r[i] = i;
	}
	sort(r + 1, r + 1 + n, cmp);
	for (int i = 0; i < m; i++) {
		scanf("%d%d", &x, &y);
		a[x].push_back(y);
		a[y].push_back(x);
	}
	for (int i = 1; i <= n; i++) {
		v[r[i]] = 1;
		f[r[i]] = r[i];
		g[r[i]] = A[r[i]];
		for (int j: a[r[i]]) {
			j = F(j);
			if (v[j] && j != r[i]) {
				B[r[i]] += B[j];
				g[r[i]] = min(g[r[i]], max(g[j], A[r[i]] - B[j]));
				f[j] = r[i];
			}
		}
	}
	printf("%lld\n", g[F(1)] + B[F(1)]);
	return 0;
}