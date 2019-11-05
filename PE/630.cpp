#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll s[5020];
ll t[5020];
ll gcd(ll x, ll y) {
	return y ? gcd(y, x % y) : x;
}
ll solve(vector<pair<ll, ll> > p) {
	map<pair<ll, ll>, set<pair<ll, ll> > > g;
	for (int i = 0; i < p.size(); i++) {
		for (int j = 0; j < i; j++) {
			pair<ll, ll> k = make_pair(p[i].first - p[j].first, p[i].second - p[j].second);
			ll c = p[i].first * p[j].second - p[j].first * p[i].second;
			ll d = abs(gcd(k.first, k.second));
			k.first /= d;
			k.second /= d;
			if (k.first < 0 || k.first == 0 && k.second < 0) {
				k.first = -k.first;
				k.second = -k.second;
				c = -c;
			}
			ll t = abs(gcd(c, d));
			c /= t;
			d /= t;
			g[k].insert(make_pair(c, d));
//			if (k.first == 1 && k.second == -1 && c == 46 && d == 1 || i == 73 && j == 53) {
//				cerr << k.first << ' ' << k.second << ' ' << c << ' ' << d << endl;
//				cerr << i << ' ' << j << endl;
//			}
		}
	}
	ll ans = 0;
	ll cnt = 0;
	for (auto i: g) {
		cnt += i.second.size();
		ans += i.second.size() * (i.second.size() - 1);
	}
	cerr << cnt << ' ' << ans << endl;
	ans = cnt * (cnt - 1) - ans;
	return ans;
}
int main() {
	s[0] = 290797;
	for (int i = 1; i < 5010; i++) {
		s[i] = s[i - 1] * s[i - 1] % 50515093;
		t[i] = s[i] % 2000 - 1000;
	}
	vector<pair<ll, ll> > p;
	for (int i = 1; i <= 2500; i++) {
		p.push_back(make_pair(t[2 * i - 1], t[2 * i]));
	}
	printf("%lld\n", solve(p));

}