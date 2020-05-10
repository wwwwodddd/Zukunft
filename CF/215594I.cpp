#include <bits/stdc++.h>
using namespace std;
const int N = 1000000;
typedef long long ll;
typedef long double ld;
int v[N + 20];
int p[100020], pc;
long long a[520];
int b[520];
int g[520][520];
int d[520], m;
ll qmul(ll a, ll b, ll m) { a %= m; b %= m;
	ll r = a * b, s = ld(a) * b / m;
	return ((r - m * s) % m + m) % m;
}
ll qpow(ll x, ll y, ll p) {
	ll re = 1;
	for (; y > 0; y >>= 1) {
		if (y & 1) {
			re = qmul(re, x, p);
		}
		x = qmul(x, x, p);
	}
	return re;
}
bool miller_rabin(ll n, ll base) {
	ll n2 = n - 1, s = 0;
	while(n2 % 2 == 0) n2 /= 2, s ++;
	ll t = qpow(base, n2, n);
	if(t == 1 || t == n - 1) return true;
	for(s --; s >= 0; s --)
		if((t = qmul(t, t, n)) == n - 1) return true;
	return false;
}
bool is_prime(ll n) {
	static ll base[] = {2,3,5,7,11,13,17,19,23,29,31,37};
/*static ll lim[]={4,2047,1373653,25326001,3215031751LL,21\
52302898747LL,3474749660383LL,341550071728321LL,0,0,0,0};*/
	if(n < 2) return false;
	for(int i = 0; i < 12 && base[i] < n; i ++) {
		// if(n < lim[i]) return true;
		if(!miller_rabin(n, base[i])) return false;
	}
	return true;
}
int mu(long long x) {
	int re = 1;
	for (int i = 0; i < pc; i++) {
		if (x % p[i] == 0) {
			x /= p[i];
			re = -re;
			if (x % p[i] == 0) {
				return 0;
			}
		}
		if (x == 1) {
			break;
		}
		if (p[i] * p[i] > x) {
			break;
		}
	}
	if (x > 1) {
		long long rt = sqrt(x);
		if (rt * rt == x) {
			return 0;
		}
		if (is_prime(x)) {
			re = -re;
		}
	}
	return re;
}
long long gcd(long long x, long long y) {
	return y ? gcd(y, x % y) : x;
}
int solve() {
	int z = 1;
	for (int i = 0; i < m; i++) {
		for (int j = 0; j < i; j++) {
			if (g[d[i]][d[j]]) {
				return 0;
			}
		}
		z *= b[d[i]];
	}
	return z;
}
int main() {
	for (int i = 2; i <= N; i++) {
		if (v[i] > 0) {
			continue;
		}
		p[pc++] = i;
		for (int j = i; j <= N; j += i) {
			v[j] = i;
		}
	}
	int n, q;
	scanf("%d%d", &n, &q);
	for (int i = 1; i <= n; i++) {
		scanf("%lld", &a[i]);
		b[i] = mu(a[i]);
	}
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			g[i][j] = (gcd(a[i], a[j]) > 1);
		}
	}
	for (int i = 0; i < q; i++) {
		scanf("%d", &m);
		for (int j = 0; j < m; j++) {
			scanf("%d", &d[j]);
		}
		printf("%d\n", solve());
	}
	return 0;
}