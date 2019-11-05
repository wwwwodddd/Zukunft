#include <bits/stdc++.h>
using namespace std;
int v[300020];
int p[300020], pc;
typedef long long ll;
ll b[300020];
ll ib[300020];
ll d[300020];
ll pw(ll x, ll y, ll p) {
	ll re = 1;
	for (; y > 0; y >>= 1) {
		if (y & 1) {
			re = re * x % p;
		}
		x = x * x % p;
	}
	return re;
}
int main() {
	int n = 300000;
	for (int i = 2; i <= n; i++) {
		if (v[i]) {
			continue;
		}
		p[++pc] = i;
		for (int j = i; j <= n; j += i) {
			v[j] = i;
		}
	}
	ll ans = 0;
	for (int i = 1; i <= pc; i++) {
		if (i % 1000 == 0) {
			cerr << i << endl;
		}
		ll cur = 0;
		ll tmp = 1;
		bool flag = false;
		for (int j = 1; j < i; j++) {
			cur = (cur + (j - d[j] + p[j]) * ib[j] % p[j] * tmp) % p[i];
			tmp = tmp * p[j] % p[i];
			if (cur == 0) {
				flag = true;
			}
		}
		if (flag) {
			ans += p[i];
		}
		b[i] = tmp;
		ib[i] = pw(b[i], p[i] - 2, p[i]);
		d[i] = cur;
	}
	cerr << ans << endl;
	return 0;
}