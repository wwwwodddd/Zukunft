#include <bits/stdc++.h>
using namespace std;
const int n = 120000;
typedef long long ll;
map<pair<ll, ll>, ll> g;
vector<pair<ll, ll> > a[n + 10];
set<ll> z;
long long getsqrt(long long x) {
	return (long long)(sqrt(x) + 0.5);
}
int main() {
	for (ll i = 1; i <= n; i++) {
		for (ll j = i; j <= n; j++) {
			ll square = i * i + j * j + i * j;
			ll root = getsqrt(square);
			if (i + j > n) {
				break;
			}
			if (root * root == square) {
//				cerr << i << ' ' << j << endl;
				a[i].push_back(make_pair(j, root));
				g[make_pair(i, j)] = root;
			}
		}
	}
	for (int i = 1; i <= n; i++) {
		for (int jj = 0; jj < a[i].size(); jj++) {
			for (int kk = jj + 1; kk < a[i].size(); kk++) {
				ll cir = i + a[i][jj].first + a[i][kk].first;
				if (cir > n) {
					break;
				}
				pair<ll, ll> u(a[i][jj].first, a[i][kk].first);
				if (g.find(u) != g.end()) {
					z.insert(cir);
				}
			}
		}
	}
	ll ans = 0;
	for (ll i: z) {
		ans += i;
	}
	fprintf(stderr, "size %d\n", g.size());
	printf("ans: %lld\n", ans);
	return 0;
}