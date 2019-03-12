#include <bits/stdc++.h>
using namespace std;
const int mod = 1000000007;
vector<pair<int, int> > a[2520];
long long ans = 0;
long long cnt = 1;
long long sum;
int sz;
bool v[2520];
long long inv[2520];
long long f[2520];
long long g[2520];
int n, m, x, y;
int dfs(int x, int y) {
	v[x] = true;
	int re = 1;
	for (pair<int, int> i: a[x]) {
		if (i.first != y) {
			int tmp = dfs(i.first, x);
			re += tmp;
			sum += (long long)i.second * tmp * (sz - tmp);
		}
	}
	return re;
}
map<int, int> c;
map<int, int> gao(int x, int y) {
	v[x] = true;
	map<int, int> re;
	re[0] = 1;
	for (pair<int, int> i: a[x]) {
		if (i.first != y) {
			map<int, int> tmp = gao(i.first, x);
			for (pair<int, int> j: re) {
				for (pair<int, int> k: tmp) {
					c[j.first + i.second + k.first] += j.second * k.second * 2;
				}
			}
			for (pair<int, int> k: tmp) {
				re[i.second + k.first] += k.second;
			}
		}
	}
	return re;
}
int main() {
	cin >> n >> m >> x >> y;
	inv[1] = 1;
	for (int i = 2; i <= n; i++) {
		inv[i] = inv[mod % i] * (mod - mod / i) % mod;
	}
	if ((n - m) * x <= y) {
		f[(n - m) * x] = 1;
	}

	for (int i = 0; i < m; i++) {
		int x, y, z;
		cin >> x >> y >> z;
		a[x].push_back(make_pair(y, z));
		a[y].push_back(make_pair(x, z));
	}

	memset(v, 0, sizeof v);
	for (int i = 1; i <= n; i++) {
		if (!v[i]) {
			sz = dfs(i, 0);
			cnt = cnt * sz % mod * (sz - 1) % mod;
		}
	}

	memset(v, 0, sizeof v);
	for (int i = 1; i <= n; i++) {
		if (!v[i]) {
			sz = dfs(i, 0);
			sum = 0;
			dfs(i, 0);
			ans = (ans + cnt * inv[sz] % mod * inv[sz-1] % mod * sum % mod) % mod;
		}
	}

	ans *= 2;

	ans = (ans + cnt * (n - m) * x) % mod;

	memset(v, 0, sizeof v);
	for (int i = 1; i <= n; i++) {
		if (!v[i]) {
			c.clear();
			gao(i, 0);
			memset(g, 0, sizeof g);
			for (pair<int, int> i: c) {
				for (int j = i.first; j <= y; j++) {
					g[j] = (g[j] + f[j - i.first] * i.second) % mod;
				}
			}
			swap(f, g);
		}
	}

	for (int i = 0; i < y; i++) {
		ans = (ans - (long long)i * f[i] % mod + mod) % mod;
	}

	for (int i = 1; i < n - m; i++) {
		ans = ans * i % mod;
	}

	if (ans & 1) {
		ans += mod;
	}
	ans /= 2;
	cout << ans << endl;
	return 0;
}