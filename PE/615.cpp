#include <bits/stdc++.h>
using namespace std;
vector<pair<int, int> >a;
const int n = 1000000, f = min(n, 35);
long long ff = 1LL << f;
int v[2 * n + 20];
int c[2 * n + 20];
int p[2 * n + 20], pc;

set<long long> q;
void dfs(long long x, int z) {
	for (; z < pc; z++) {
		if (*--q.end() / p[z] >= x / 2) {
			q.insert(x / 2 * p[z]);
			if (q.size() > n) {
				if (*--q.end() == x / 2 * p[z]) {
					q.erase(--q.end());
					return;
				} else {
					q.erase(--q.end());
				}
			}
		} else {
			return;
		}
		dfs(x / 2 * p[z], z);
	}
	return;
}
int main() {
	for (int i = 2; i <= n; i++) {
		if (v[i] > 0) {
			continue;
		}
		p[pc++] = i;
		for (int j = i; j <= n; j += i) {
			v[j] = i;
		}
	}
	for (int i = 2; i <= n; i++) {
		c[i] = c[i / v[i]] + 1;
	}
	for (int i = 1; i <= n; i++) {
		q.insert(ff * i);
	}
	p[0] = 3;
	p[1] = 4;
	dfs(ff, 0);
	cerr << q.size() << endl;
	long long ans = *--q.end();
	for (int i = f; i < n; i++) {
		ans = ans * 2 % 123454321;
	}
	cerr << ans << endl;
	return 0;
}