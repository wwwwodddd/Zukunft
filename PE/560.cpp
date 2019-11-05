#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int v[10000020];
int p[10000020], pc;
ll mod = 1000000007;
const int B = 20;
ll a[1 << B];
ll b[1 << B];
void fwt(ll a[]) {
	for (int j = 0; j < B; j++) {
		for (int i = 0; i < 1 << B; i++) {
			if (i >> j & 1) {
				ll x = a[i ^ (1 << j)];
				ll y = a[i];
				a[i ^ (1 << j)] = (x + y) % mod;
				a[i] = (x - y + mod) % mod;
			}
		}
	}
}
void mul(ll a[], ll b[]) {
	for (int i = 0; i < 1 << B; i++) {
		a[i] = (a[i] * b[i]) % mod;
	}
}
ll pw(ll x, ll y) {
	ll re = 1;
	for (; y > 0; y >>= 1) {
		if (y & 1) {
			re = re * x % mod;
		}
		x = x * x % mod;
	}
	return re;
}
int main() {
	int m = 10000000;
	int n = 10000000;
	for (int i = 2; i < m; i++) {
		if (v[i]) {
			continue;
		}
		p[i] = ++pc;
		for (int j = i; j < m; j += i) {
			if (v[j] == 0) {
				v[j] = i;
			}
		}
	}
	p[0] = 1;
	p[2] = 0;
	for (int i = 1; i < m; i++) {
		b[p[v[i]]]++;
	}
	a[0] = 1;
	fwt(a);
	fwt(b);
	for (; n > 0; n >>= 1) {
		if (n & 1) {
			mul(a, b);
		}
		mul(b, b);
	}
	fwt(a);
	ll inv = pw(1 << B, mod - 2);
	for (int i = 0; i < 1 << B; i++) {
		a[i] = a[i] * inv % mod;
	}
	cout << a[0] << endl;
}