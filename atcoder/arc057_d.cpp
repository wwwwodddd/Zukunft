#include <bits/stdc++.h>
using namespace std;
int n, a[33], p = 1000000007;
map<vector<int>, int> g[33];
int main() {
	scanf("%d", &n);
	for (int i = 1; i < n; i++) {
		scanf("%d", &a[i]);
	}
	a[n] = n * (n - 1) / 2;
	g[n][vector<int>(n, 1)] = 1;
	for (int t = n; t >= 1; t--) {
		for (pair<vector<int>, int> uu: g[t]) {
			vector<int> u = uu.first;
			int b = 0;
			for (int i: u) {
				b += i * (i - 1) / 2;
			}
			long long d = g[t][u];
			for (int k = a[n - t]; k < a[n - t + 1] - 1; k++) {
				d = d * (b - k) % p;
			}
			if (t == 1) {
				printf("%lld\n", d);
				return 0;
			}
			for (int i = 0; i < u.size(); i++) {
				for (int j = 0; j < i; j++) {
					vector<int> v;
					for (int k = 0; k < u.size(); k++) {
						if (k != i && k != j) {
							v.push_back(u[k]);
						}
					}
					v.push_back(u[i] + u[j]);
					sort(v.begin(), v.end());
					g[v.size()][v] = (g[v.size()][v] + d * u[i] * u[j]) % p;
				}
			}
		}
	}
}