#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll F(ll n, int x) { // < n  contains how many x
	n++;
	ll t = 1, z = 0;
	while (t < n) {
		z += n / 10 / t * t;
		if (n / t % 10 > x) {
			z += t;
		} else if (n / t % 10 == x) {
			z += n % t;
		}
		t *= 10;
	}
	n--;
	return z - n;
}
ll FF(ll n, int x) {
	ll z = 0;
	for (int i = 1; i < n; i++) {
		int j = i;
		while (j > 0) {
			if (j % 10 == x) {
				z++;
			}
			j /= 10;
		}
	}
	return z;
}
ll solve(int d) {
	ll z = 0;
	ll cur = 0;
	ll lim = 1e12;
	while (cur < lim) {
		ll delta = F(cur, d);
		if (delta == 0) {
//			cerr << cur << endl;
			z += cur;
		}
		delta = abs(delta);
		delta = delta / 11 + 1;
		cur += delta;
	}
	return z;
}
int main() {
	ll s = 0;
	for (int i = 1; i <= 9; i++) {
		s += solve(i);
	}
	cerr << s << endl;
	return 0;
}