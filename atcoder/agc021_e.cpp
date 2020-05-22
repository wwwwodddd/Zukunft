#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll n, k, z, c = 1, p = 998244353;
ll pw(ll x, ll y) {
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
	cin >> k >> n;
	z = pw(2, n - 1);
	for (int i = 0; i < k; i++) {
		if ((k - i) % 2 == 0) {
			z = (z + p - c) % p;
		}
		c = c * (n - i) % p * pw(i + 1, p - 2) % p;
	}
	cout << z << endl;
	return 0;
}