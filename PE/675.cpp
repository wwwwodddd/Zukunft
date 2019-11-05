#include <bits/stdc++.h>
using namespace std;
int v[10000020];
int c[10000020];
typedef long long ll;
ll mod = 1000000087;
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
	int n = 10000000;
	for (int i = 2; i <= n; i++) {
		if (v[i]) {
			continue;
		}
		for (int j = i; j <= n; j += i) {
			v[j] = i;
		}
	}
	long long ans = 1;
	long long sum = 0;
	for (int i = 2; i <= n; i++) {
		int t = i;
		while (t > 1) {
			ans = ans * pw(c[v[t]] * 2 + 1, mod - 2) % mod;
			c[v[t]]++;
			ans = ans * (c[v[t]] * 2 + 1) % mod;
			t /= v[t];
		}
		sum = (sum + ans) % mod;
	}
	cout << sum << endl;
	return 0;
}