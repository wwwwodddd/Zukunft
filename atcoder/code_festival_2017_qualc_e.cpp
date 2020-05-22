#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
vector<pair<ll, ll> > p;
ll a, b, c, d, nx, ny, nz, px, py, pz, dx, dy, dz, mod = 1000000007;
bool cmp(const pair<ll, ll> &a, const pair<ll, ll> &b) {
	return a.first * b.second < a.second * b.first;
}
int main() {
	cin >> a >> b >> c >> d;
	for (int i = 0; i <= d; i++) {
		if (i < a) {
			p.push_back({i, a});
			p.push_back({a - i - 1, a});
		}
		if (i < b) {
			p.push_back({i, b});
			p.push_back({b - i - 1, b});
		}
		if (i < c) {
			p.push_back({i, c});
			p.push_back({c - i - 1, c});
		}
	}
	sort(p.begin(), p.end(), cmp);
	ll ans = (min(a - 1, d) + 1) * (min(b - 1, d) + 1) * (min(c - 1, d) + 1);
	for (int i = 1; i < p.size(); i++) {
		nx = a * p[i].first / p[i].second;
		ny = b * p[i].first / p[i].second;
		nz = c * p[i].first / p[i].second;
		dx = min(a - 1, px + d) - max(0LL, px - d) + 1;
		dy = min(b - 1, py + d) - max(0LL, py - d) + 1;
		dz = min(c - 1, pz + d) - max(0LL, pz - d) + 1;
		if (nx + d < a) {
			ans += (nx - px) * dy % mod * dz % mod;
		}
		if (ny + d < b) {
			ans += (ny - py) * dz % mod * dx % mod;
		}
		if (nz + d < c) {
			ans += (nz - pz) * dx % mod * dy % mod;
		}
		px = nx;
		py = ny;
		pz = nz;
	}
	cout << ans % mod << endl;
	return 0;
}